// 5.2 : getfloat

#include "header.h"

int getfloat(double* dest)
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

    if (!isdigit(c) && c != '.') {
	ungetch(c);
	return 0;
    }

    for (*dest = 0; isdigit(c); c = getch())
	*dest = 10 * (*dest) + (c - '0');

    if (c == '.')
	c = getch();

    int power = 1;
    for (; isdigit(c); c = getch(), power *= 10)
	*dest = 10 * (*dest) + (c - '0');

    *dest = (*dest / power) * sign;
    if (c != EOF)
	ungetch(c);

    return c;
}

int main()
{
    double output[1];
    while (getfloat(output) > 0)
	putf(*output);

    return 0;
}
