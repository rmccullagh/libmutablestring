AC_INIT([libmutablestring], [1.0.0], [bug-automake@whiletrueconsulting.com])
AM_INIT_AUTOMAKE([-Wno-portability])
LT_INIT([disable-static])
AC_SUBST([LIBTOOL_DEPS])
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_INSTALL
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([src/config.h])
LIB_MUTABLE_STRING_VERSION=1:0:0
AC_SUBST(LIB_MUTABLE_STRING_VERSION)
AC_ARG_ENABLE(debug,
              [AS_HELP_STRING([--enable-debug],
                             [Turn on debugging [default=no]])],[enable_debug=yes],
              [enable_debug=no])

AC_MSG_CHECKING([if we are enabling debug support])
AS_IF([test "x$enable_debug" = "xyes"], [
       AC_DEFINE(HAVE_LIB_MUTABLE_STRING_DEBUG, 1, [Wheather to enable debugging messages])
       AC_MSG_RESULT([yes])
], [ AC_MSG_RESULT([no]) ])


if test -n "$GCC"; then
  CFLAGS="$CFLAGS -Wall -Wextra -Werror"
fi

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/configure.h
 tests/Makefile
])
AC_OUTPUT

cat << EOF

Build configuration:
	CPPFLAGS = $CPPFLAGS
	CFLAGS = $CFLAGS
	CXXFLAGS = $CXXFLAGS
	LDFLAGS = $LDFLAGS
	CC = $CC
	Installation prefix: $prefix

	To run the tests use make check

EOF
