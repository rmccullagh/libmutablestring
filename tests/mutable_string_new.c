#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <mutablestring.h>

#include "test_common.h"

static void test_null_arg(void)
{
	MutableString* ms = mutable_string_new(NULL);
	expect(ms != NULL);
	expect(ms->length == 0);
	expect(ms->buffer == NULL);
	free(ms);
}

static void test_non_null_arg(void)
{
	MutableString* ms = mutable_string_new("Ryan");
	expect(ms != NULL);
	expect(ms->capacity == 5);
	expect(ms->length == 4);
	expect(ms->buffer != NULL);
	expect(str_equal("Ryan", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	free(ms->buffer);
	free(ms);
}

int main(void)
{
	test_null_arg();
	test_non_null_arg();

	return 0;
}
