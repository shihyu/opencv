#include <stdio.h>

#ifdef __cplusplus
extern  "C" {
 #endif 
/* func_trace.c */
__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site) {
    printf("enter func => %p\n", this_fn);
}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site) {
    printf("exit func <= %p\n", this_fn);
}

#ifdef __cplusplus
};
#endif

