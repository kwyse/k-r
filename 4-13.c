// 4.13 : Recursive reverse(str)

#include "header.h"

void reverse_r(char str[], size_t start, size_t end);
void swap(char str[], size_t i, size_t j);

void reverse_r(char str[], size_t start, size_t end)
{
    if (start >= end)
	return;

    swap(str, start, end);
    reverse_r(str, start + 1, end - 1);
}

void swap(char str[], size_t i, size_t j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

int main()
{
    char output[] = "Hello there, buddy!";
    reverse_r(output, 0, strlen(output) - 1);
    puts(output);

    return 0;
}
