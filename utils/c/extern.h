#ifndef __USER_DEFINED__EXTERN_HEADER
#define __USER_DEFINED__EXTERN_HEADER

#define __VISIBLE__   __attribute__((visibility("default")))
#define __INVISIBLE__ __attribute__((visibility("hidden")))

#ifdef __cplusplus
  #define __EXTERN__ extern "C"
#else
  #define __EXTERN__
#endif

/* A "decorator" for exporting function to wasm */
#define EXTERN __EXTERN__ __VISIBLE__

/**
 * [RISKY]
 * Unexport "_start" symbol from WASI SDK
 * FIXME: Find a way to somehow hack the below warning.
 *        wasm-ld: warning: function signature mismatch: _start
 */
__EXTERN__ __INVISIBLE__ void _start(int) {};

#endif
