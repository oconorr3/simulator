#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_LANG(C++)
AC_INIT([disk-simulator], [0.1], [jstinf@vt.edu])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_SRCDIR([src/simulator.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AC_SUBST([CPPFLAGS], ["-I/usr/include/python2.7"])
AC_SUBST([CXXFLAGS], ["-ggdb3 -O0"])

# Checks for programs.
AC_PROG_CXX([clang++ python])
AC_PROG_CC([clang])

# Checks for libraries.
#AC_CHECK_LIB([boost_python], [list], []
#    [AC_MSG_ERROR(cannot find header file)], [boost_python-mt boost_python-py35 boost_python-py27])
AX_BOOST_PYTHON

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h pyconfig.h], [],
    [AC_MSG_ERROR(cannot find header file)])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL([stdbool.h])

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
