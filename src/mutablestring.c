/*
 *  Copyright (c) 2015 Ryan McCullagh <me@ryanmccullagh.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <configure.h>
#include <mutablestring.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline MutableString* mutable_string_sized_init(size_t capacity)
{
	MutableString* ms = malloc(sizeof(MutableString));

	if(ms == NULL)
		return NULL;
	
	ms->length = 0;
	ms->capacity = capacity;
	ms->buffer = NULL;

	return ms;
	
}

static inline void mutable_string_append_str_len(MutableString* ms, const char* begin, size_t len)
{
	if(ms == NULL || begin == NULL)
		return;

	size_t old_len;
	old_len = ms->length;
	size_t i;
        i = 0;
	ms->length = len + old_len;

	if(ms->length >= ms->capacity) 
	{
		if(ms->buffer == NULL) 
		{
			ms->capacity *= 2;
			ms->buffer = malloc(ms->capacity);
			if(ms->buffer == NULL)
				return;
		}
		else
		{
			while(ms->length >= ms->capacity)
			{
				ms->capacity *= 2;
				ms->buffer = realloc(ms->buffer, ms->capacity);
				if(ms->buffer == NULL)
					return;

				
			}
		}
	}
	else
	{

		if(ms->buffer == NULL) 
		{
			ms->buffer = malloc(ms->capacity);
			if(ms->buffer == NULL)
				return;
		}

	}


	while(i < len)
	{
		ms->buffer[old_len++] = *begin;
		begin++;
		i++;
	}

	ms->buffer[ms->length] = '\0';

}

static inline void mutable_string_clear_buffer(MutableString* ms)
{
	if(ms == NULL)
		return;

	if(ms->buffer == NULL)
		return;

	memset(ms->buffer, '\0', ms->capacity);
}

static inline void mutable_string_buffer_init(MutableString* ms)
{
	if(ms == NULL)
		return;

	if(ms->buffer != NULL)
		return;

	ms->buffer = malloc(ms->capacity);

	mutable_string_clear_buffer(ms);

}

LIB_MUTABLE_STRING_API MutableString* mutable_string_new_len(size_t n)
{
	MutableString* ms;

	if(n < LIB_MUTABLE_STRING_DEFAULT_SIZE)
		n = LIB_MUTABLE_STRING_DEFAULT_SIZE;
	
	ms = mutable_string_sized_init(n + 1);

	mutable_string_buffer_init(ms);

	return ms;

}

LIB_MUTABLE_STRING_API MutableString* mutable_string_new(const char* s)
{
	MutableString* ms;

	if(s == NULL) 
	{
		ms = mutable_string_sized_init(LIB_MUTABLE_STRING_DEFAULT_SIZE);
	}
	else
	{
		size_t len;
		len = strlen(s);
		ms = mutable_string_sized_init(len + 1);
		
		mutable_string_append_str_len(ms, s, len);
	}

	return ms;
}

LIB_MUTABLE_STRING_API MutableString* mutable_string_new_str_len(const char* s,
		size_t len)
{
	MutableString* ms = mutable_string_sized_init(len + 1);

	mutable_string_append_str_len(ms, s, len);

	return ms;

}

LIB_MUTABLE_STRING_API
void mutable_string_append(MutableString* ms, const char* s)
{
	if(ms == NULL || s == NULL)
		return;
	
	size_t len;
	len = strlen(s);

	mutable_string_append_str_len(ms, s, len);

}

LIB_MUTABLE_STRING_API
void mutable_string_append_c(MutableString* ms, char s)
{
	if(ms == NULL)
		return;
	
	char buf[2];
	buf[0] = s;
	buf[1] = '\0';

	const char* ref = buf;
	mutable_string_append_str_len(ms, ref, 1);
}

LIB_MUTABLE_STRING_API
const char* mutable_string_lib_version(void)
{
	return LIB_MUTABLE_STRING_VERSION_STRING;

}
