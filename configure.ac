dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(room-game, 1.0)


AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CXX

AC_CHECK_LIB([SDL], [SDL_SetVideoMode], [])
AC_CHECK_LIB([SDL_image], [IMG_Load], [])

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

