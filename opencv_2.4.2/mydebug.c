#include <stdio.h>

#define DUMP(func, call) printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)  

#ifdef __cplusplus
extern "C" {
#endif

void __attribute__((__no_instrument_function__))  
        __cyg_profile_func_enter(void *this_func, void *call_site);  

void __attribute__((__no_instrument_function__))  
        __cyg_profile_func_exit(void *this_func, void *call_site);  

#ifdef __cplusplus
};
#endif
