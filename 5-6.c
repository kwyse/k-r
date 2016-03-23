// 5.6 : getln, atoi, itoa, rev and strindex

#include <ctype.h>
#include "header.h"

size_t getln(const char* line);
int atoi(const char* n);
char* itoa(int n, char* out);
char* rev(char* str);
int strindex(char* s, char* t);

size_t getln(const char* line)
{
    size_t i = 0;
    for( ; *line != '\n' && *line++ != '\0'; i++);
    return i;
}

int atoi(const char* n)
{
    for( ; isspace(*n); n++);

    int sign = (*n == '-') ? -1 : 1;
    if (*n == '+' || *n == '-')
	n++;

    int val = 0;
    while (isdigit(*n))
	val = val * 10 + (*n++ - '0');
    
    return val * sign;
}

char* itoa(int n, char* out)
{
    char* start = out;
    bool isneg = n < 0;
    if (isneg)
	n = -(n + 1);

    *out++ = (n % 10) + '0' + (isneg ? 1 : 0);
    while (n /= 10)
	*out++ = (n % 10) + '0';

    if (isneg)
	*out++ = '-';

    *out = '\0';
    return rev(start);
}

char* rev(char* str)
{
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start <= end) {
	char tmp = *start;
	*start++ = *end;
	*end-- = tmp;
    }

    return str;
}

int strindex(char* s, char* t)
{
    char* sstart = s;
    char* tstart = t;
    for( ; *s; s++) {
	for (char* c = s; *t && (*c == *t); c++, t++);
	if (t > tstart && *t == '\0')
	    return s - sstart;
    }
	
    return -1;
}

int main()
{
    a(getln("I am hungry!") == 12);

    a(atoi("0") == 0);
    a(atoi("-1") == -1);
    a(atoi("1") == 1);
    a(atoi("-2147483647") == -2147483647);
    a(atoi("-2147483648") == -2147483648);
    a(atoi("2147483647") == 2147483647);
    a(atoi("2147483648") == -2147483648);
    a(atoi("2147483649") == -2147483647);
    a(atoi("  10    ") == 10);

    char* out = malloc(sizeof(int) * 100);
    as(itoa(0, out), "0");
    as(itoa(-1, out), "-1");
    as(itoa(1, out), "1");
    as(itoa(-2147483647, out), "-2147483647");
    as(itoa(-2147483648, out), "-2147483648");
    as(itoa(2147483647, out), "2147483647");
    as(itoa(2147483648, out), "-2147483648");
    as(itoa(2147483649, out), "-2147483647");
    as(itoa(10, out), "10");
    free(out);

    char str[] = "palindrome";
    as(rev(str), "emordnilap");
    as(rev(str), "palindrome");

    a(strindex("hello", "llo") == 2);
    a(strindex("hello", "hhello") == -1);
    a(strindex("hello", "good bye") == -1);
    a(strindex("hello", "hello") == 0);
    a(strindex("hello", "o") == 4);
    a(strindex("hello", "") == -1);

    return 0;
}
