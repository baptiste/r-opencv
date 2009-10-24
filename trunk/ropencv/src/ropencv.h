/*----------------------------------------
  ropencv Package initialization 
  Copyright (c) 2009 Jitao David Zhang
  See ../LICENSE for LPGL License Text
  ----------------------------------------*/

// package specific
// #include "display.h"

// OpenCV
#include "cv.h"
#include "cvtypes.h"
#include "highgui.h"
#include "cxcore.h"
#include "cxerror.h"

// R
#include <R.h>
#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include <R_ext/Error.h>
#include <R_ext/eventloop.h>

//  event loop
extern int (*R_timeout_handler)();
extern long R_timeout_val;

