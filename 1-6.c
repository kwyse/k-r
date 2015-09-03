#include <stdio.h>

int main() {
    int input;

    /* while ((input = getchar()) != EOF) */
    while (input = getchar() != EOF)
        /* putchar(input); */
        printf("%d\n", input);
}

