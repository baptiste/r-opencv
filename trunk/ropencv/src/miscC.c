#include "ropencv.h"
#include <stdio.h>
#include <R_ext/Memory.h>
#include <R_ext/Error.h>

int showImage(char ** file) {
  IplImage* img = cvLoadImage (file[0], 1);
  cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
  cvShowImage("Example1", img);
  cvWaitKey(0);
  cvReleaseImage( &img );
  cvDestroyWindow("Example1");
}

/* convolve function as example of C code*/
void convolve(double *a, int *na, double *b, int *nb, double *ab)
     {
       int i, j, nab = *na + *nb - 1;
     
       for(i = 0; i < nab; i++)
         ab[i] = 0.0;
       for(i = 0; i < *na; i++)
         for(j = 0; j < *nb; j++)
           ab[i + j] += a[i] * b[j];
     }
