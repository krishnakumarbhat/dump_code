#include "boost/pfr.hpp"
#include "pugixml.hpp"
#include <cstdint>
#include <cstring>
#include <fstream>
#include <optional>
#include <string>
#include <type_traits>
using pugi::xml_node;

// When int8_t or uint8_t are written to an std::ostream,
// they are written as raw ASCII bytes instead of decimal
// integers. To fix this, we widen them to int16_t
template <typename T> constexpr auto widen_for_stream(T val)
{
   // Don't collapse this condition to sizeof(T) == 1, because booleans
   // are 1 byte too
   if constexpr (std::is_same_v<uint8_t, T> or std::is_same_v<int8_t, T>)
   {
      return static_cast<int16_t>(val);
   }
   else
   {
      return val;
   }
}

/// FUNCTIONS FOR SINGLETON OBJECTS (LIKE CALIBRATIONS)
template <typename T>
static inline __attribute__((always_inline)) void print_singleton_array_csv(std::ofstream &stream, std::string_view field_name,
                                                                            const T &arr)
{
   constexpr auto rank = std::rank_v<T>;
   static_assert(rank <= 2);
   if constexpr (rank == 1)
   {
      for (std::size_t i = 0; i < std::extent_v<T, 0>; i++)
      {
         stream << field_name << "[" << i << "]," << widen_for_stream(arr[i]) << '\n';
      }
   }
   else
   {
      for (std::size_t i = 0; i < std::extent_v<T, 0>; i++)
      {
         for (std::size_t j = 0; j < std::extent_v<T, 1>; j++)
         {
            stream << field_name << "[" << i << "][" << j << "]," << widen_for_stream(arr[i][j]) << '\n';
         }
      }
   }
}

template <typename T> static inline __attribute__((always_inline)) void print_singleton_csv(std::ofstream &stream, const T &obj)
{
   static_assert(std::is_class_v<T>);
   boost::pfr::for_each_field_with_name(obj,
                                        [&stream]<typename field_type>(std::string_view field_name, const field_type &field)
                                        {
                                           if constexpr (std::is_class_v<field_type>)
                                           {
                                              print_singleton_csv(stream, field);
                                           }
                                           else if constexpr (std::is_array_v<field_type>)
                                           {
                                              print_singleton_array_csv(stream, field_name, field);
                                           }
                                           else
                                           {
                                              if (field_name.find("unused") == std::string_view::npos)
                                              {
                                                 stream << field_name << "," << widen_for_stream(field) << '\n';
                                              }
                                           }
                                        });
}

template <typename T>
static inline __attribute__((always_inline)) void save_singleton_array_xml(xml_node &node, std::string_view field_name,
                                                                           const T &arr)
{
   constexpr auto rank = std::rank_v<T>;
   static_assert(rank <= 2);
   if constexpr (rank == 1)
   {
      for (std::size_t i = 0; i < std::extent_v<T, 0>; i++)
      {
         std::string tag_name{field_name};
         tag_name += "[" + std::to_string(i) + "]";
         node.append_child(tag_name.c_str()).text().set(arr[i]);
      }
   }
   else if (rank == 2)
   {
      for (std::size_t i = 0; i < std::extent_v<T, 0>; i++)
      {
         for (std::size_t j = 0; j < std::extent_v<T, 1>; j++)
         {
            std::string tag_name{field_name};
            tag_name += "[" + std::to_string(i) + "][" + std::to_string(j) + "]";
            node.append_child(tag_name.c_str()).text().set(arr[i][j]);
         }
      }
   }
}

template <typename T> static inline __attribute__((always_inline)) void save_singleton_xml(xml_node &node, const T &obj)
{
   static_assert(std::is_class_v<T>);
   boost::pfr::for_each_field_with_name(obj,
                                        [&node]<typename field_type>(std::string_view field_name, const field_type &field)
                                        {
                                           if constexpr (std::is_class_v<field_type>)
                                           {
                                              xml_node child = node.append_child(field_name.data());
                                              save_singleton_xml(child, field);
                                           }
                                           else if constexpr (std::is_array_v<field_type>)
                                           {
                                              save_singleton_array_xml(node, field_name, field);
                                           }
                                           else
                                           {
                                              if (field_name.find("unused") == std::string_view::npos)
                                              {
                                                 xml_node child = node.append_child(field_name.data());
                                                 child.text().set(field);
                                              }
                                           }
                                        });
}

