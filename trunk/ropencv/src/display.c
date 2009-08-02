#include "ropencv.h"

/* show a image */
int showImage(char** file) {
  IplImage* img = cvLoadImage (file[0], 1);
  cvNamedWindow("Example", CV_WINDOW_AUTOSIZE);
  cvShowImage("Example", img);
  cvWaitKey(1000);
  cvDestroyWindow("Example");
  cvReleaseImage( &img );
}
