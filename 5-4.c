// 5.4 : strend

#include "header.h"

bool strend(char* s, char* t);

bool strend(char* s, char* t)
{
    char* send = s + strlen(s) - 1;
    char* tend = t + strlen(t) - 1;

    while ((*send-- == *tend--) && (tend > t));

    return ((tend == t) && (*tend == *send));
}

#define display(x, y) {\
    printf("%s | %s -> %s\n", x, y, strend(x, y) ? "Yup" : "Nope");\
}

int main()
{
    char s[100] = "this is not the end";
    display(s, "the end");
    display(s, "is the end");
    display(s, "this is not the end");
    display(s, "it is said this is not the end");
    display(s, "e end");
    display(s, "end of");
    display(s, " end");

    return 0;
}
