// 5.4 : strend

#include "header.h"

#define dbp(x) { printf("Value of %s: %p (%c)\n", #x, x, *x); }

bool strend(char* s, char* t);

bool strend(char* s, char* t)
{
    char* send = s + strlen(s) - 1;
    char* tend = t + strlen(t) - 1;

    while ((*send) == (*tend) && tend > t) {
        send--;
        tend--;
    }

    return (tend == t && *tend == *(send));
}

int main()
{
    char s[100] = "this is not the end";
    char t1[] = "is the end";
    strend(s, t1) ? puts("Yup") : puts("Nope");

    return 0;
}
