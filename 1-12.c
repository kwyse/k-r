#include <stdio.h>
#include <stdbool.h>

int main() {
    int input_char;
    bool in_word = true;

    while ((input_char = getchar()) != EOF) {
        if ((input_char == ' ' || input_char == '\t' || input_char == '\n')) {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            putchar('\n');
        }

        putchar(input_char);
    }
}
