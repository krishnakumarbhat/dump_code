#include <cassert>
#include <iostream>

using functionptr_T = void (*)();
#ifdef __unix__
   #include <dlfcn.h>
using dll_handle_T = void *;
#elif defined(_WIN32) || defined(__WIN32__)
   #include <windows.h>
using dll_handle_T = HMODULE;
#endif

static bool init_done = false;

dll_handle_T dll_open(const char *path)
{
#ifdef __unix__
   dll_handle_T handle = dlopen(path, RTLD_LAZY);
   if (!handle)
   {
      std::cerr << "dlopen failed: " << dlerror() << std::endl;
      return nullptr;
   }
   return handle;
#elif defined(_WIN32) || defined(__WIN32__)
   dll_handle_T handle = LoadLibrary(TEXT(path));
   if (!handle)
   {
      std::cerr << "LoadLibrary failed: " << GetLastError() << std::endl;
      return nullptr;
   }
   return handle;
#endif
}

functionptr_T get_function_ptr(dll_handle_T handle, const char *name)
{
#ifdef __unix__
   auto fun = (functionptr_T)dlsym(handle, name);
   char *error;
   if ((error = dlerror()))
   {
      std::cerr << error << std::endl;
      return nullptr;
   }
   return fun;
#elif defined(_WIN32) || defined(__WIN32__)
   auto fun = (functionptr_T)GetProcAddress(handle, name);
   if (!fun)
   {
      std::cerr << "GetProcAddress failed: " << GetLastError() << std::endl;
      return nullptr;
   }
   return fun;
#endif
}

void dll_close(dll_handle_T handle)
{
#ifdef __unix__
   dlclose(handle);
#elif defined(_WIN32) || defined(__WIN32__)
   FreeLibrary(handle);
#endif
}

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      std::cerr << "Usage: " << argv[0] << " <dll_path>" << std::endl;
      return 1;
   }
   const auto handle = dll_open(argv[1]);
   auto sil_init     = get_function_ptr(handle, "sil_init");
   assert(sil_init);
   if (init_done == false)
   {
      sil_init();
      init_done = true;
   }

   auto sil_run = get_function_ptr(handle, "sil_run");
   assert(sil_run);
   if (init_done == true)
   {
      sil_run();
   }

   dll_close(handle);
   return 0;
}
