#include <stdio.h>

int main() {
    int input;
    int successive_blanks = 0;
    while ((input = getchar()) != EOF) {
        if (input == '\t') {
            putchar('\\');
            putchar('t');
        } else if (input == '\b') {
            putchar('\\');
            putchar('b');
        } else if (input == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(input);
        }
    }
}
