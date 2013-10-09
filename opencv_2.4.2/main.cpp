#include "opencv.h"
#include     <fstream> 
#include     <iomanip> 
#include     <iostream>
#include <cstdlib> 
#include     <cstdlib> 
using namespace std;
using namespace cv;
// compile g++ `pkg-config --cflags opencv` `pkg-config --libs opencv` -finstrument-functions  -g main.cpp -o main
// g++ `pkg-config --cflags opencv` `pkg-config --libs opencv` -I/usr/local/opencv/include -finstrument-functions  -g main.cpp -o main

#if 0
#define DUMP(func, call) printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)
#ifdef __cplusplus
extern  "C" {
     #endif 
    /* Static functions. */ 
    static FILE *openlogfile ( const  char * filename)
                __attribute__ ((no_instrument_function));
    static  void closelogfile ( void )
                __attribute__ ((no_instrument_function));

    /* Note that these are linked internally by the compiler.
     *  * Don't call them directly! */ 
    void __cyg_profile_func_enter ( void *this_fn, void * call_site)
                __attribute__ ((no_instrument_function));
    void __cyg_profile_func_exit ( void *this_fn, void * call_site)
                __attribute__ ((no_instrument_function));

#ifdef __cplusplus
};
#endif

void 
__cyg_profile_func_enter ( void *this_fn, void * call_site)
{
        DUMP(this_fn, call_site);
}

void 
__cyg_profile_func_exit ( void *this_fn, void * call_site)
{
       DUMP(this_fn, call_site);
}
#endif

int main(int argc, char* argv[])
{
    cout << "YAO[+]" << endl;
    IplImage *gimg = cvLoadImage("lena.bmp", 0);

    BwImage gimgA(gimg);

    gimgA[0][0] = 0;
    gimgA[0][1] = 0;
    gimgA[0][2] = 0;
    cout << "YAO[-]" << endl;

    cvNamedWindow("Bitmap",0);
    cvShowImage("Bitmap",gimg);
    cvWaitKey(0);
    cout << gimg->height << endl;
    cout << gimg->depth << endl;
	return 0;
}
