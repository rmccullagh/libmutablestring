noinst_HEADERS = configure.h
lib_LTLIBRARIES = libmutablestring.la
libmutablestring_la_SOURCES = configure.h mutablestring.c
libmutablestring_la_CFLAGS = $(AM_CFLAGS)
libmutablestring_la_CPPFLAGS = -DBUILDING_LIB_MUTABLE_STRING
libmutablestring_la_LDFLAGS = -no-undefined -version-info ${LIB_MUTABLE_STRING_VERSION}
include_HEADERS = mutablestring.h
