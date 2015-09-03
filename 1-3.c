#include <stdio.h>
#include <stdint.h>

int main() {
    const uint8_t lower = 0;
    const uint16_t upper = 300;
    const uint8_t step = 20;

    puts("-- TEMP CONVERSION PROGRAM (F to C) --\n");
    float fahrenheit = lower;
    while (fahrenheit <= upper) {
        float celcius = (5.f / 9.f) * (fahrenheit - 32);
        printf("%3.0f %6.1f\n", fahrenheit, celcius);
        fahrenheit += step;
    }
}
