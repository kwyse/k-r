// 5.5 : strncpy, strncat and strncmp

#include "header.h"

void mystrncpy(char* s, const char* t, size_t n);
void mystrncat(char* s, const char* t, size_t n);
int mystrncmp(const char* s, const char* t, size_t n);

void mystrncpy(char* s, const char* t, size_t n)
{
    while ((*s++ = *t++) && n--);
    *s = '\0';
}

void mystrncat(char* s, const char* t, size_t n)
{
    char* send = s + strlen(s);
    while ((*send++ = *t++) && n--);
    *send = '\0';
}

int mystrncmp(const char* s, const char* t, size_t n)
{
    for (; (*s == *t) && n--; s++, t++) {
	if (*s == '\0')
	    return 0;
    }

    return *s - *t;
}

int main()
{
    char s[100];
    char* t = "should have known better than to let you leave alone";

    mystrncpy(s, t, 6);
    puts(s);

    mystrncat(s, "have become a lumberjack", 4);
    puts(s);

    putd(mystrncmp("this c", "this begins", 8));
    putd(mystrncmp("this c", "this ends", 8));

    return 0;
}
