LDADD = $(top_builddir)/src/libmutablestring.la

TESTS_ENVIRONMENT=valgrind

noinst_HEADERS = \
	test_common.h		\
	$(NULL)

noinst_PROGRAMS = \
	mutable_string_new		\
	mutable_string_append		\
	mutable_string_append_c 	\
	mutable_string_new_str_len 	\
	mutable_string_new_len		\
	mutable_string_escape		\
	mutable_string_compare		\
	$(NULL)

check_PROGRAMS = \
	mutable_string_new		\
	mutable_string_append		\
	mutable_string_append_c 	\
	mutable_string_new_str_len 	\
	mutable_string_new_len		\
	mutable_string_escape		\
	mutable_string_compare		\
	$(NULL)

TESTS = $(check_PROGRAMS)

