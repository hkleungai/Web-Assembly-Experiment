#ifndef __USER_DEFINED__EXTERN_HEADER
#define __USER_DEFINED__EXTERN_HEADER

#define __VISIBLE__   __attribute__((visibility("default")))

#ifdef __cplusplus
  #define __EXTERN__ extern "C"
#else
  #define __EXTERN__
#endif

/* A "decorator" for exporting function to wasm */
#define EXTERN __EXTERN__ __VISIBLE__

#endif
