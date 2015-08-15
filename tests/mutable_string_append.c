#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <mutablestring.h>

#include "test_common.h"

static void test_mutable_string_append(void)
{
	MutableString* ms = mutable_string_new("Ryan");
	expect(ms != NULL);
	expect(ms->capacity == 5);
	expect(ms->length == 4);
	expect(ms->buffer != NULL);
	expect(str_equal("Ryan", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	mutable_string_append(ms, " McCullagh");
	expect(ms->length == 14);
	expect(ms->capacity == 20);
	expect(str_equal("Ryan McCullagh", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	mutable_string_append(ms, "123456");
	expect(ms->length == 20);
	expect(ms->capacity == 40);
	expect(str_equal("Ryan McCullagh123456", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	mutable_string_append(ms, NULL);
	
	expect(ms->length == 20);
	expect(ms->capacity == 40);
	expect(str_equal("Ryan McCullagh123456", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	
	mutable_string_append(NULL, NULL);
	
	expect(ms->length == 20);
	expect(ms->capacity == 40);
	expect(str_equal("Ryan McCullagh123456", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');
	
	free(ms->buffer);
	free(ms);
}

int main(void)
{
	test_mutable_string_append();

	return 0;
}
