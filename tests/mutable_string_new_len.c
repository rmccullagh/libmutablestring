#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <mutablestring.h>

#include "test_common.h"

/*
 * mutable_string_append_c(ms, char s)
 */
static void test_mutable_string_new_len(void)
{
	MutableString* ms = mutable_string_new_len(4);
	expect(ms != NULL);
	expect(ms->length == 0);
	expect(ms->buffer != NULL);
	expect(ms->capacity == 4);
	
	free(ms->buffer);
	free(ms);
}

int main(void)
{
	test_mutable_string_new_len();

	return 0;
}
