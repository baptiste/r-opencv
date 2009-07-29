AC_INIT([ropencv], 0.0.1) dnl package name, version

dnl User-specifable options goes here

dnl Select an optional include path, from a configure option
dnl or from an environment variable
AC_ARG_WITH([opencv-include],
	    AC_HELP_STRING([--with-opencv-include=INCLUDE_PATH],
			   [the location of OpenCV header files]),
	    [opencv_include_path=$withval])
ROPENCV_CPPFLAGS="-I."
if test [ -n "$opencv_include_path"] ; then
   ROPENCV_CPPFLAGS="-I. -I${opencv_include_path}"
else
  if test [ -n "${OPENCV_INCLUDE}" ] ; then
    ROPENCV_CPPFLAGS="-I. -I${OPENCV_INCLUDE}"
  fi
fi

dnl ditto for a library path
AC_ARG_WITH([opencv-lib],
	    AC_HELP_STRING([--with-opencv-lib=LIB_PATH],
		           [the location of OpenCV libraries]),
	    [opencv_lib_path=$withval])
if test [ -n "$opencv_lib_path" ] ; then
  LIBS="-L$opencv_lib_path ${LIBS}"
else
  if test [ -n "${OPENCV_LIBS}" ] ; then
    LIBS="-L${OPENCV_LIBS} ${LIBS}"
  fi
fi

dnl Find the compiler and compiler flags to use
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
 echo "could not determine R_HOME"
  exit 1	   
fi
CC=`"${R_HOME}/bin/R" CMD config CC`
CPP=`"${R_HOME}/bin/R" CMD config CPP`
CFLAGS=`"${R_HOME}/bin/R" CMD config CFLAGS`
CPPFLAGS=`"${R_HOME}/bin/R" CMD config CPPFLAGS`
AC_PROG_CC
AC_PROG_CPP

CPPFLAGS="${CPPFLAGS} ${ROPENCV_CPPFLAGS}"

dnl Check the headers can be found
AC_CHECK_HEADERS([cv.h])
AC_CHECK_HEADERS([highgui.h])
dnl if test "${HAVE_CV_H}" = 0 || "${HAVE_HIGHGUI_H}" = no; then
dnl      AC_MSG_ERROR("OpenCV headers cv.h and highgui.h not found")
dnl fi
          
          
dnl substitute ROPENCV_CPPFLAGS and LIBS
AC_SUBST(ROPENCV_CPPFLAGS)
AC_SUBST(LIBS)
AC_CONFIG_HEADERS([src/config.h])

dnl and do substitution in the src/Makevars.in and src/config.h
AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT
