#pragma once
// FFX Debug/Logging System
// Enable logging by defining FFX_LOG_ENABLE (or via build system: -DFFX_LOG_ENABLE)
// All stubs log their calls to stderr for tracing.

#include <stdio.h>

#ifdef FFX_LOG_ENABLE
    #define FFX_LOG(...) \
        do { fprintf(stderr, "[FFX] " __VA_ARGS__); fprintf(stderr, "\n"); } while(0)

    #define FFX_LOG_STUB() \
        FFX_LOG("STUB: %s", __FUNCTION__)

    #define FFX_LOG_STUB_WITH(...) \
        do { fprintf(stderr, "[FFX] STUB: %s(", __FUNCTION__); \
             fprintf(stderr, __VA_ARGS__); \
             fprintf(stderr, ")\n"); } while(0)

    #define FFX_LOG_CALL(...) \
        do { fprintf(stderr, "[FFX] CALL: %s(", __FUNCTION__); \
             fprintf(stderr, __VA_ARGS__); \
             fprintf(stderr, ")\n"); } while(0)

    #define FFX_LOG_RETURN(val) \
        do { fprintf(stderr, "[FFX] %s => %d\n", __FUNCTION__, (int)(val)); } while(0)
#else
    #define FFX_LOG(...)
    #define FFX_LOG_STUB()
    #define FFX_LOG_STUB_WITH(...)
    #define FFX_LOG_CALL(...)
    #define FFX_LOG_RETURN(val)
#endif
