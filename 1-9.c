#include <stdio.h>
#include <stdint.h>

int main() {
    int input;
    int successive_blanks = 0;
    while ((input = getchar()) != EOF) {
        if (input == ' ') successive_blanks++;

        if (successive_blanks == 0) {
            putchar(input);
        } else if (input != ' ') {
            putchar(' ');
            putchar(input);
            successive_blanks = 0;
        }
    }
}
