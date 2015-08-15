#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <mutablestring.h>

#include "test_common.h"

/*
 * mutable_string_append_c(ms, char s)
 */
static void test_mutable_string_append_c(void)
{
	MutableString* ms = mutable_string_new(NULL);
	expect(ms != NULL);
	expect(ms->length == 0);
	expect(ms->buffer == NULL);
	
	mutable_string_append_c(ms, 'R');
	expect(ms->length == 1);
	expect(ms->capacity == 2);
	expect(ms->buffer != NULL);
	expect(str_equal("R", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');
	
	mutable_string_append_c(ms, 'y');
	expect(ms->length == 2);
	expect(ms->capacity == 4);
	expect(ms->buffer != NULL);
	expect(str_equal("Ry", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	mutable_string_append_c(ms, 'a');
	expect(ms->length == 3);
	expect(ms->capacity == 4);
	expect(ms->buffer != NULL);
	expect(str_equal("Rya", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	mutable_string_append_c(ms, 'n');
	expect(ms->length == 4);
	expect(ms->capacity == 8);
	expect(ms->buffer != NULL);
	expect(str_equal("Ryan", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');
	
	free(ms->buffer);
	free(ms);
}

int main(void)
{
	test_mutable_string_append_c();

	return 0;
}
