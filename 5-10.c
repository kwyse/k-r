// 5.10 : RPN expr evaluator

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isnumber(const char* str) {
    while (*str) {
	if (!isdigit(*str))
	    return false;

	str++;
    }

    return true;
}

int main(int argc, char* argv[]) {
    int operands[1000];
    int* ptr = operands;
    while (--argc > 0 && isnumber(*++argv))
	*ptr++ = atoi(*argv);

    int operator, a, b;
    while (argc-- > 0 && (operator = (*argv++)[0])) {
	switch (operator) {
	case '+':
	    a = *--ptr;
	    b = *--ptr;
	    *ptr++ = a + b;
	    break;
	case 'x':
	    a = *--ptr;
	    b = *--ptr;
	    *ptr++ = a * b;
	    break;
	default:
	    printf("Usage: <OPERANDS>... <OPERATORS>...\n");
	    break;
	}
    }

    printf("%d\n", *--ptr);

    return 0;
}
