#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
    const uint32_t MAX_WORD_LENGTH = 20;

    uint32_t word_lengths[MAX_WORD_LENGTH + 1];
    for (int i = 0; i <= MAX_WORD_LENGTH; i++) word_lengths[i] = 0;

    uint8_t size = 0;
    bool in_word = true;

    int input_char;
    while ((input_char = getchar()) != EOF) {
        if ((input_char == ' ' || input_char == '\t' || input_char == '\n')) {
            in_word = false;

            if (size > 0) word_lengths[size]++;
            size = 0;
        } else if (!in_word) {
            in_word = true;
        }

        if (in_word) size++;
    }

    for (uint8_t i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%2d. ", i);
        for (uint32_t j = 0; j < word_lengths[i]; j++) printf("#");
        puts("");
    }

    puts("");
    puts("");

    uint32_t max_found_length = 0;
    for (uint8_t i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] > max_found_length) max_found_length = word_lengths[i];
    }

    for (uint8_t i = max_found_length; i >= 0; i--) {
        for (uint8_t j = 0; j < MAX_WORD_LENGTH; j++) {
            if (word_lengths[j] >= i) printf("#");
            else printf(" ");
        }

        puts("");
        printf("%d\n", max_found_length);
    }
}