/// FUNCTIONS FOR NON-SINGLETON OBJECTS (LIKE STREAMS)
template <typename T>
static inline __attribute__((always_inline)) void print_csv_header(std::ofstream &stream, const T &obj, bool recursive = false,
                                                                   std::optional<std::string_view> prefix = std::nullopt)
{
   static_assert(std::is_class_v<T>, "T is not a struct");
   boost::pfr::for_each_field_with_name(
      obj,
      [&stream, &prefix]<typename field_type>(std::string_view field_name, const field_type &field)
      {
         if (prefix)
         {
            stream << *prefix;
         }
         if constexpr (std::is_class_v<field_type>)
         {
            print_csv_header(stream, field, true);
         }
         else if constexpr (std::is_array_v<field_type>)
         {
            using element_type  = std::remove_all_extents_t<field_type>;
            constexpr auto rank = std::rank_v<field_type>;
            static_assert(rank <= 2);
            if constexpr (std::is_fundamental_v<element_type>)
            {
               if constexpr (rank == 1)
               {
                  for (std::size_t i = 0; i < std::extent_v<field_type, 0>; i++)
                  {
                     stream << field_name << '_' << i << ",";
                  }
               }
               else
               {
                  for (std::size_t i = 0; i < std::extent_v<T, 0>; i++)
                  {
                     for (std::size_t j = 0; j < std::extent_v<field_type, 1>; j++)
                     {
                        stream << field_name << '_' << i << "_" << j << ",";
                     }
                  }
               }
            }
            else
            {
               if constexpr (rank == 1)
               {
                  for (std::size_t i = 0; i < std::extent_v<field_type, 0>; i++)
                  {
                     static std::array<char, 50> arr_prefix;
                     memset(arr_prefix.data(), 0, arr_prefix.size());
                     sprintf(arr_prefix.data(), "%s_%llu.", field_name.data(), i);
                     print_csv_header(stream, field[i], true, {{arr_prefix.cbegin(), arr_prefix.cend()}});
                  }
               }
               else
               {
                  for (std::size_t i = 0; i < std::extent_v<field_type, 0>; i++)
                  {
                     for (std::size_t j = 0; j < std::extent_v<field_type, 1>; j++)
                     {
                        static std::array<char, 50> arr_prefix;
                        memset(arr_prefix.data(), 0, arr_prefix.size());
                        sprintf(arr_prefix.data(), "%s_%llu_%llu.", field_name.data(), i, i);
                        print_csv_header(stream, field, true, {{arr_prefix.cbegin(), arr_prefix.cend()}});
                     }
                  }
               }
            }
         }
         else
         {
            static_assert(std::is_fundamental_v<field_type>, "field_type is not a class, array, or fundamental type");
            stream << field_name << ',';
         }
      });
   if (!recursive)
   {
      // replace last comma with newline
      stream.seekp(-1, std::ios_base::cur);
      stream << '\n';
   }
}

template <typename T>
static inline __attribute__((always_inline)) void print_csv_data(std::ofstream &stream, const T &obj, bool recursive = false)
{
   static_assert(std::is_class_v<T>, "T is not a struct");
   boost::pfr::for_each_field(obj,
                              [&stream]<typename field_type>(const field_type &field)
                              {
                                 if constexpr (std::is_class_v<field_type>)
                                 {
                                    print_csv_data(stream, field, true);
                                 }
                                 else if constexpr (std::is_array_v<field_type>)
                                 {
                                    using element_type  = std::remove_all_extents_t<field_type>;
                                    constexpr auto rank = std::rank_v<field_type>;
                                    static_assert(rank <= 2);
                                    if constexpr (std::is_fundamental_v<element_type>)
                                    {
                                       if constexpr (rank == 1)
                                       {
                                          for (std::size_t i = 0; i < std::extent_v<field_type, 0>; i++)
                                          {
                                             stream << widen_for_stream(field[i]) << ',';
                                          }
                                       }
                                       else
                                       {
                                          for (std::size_t i = 0; i < std::extent_v<T, 0>; i++)
                                          {
                                             for (std::size_t j = 0; j < std::extent_v<field_type, 1>; j++)
                                             {
                                                stream << widen_for_stream(field[i][j]) << ',';
                                             }
                                          }
                                       }
                                    }
                                    else
                                    {
                                       if constexpr (rank == 1)
                                       {
                                          for (std::size_t i = 0; i < std::extent_v<field_type, 0>; i++)
                                          {
                                             print_csv_data(stream, field[i], true);
                                          }
                                       }
                                       else
                                       {
                                          for (std::size_t i = 0; i < std::extent_v<field_type, 0>; i++)
                                          {
                                             for (std::size_t j = 0; j < std::extent_v<field_type, 1>; j++)
                                             {
                                                print_csv_data(stream, field[i][j], true);
                                             }
                                          }
                                       }
                                    }
                                 }
                                 else
                                 {
                                    static_assert(std::is_fundamental_v<field_type>,
                                                  "field_type is not a class, array, or fundamental type");
                                    stream << widen_for_stream(field) << ',';
                                 }
                              });
   if (!recursive)
   {
      // replace last comma with newline
      stream.seekp(-1, std::ios_base::cur);
      stream << '\n';
   }
}
