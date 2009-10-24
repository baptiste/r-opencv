## configure.ac for the configuration of ropencv package
## Jitao David Zhang <j.zhang@dkfz.de>, 2009-08-02

## initial information about the project
AC_INIT([ropencv], 0.0.4, [j.zhang@dkfz.de])

## check if the source folder is available
AC_CONFIG_SRCDIR([src/])

## Select an optional library path
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

## use pkg-config to set flags
AC_CHECK_PROG(pkgfound, [pkg-config --version], yes, no)
if test "$pkgfound" = "yes" ; then
   if `pkg-config --cflags opencv > /dev/null`; then
     echo pkg-config found
     COMPILERFLAGS="`pkg-config --cflags opencv`"
     CFLAGS="-DGLIB_GETTEXT ${COMPILERFLAGS} ${CFLAGS}"
     CXXFLAGS="-DGLIB_GETTEXT ${COMPILERFLAGS} ${CXXFLAGS}"
     LINKERFLAGS="`pkg-config --libs opencv`"
     LIBS="${LINKERFLAGS} ${LIBS} ${LFLAGS}"
     LFLAGS="${LIBS}"
   else
     echo 'pkg-config' does not know anything about opencv
   fi
else
   echo 'pkg-config' not found!   
fi



## Find the compiler and compiler flags to use
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
   AC_MSG_ERROR("could not determine R_HOME...")
fi

## substitute ROPENCV_CPPFLAGS and LIBS
AC_SUBST(CFLAGS)
AC_SUBST(CPPFLAGS)
AC_SUBST(LIBS)

dnl saving output variables into Makevar.in and config.R
AC_CONFIG_HEADERS([src/config.h])
AC_OUTPUT(src/Makevars)

