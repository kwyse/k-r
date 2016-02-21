#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main() {
    bool in_word = false;
    uint32_t char_count = 0;
    uint32_t word_count = 0;
    uint32_t line_count = 0;

    int input_char;
    while ((input_char = getchar()) != EOF) {
        char_count++;

        // Fail on CRLF
        if (input_char == '\n') line_count++;

        if (input_char == ' ' || input_char == '\n' || input_char == '\t') {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            word_count++;
        }
    }

    printf("%d %d %d\n", line_count, word_count, char_count);
}
