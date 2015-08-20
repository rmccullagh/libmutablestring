#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mutablestring.h>
#include "test_common.h"

void test_mutable_string_escape(void)
{
	MutableString* raw;
	MutableString* escaped;

	raw = mutable_string_new("\tRyan\nMcCullagh\n");
	expect(raw != NULL);
	
	escaped = mutable_string_escape(raw);
	expect(escaped != NULL);

	expect(str_equal(escaped->buffer, "\\tRyan\\nMcCullagh\\n"));

	mutable_string_free(raw);
	mutable_string_free(escaped);
}

int main(void)
{
	test_mutable_string_escape();

	return 0;
}


