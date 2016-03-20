// 4.12 : Recursive itoa

#include "header.h"

void itoa(int n, char to[], size_t i);

void itoa(int n, char to[], size_t i)
{
    if (n < 0) {
	to[0] = '-';
	n = -n;
    }

    if (n / 10)
	itoa(n / 10, to, i - 1);
    to[i] = (n % 10 + '0');
}

int main()
{
    char output[100];
    itoa(786, output, 2);
    puts(output);
    itoa(-786, output, 3);
    puts(output);

    return 0;
}
