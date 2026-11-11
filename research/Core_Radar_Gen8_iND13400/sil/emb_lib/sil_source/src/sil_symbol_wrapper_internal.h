#ifndef SIL_SYMBOL_WRAPPER_INTERNAL_H
#define SIL_SYMBOL_WRAPPER_INTERNAL_H

#include <array>
#include <cstddef>

#include "sil_wrapper_common.h"

namespace sil_symbol_wrapper_internal
{
/* Generic fixed-depth delay line: Push_And_Pop() returns the sample fed in Depth cycles ago */
template <typename T, std::size_t Depth = 1U> class Delay_Line_T
{
   static_assert(Depth >= 1U, "Delay_Line_T requires Depth >= 1");

 public:
   T &Push_And_Pop(const T &new_sample)
   {
      output_        = buffer_[head_];
      buffer_[head_] = new_sample;
      head_          = (head_ + 1U) % Depth;
      return output_;
   }

 private:
   std::array<T, Depth> buffer_ = {};
   T output_                    = {};
   std::size_t head_            = 0U;
};

struct Radar_Symbol_Context_T
{
   Radar_Position self_radar_position              = UNKNOWN_POSITION;
   Radar_Position partner_radar_position           = UNKNOWN_POSITION;
   const Vehicle_Data_Input_T *vehicle_input       = nullptr;
   const MOUNTING_VALUES_XML_T *self_mounting      = nullptr;
   const Detection_Data_Input_T *self_detection    = nullptr;
   const MOUNTING_VALUES_XML_T *partner_mounting   = nullptr;
   const Detection_Data_Input_T *partner_detection = nullptr;
};

Radar_Symbol_Context_T resolve_radar_symbol_context(const SIL_RADAR_Input_Symbol_T *symbol_input,
                                                    Radar_Position self_radar_position);
} // namespace sil_symbol_wrapper_internal

#endif // SIL_SYMBOL_WRAPPER_INTERNAL_H
