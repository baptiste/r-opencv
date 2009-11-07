# configure.ac for the configuration of ropencv package
# Jitao David Zhang <j.zhang@dkfz.de>

AC_INIT([ropencv], 0.1, [j.zhang@dkfz.de])

AC_CONFIG_SRCDIR([src])

CFLAGS="-Wall ${CFLAGS}"
CXXFLAGS="-Wall ${CXXFLAGS}"

PKGCONF=[pkg-config]
AC_CHECK_PROG(pkgfound, [pkg-config --version], yes, no)
if test "$pkgfound" = "no" ; then
  PKGCONF=pkgconfig
  AC_CHECK_PROG(pkgfound, [pkgconfig --version], yes, no)
fi

if test "$pkgfound"="yes"; then
   if `$PKGCONF --cflags opencv > /dev/null`; then
     echo "** OpenCV found by $PKGCONF"
     COMPILERFLAGS="`$PKGCONF --cflags opencv`"
     CFLAGS="${COMPILERFLAGS} ${CFLAGS}"
     CXXFLAGS="${COMPILERFLAGS} ${CXXFLAGS}"
     LINKERFLAGS="`$PKGCONF --libs opencv`"
     LIBS="${LINKERFLAGS} ${LIBS} ${LFALGS}"
   else
     echo "** OpenCV not found by $PKGCONF, trying command line options"
   fi
else
  AC_ARG_WITH([opencv-include],
	    AC_HELP_STRING([--with-opencv-include=INCLUDE_PATH],
			   [the location of OpenCV header files]),
	    [opencv_include=$withval])
  if test [ -n "$opencv_include"] ; then
    CFLAGS="-I${opencv_include} ${CFLAGS}"
    CXXFLAGS="-I${opencv_include} ${CXXFLAGS}"
  else
    AC_MSG_ERROR("OpenCV includes not found!")
  fi
  
  AC_ARG_WITH([opencv-lib],
	    AC_HELP_STRING([--with-opencv-lib=LIB_PATH],
		           [the location of OpenCV libraries]),
	    [opencv_lib_path=$withval])
  if test [ -n "$opencv_lib_path" ] ; then
    LIBS="-L{$opencv_lib_path} ${LIBS}"
  else
    AC_MSG_ERROR("OpenCV library not found!")
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
CFLAGS="`"${R_HOME}/bin/R" CMD config CFLAGS` ${CFLAGS}"
CXXFLAGS="`"${R_HOME}/bin/R" CMD config CXXFLAGS` ${CXXFLAGS}"
AC_PROG_CC
AC_PROG_CPP

# substitute ROPENCV_CXXFLAGS and LIBS
AC_SUBST(CFLAGS)
AC_SUBST(CXXFLAGS)
AC_SUBST(LIBS)
AC_CONFIG_HEADERS([src/config.h])

dnl and do substitution in the src/Makevars.in and src/config.h
AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT
