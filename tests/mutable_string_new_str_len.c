#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <mutablestring.h>

#include "test_common.h"

static void test_mutable_string_new_str_len(void)
{
	const char* s = "Ryan";

	MutableString* ms = mutable_string_new_str_len(s + 1, 3);
	expect(ms != NULL);
	expect(ms->length == 3);
	expect(ms->capacity == 4);
	expect(ms->buffer != NULL);
	expect(ms->buffer[ms->length] == '\0');
	expect(str_equal("yan", ms->buffer));

	free(ms->buffer);
	free(ms);
}

int main(void)
{
	test_mutable_string_new_str_len();

	return 0;
}
