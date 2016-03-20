// 5.4 : strend

#include "header.h"

bool strend(char* s, char* t);

bool strend(char* s, char* t)
{
    char* send = s + strlen(s);
    char* tend = t + strlen(t);
    while (*send-- == *tend--)
	putchar(*send);

    printf("%p\n", send);
    printf("%p\n", s);
    printf("%p\n", tend);
    printf("%p\n", t);

    return (tend == t);
}

int main()
{
    char s[100] = "the end";
    char* t1 = "the end";
    strend(s, t1) ? puts("Yup") : puts("Nope");

    return 0;
}
