#pragma once

#ifdef RIB_PLATFORM_WINDOWS
  #error Ribbon only supports Linux!
  #ifdef RIB_BUILD_DLL
    #define RIB_API __declspec(dllexport)
  #else
    #define RIB_API __declspec(dllimport)
  #endif
#else
  #ifdef RIB_PLATFORM_LINUX
    #ifdef RIB_BUILD_DLL
      #define RIB_API __attribute__ ((visibility ("default")))
    #else
      #define RIB_API __attribute__ ((visibility ("default")))
    #endif
    #define RIB_INTERNAL __attribute__ ((visibility ("hidden")))
  #else
    #error Not defined platfom!
  #endif
#endif
