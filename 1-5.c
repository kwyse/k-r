#include <stdio.h>
#include <stdint.h>

int main() {
    const uint8_t lower = 0;
    const uint16_t upper = 300;
    const uint8_t step = 20;

    for (float fahrenheit = upper; fahrenheit >= lower; fahrenheit -= step) {
        printf("%3.0f %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
    }
}
