# configure.ac for the configuration of ropencv package
# Jitao David Zhang <JDZhang@nextbiomotif.com>

# initial information about the project
AC_INIT([ropencv], 0.0.1) dnl package name, version

# check if the source folder is available
AC_CONFIG_SRCDIR([src/miscC.c])

# Select an optional include path, from a configure option
# or from an environment variable
AC_ARG_WITH([opencv-include],
	    AC_HELP_STRING([--with-opencv-include=INCLUDE_PATH],
			   [the location of OpenCV header files]),
	    [opencv_include=$withval])
ROPENCV_CPPFLAGS="-I."
if test [ -n "$opencv_include"] ; then
   ROPENCV_CPPFLAGS="-I. -I${opencv_include}"
else
  if test [ -n "${OPENCV_INCLUDE}" ] ; then
    ROPENCV_CPPFLAGS="-I. -I${OPENCV_INCLUDE}"
  fi
fi

# Select an optional library path
AC_ARG_WITH([opencv-lib],
	    AC_HELP_STRING([--with-opencv-lib=LIB_PATH],
		           [the location of OpenCV libraries]),
	    [opencv_lib_path=$withval])
if test [ -n "$opencv_lib_path" ] ; then
  LIBS="-L{$opencv_lib_path} ${LIBS}"
else
  if test [ -n "${OPENCV_LIBS}" ] ; then
    LIBS="-L${OPENCV_LIBS} ${LIBS}"
  fi
fi

# Find the compiler and compiler flags to use
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

# Check the headers
AC_CHECK_HEADERS(cv.h highgui.h)
if test "${ac_cv_header_cv_h}" = no || 
   test "${ac_cv_header_highgui_h}" = no; then
  AC_MSG_ERROR("OpenCV headers cv.h and highgui.h not found")
fi
          
          
# substitute ROPENCV_CPPFLAGS and LIBS
AC_SUBST(ROPENCV_CPPFLAGS)
AC_SUBST(LIBS)
AC_CONFIG_HEADERS([src/config.h])

dnl and do substitution in the src/Makevars.in and src/config.h
AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT
