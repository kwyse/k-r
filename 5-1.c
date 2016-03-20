// 5.1 : getint + if non-digit after [+|-], put char back into input

#include "header.h"

int getint(int* dest)
{
    int c;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
	ungetch(c);
	return 0;
    }

    int sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
	c = getch();

    if (!isdigit(c)) {
	ungetch(c);
	return 0;
    }

    for (*dest = 0; isdigit(c); c = getch())
	*dest = 10 * (*dest) + (c - '0');

    *dest *= sign;
    if (c != EOF)
	ungetch(c);

    return c;
}

int main()
{
    int output[1];
    while (getint(output) > 0)
	putd(*output);

    return 0;
}
