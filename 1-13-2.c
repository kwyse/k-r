#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
    const uint8_t MAX_WORD_LENGTH = 20;

    uint32_t word_lengths[MAX_WORD_LENGTH];
    for (uint8_t i = 0; i < MAX_WORD_LENGTH; i++)
        word_lengths[i] = 0;

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

    uint8_t max_occurences = 0;
    for (size_t i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] > max_occurences)
            max_occurences = word_lengths[i];
    }

    char histogram[max_occurences][MAX_WORD_LENGTH];
    for (size_t i = 0; i < max_occurences; i++) {
        for (size_t j = 0; j < MAX_WORD_LENGTH; j++)
            histogram[i][j] = ' ';
    }

    for (size_t i = 0; i < max_occurences; i++) {
        for (size_t j = 0; j < MAX_WORD_LENGTH; j++) {
            if (word_lengths[j] >= (max_occurences - i))
                histogram[i][j] = '@';
            else
                histogram[i][j] = ' ';
        }
    }

    printf("\n   +");
    for (size_t i = 1; i < MAX_WORD_LENGTH; i++)
        printf("-");
    printf("\n");
    printf("   |\n");

    for (size_t i = 0; i < max_occurences; i++) {
        printf("%3ld|", max_occurences - i);
        for (size_t j = 1; j < MAX_WORD_LENGTH; j++)
            putchar(histogram[i][j]);

        printf("\n");
    }

    printf("   +");
    for (size_t i = 1; i < MAX_WORD_LENGTH; i++)
        printf("-");
    printf("\n");

    printf("    ");
    for (size_t i = 1; i < MAX_WORD_LENGTH; i++)
        printf("%ld", i % 10);
    printf("\n");
}
