#pragma once

#ifdef RIB_PLATFORM_WINDOWS
  #error Ribbon only supports Linux!
  #ifdef RIB_BUILD_DLL
    #define RIB_API __declspec(dllexport)
  #else
    #define RIB_API __declspec(dllimport)
  #endif
  #define DEBUG_BREAK() __debugbreak()
#else
  #ifdef RIB_PLATFORM_LINUX
    #ifdef RIB_BUILD_DLL
      #define RIB_API __attribute__ ((visibility ("default")))
    #else
      #define RIB_API __attribute__ ((visibility ("default")))
    #endif
    #define RIB_INTERNAL __attribute__ ((visibility ("hidden")))
    #define DEBUG_BREAK() __builtin_trap()
  #else
    #error Not defined platfom!
  #endif
#endif

#ifdef RIB_BUILD_DEBUG
#define RIB_DEBUG(X) X
#else
#define RIB_DEBUG(X)
#endif

#ifdef RIB_ENABLE_ASSERTS
	#define RIB_ASSERT(X, MSG) { if(!(X)) { RIB_ERROR << "Assertion Failed: " <<  MSG; DEBUG_BREAK(); } }
	#define RIB_ENGINE_ASSERT(X, MSG) { if(!(X)) { RIB_ENGINE_ERROR << "Assertion Failed: " << MSG; DEBUG_BREAK(); } }
#else
	#define RIB_ASSERT(X, MSG)
	#define RIB_ENGINE_ASSERT(X, MSG)
#endif
