#include <iso646.h>


#define new(T, name) T *name = malloc(sizeof(T))
#define defer(variable, result) if (not (variable)) return (result)
#define unless(condition) if (not (condition))