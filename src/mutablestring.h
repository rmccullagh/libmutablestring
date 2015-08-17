/**
 * @file mutablestring.h
 * @brief Function prototypes for the public API
 *
 * Public API functions
 */
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
 *
 * @author Ryan McCullagh
 */

#ifndef __LIB_MUTABLE_STRING_INCLUDED_H
#define __LIB_MUTABLE_STRING_INCLUDED_H

#include <stddef.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_LIB_MUTABLE_STRING_DEBUG
  #define LIB_MUTABLE_STRING_DEBUG 1
#else
  #define LIB_MUTABLE_STRING_DEBUG 0
#endif

/**
 * @def LIB_MUTABLE_STRING_DEFAULT_SIZE
 * @brief The default size used to allocate the buffer member of MutableString
 */
#define LIB_MUTABLE_STRING_DEFAULT_SIZE (2)
#define LIB_MUTABLE_STRING_MAX ((size_t)-1)

#if defined _WIN32 || defined __CYGWIN__
  #define LIB_MUTABLE_STRING_HELPER_DLL_IMPORT __declspec(dllimport)
  #define LIB_MUTABLE_STRING_HELPER_DLL_EXPORT __declspec(dllexport)
  #define LIB_MUTABLE_STRING_HELPER_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define LIB_MUTABLE_STRING_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define LIB_MUTABLE_STRING_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define LIB_MUTABLE_STRING_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define LIB_MUTABLE_STRING_HELPER_DLL_IMPORT
    #define LIB_MUTABLE_STRING_HELPER_DLL_EXPORT
    #define LIB_MUTABLE_STRING_HELPER_DLL_LOCAL
  #endif
#endif

#ifdef BUILDING_LIB_MUTABLE_STRING
  #define LIB_MUTABLE_STRING_API LIB_MUTABLE_STRING_HELPER_DLL_EXPORT
#else
  #define LIB_MUTABLE_STRING_API LIB_MUTABLE_STRING_HELPER_DLL_IMPORT
#endif

/**
 * A MutableString object is a memory managed byte string whose buffer pointer
 * always contains a NULL byte at the end. While it is called string, it
 * is actually a byte array storing the length in bytes. It's possible to use 
 * it to store NULL bytes, and you'll still get a NULL byte at the end of it.
 *
 * To insert bytes use mutable_string_append_str_len
 */
typedef struct MutableString {
	/*@{*/
	size_t length;	/**< the length of the buffer, not include the NULL byte */
	size_t capacity; /**< number of bytes allocated */
	char*  buffer; /**< the NULL terminated byte array */
	/*@}*/
} MutableString;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a new MutableString instance with an allocated buffer of n bytes.
 *
 * @brief Create a new instance of MutableString with a capacity
 * of n. The buffer will be allocated to the size of n + 1 where each
 * byte in buffer will be a NULL byte.
 *
 * @param n Number of bytes to allocate
 * @return Pointer to a MutableString type, or NULL
 */
extern LIB_MUTABLE_STRING_API
MutableString* mutable_string_new_len(size_t n);

/**
 * @brief Create a new instance of MutableString. If s is not NULL,
 * then the buffer will be allocated to the length of s + 1 and 
 * length set to the length of s, not including the NULL byte, and
 * capacity set to the length of s + 1 If s is NULL, capacity will 
 * be set to #LIB_MUTABLE_STRING_DEFAULT_SIZE and length set to 0, and 
 * the buffer will not be allocated, and set to NULL
 *
 * @param s A NULL terminated string, or NULL
 * @return Pointer to a MutableString type, or NULL if memory allocation failed
 */
extern LIB_MUTABLE_STRING_API
MutableString* mutable_string_new(const char* s);

/**
 * @brief Create a new string with the length supplied
 *
 * This function creates a new instance of MutableString
 *
 * @param s a pointer to a char* buffer
 * @param len Total number of bytes to read from s
 */
extern LIB_MUTABLE_STRING_API
MutableString* mutable_string_new_str_len(const char* s, size_t len);

extern LIB_MUTABLE_STRING_API
void mutable_string_append(MutableString* ms, const char* s);

extern LIB_MUTABLE_STRING_API
void mutable_string_append_c(MutableString* ms, char s);

extern LIB_MUTABLE_STRING_API
const char* mutable_string_lib_version(void);

#ifdef __cplusplus
}
#endif

#endif /* __LIB_MUTABLE_STRING_H */
