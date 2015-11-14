#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <mutablestring.h>

#include "test_common.h"

static void test_mutable_string_copy(void)
{
	MutableString* ms = mutable_string_new("Ryan");
	expect(ms != NULL);
	expect(ms->capacity == 5);
	expect(ms->length == 4);
	expect(ms->buffer != NULL);
	expect(str_equal("Ryan", ms->buffer));
	expect(ms->buffer[ms->length] == '\0');

	MutableString* copy;
	copy = mutable_string_copy(ms);

	expect(copy != NULL);
	expect(copy->capacity == 5);
	expect(copy->length == 4);
	expect(copy->buffer != NULL);
	expect(str_equal("Ryan", copy->buffer));
	expect(copy->buffer[copy->length] == '\0');

	mutable_string_free(ms);
	mutable_string_free(copy);

}

int main(void)
{
	test_mutable_string_copy();

	return 0;
}
