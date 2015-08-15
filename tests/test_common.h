#define STRINGIFY(x) #x

#define expect(exp) do { \
	if(!(exp)) { \
		fprintf(stderr, "%s:%d:%s The expression '%s' is not true\n", __FILE__, __LINE__, __func__, STRINGIFY(exp)); \
		exit(1); \
	} \
} while(0)

static inline int str_equal(const char* a, const char* b)
{
	return strcmp(a, b) == 0;
}
