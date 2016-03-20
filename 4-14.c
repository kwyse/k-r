// 4.14 : Swap macro

#include "header.h"

#define swap(t, x, y) {\
	t tmp = x;\
	x = y;\
	y = tmp;\
    }

int main()
{
    char output[] = "0 and 1";
    swap(char, output[0], output[6]);
    puts(output);

    return 0;
}
