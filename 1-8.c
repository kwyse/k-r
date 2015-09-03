#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t blanks = 0;
    uint32_t tabs = 0;
    uint32_t newlines = 0;

    int input;
    while ((input = getchar()) != EOF) {
        if (input == ' ') blanks++;
        if (input == '\t') tabs++;
        if (input == '\n') newlines++;
    }

    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
}
