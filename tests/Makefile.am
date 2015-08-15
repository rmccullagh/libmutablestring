#AM_CFLAGS = -I$(top_builddir)/src @AM_CXXFLAGS@
#noinst_PROGRAMS = mutable_string_new
#check_PROGRAMS = mutable_string_new
#mutable_string_new_SOURCES = mutable_string_new.c
#mutable_string_new_LDADD = $(top_builddir)/src/libmutablestring.la

LDADD = $(top_builddir)/src/libmutablestring.la
#AM_CFLAGS = $(MUTABLE_STRING_WARN_CFLAGS)

check_PROGRAMS = \
	mutable_string_new		\
	mutable_string_append		\
	mutable_string_append_c 	\
	mutable_string_new_str_len 	\
	mutable_string_new_len		\
	$(NULL)

TESTS = $(check_PROGRAMS)

