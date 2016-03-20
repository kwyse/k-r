// 5.3 : strcat with pointers

#include "header.h"

void mystrcat(char* s, char* t);

void mystrcat(char* s, char* t)
{
    char* send = s + strlen(s);
    while ((*send++ = *t++));
}

int main()
{
    char s[100] = "this is ";
    char* t = "not the end";
    mystrcat(s, t);
    puts(s);

    return 0;
}
