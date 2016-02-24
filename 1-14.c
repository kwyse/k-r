#include <stdio.h>
#include <stdint.h>

int main() {
    const uint8_t MAX_CHARS = 26;
    uint32_t char_counts[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) char_counts[i] = 0;

    int input_char;
    while ((input_char = getchar()) != EOF) {
        if (input_char >= 'a' && input_char <= 'z')
            char_counts[input_char - 'a']++;
        else if (input_char >= 'A' && input_char <= 'Z')
            char_counts[input_char - 'A']++;
    }

    printf("\n");
    for (int i = 0; i < MAX_CHARS; i++) {
        printf("%c| ", i + 'A');
        for (size_t j = 0; j < char_counts[i]; j++) {
            putchar('#');
        }

        printf("\n");
    }
}
