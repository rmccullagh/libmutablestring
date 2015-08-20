#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mutablestring.h>
#include "test_common.h"

void test_mutable_string_compare(void)
{
	MutableString* m1;
	MutableString* m2;
	int st;

	m1 = mutable_string_new("Ryan");
	m2 = mutable_string_new("Ryan");

	st = mutable_string_compare(m1, m2);

	expect(st == 0);

	mutable_string_free(m1);
	mutable_string_free(m2);
}

int main(void)
{
	test_mutable_string_compare();

	return 0;
}


