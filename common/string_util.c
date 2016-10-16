// string_util.c
#include "string_util.h"

#include <ctype.h>
#include <string.h>

bool isnumber(const char* str) {
    size_t len = strlen(str);
    size_t i;
    for (i = 0; isdigit(*str++); i++);

    return i == len;
}
