#lib-mutablestring

A MutableString object is a memory managed byte string whose buffer pointer
always contains a NULL byte at the end. While it is called string, it
is actually a byte array storing the length in bytes. It's possible to use 
it to store NULL bytes, and you'll still get a NULL byte at the end of it.

#What is it?

Libmutable string provides a data structure called `MutableString`. The library provides useful functions for manipulating and creating strings.

```c
typedef struct MutableString {
    size_t length;
    size_t capacity;
    char*  buffer;
} MutableString;
```

#Example

```c
/**
 * This program creates a string.
 */
int main(void)
{
  MutableString* ms;
  ms = mutable_string_new(NULL); // allocate a new mutable string instance, but `buffer` isn't allocated yet.
  
  mutable_string_append(ms, "This is a string");
  mutable_string_append_c(ms, '.');
  mutable_string_append_c(ms, '\n');
  
  mutable_string_dump(stdout, ms);
  
  mutable_string_free(ms);
  
  return 0;
}
```
