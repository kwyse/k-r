#include <stdio.h>
#include <stdint.h>

int main() {
    const uint8_t lower = 0;
    const uint16_t upper = 300;
    const uint8_t step = 20;

    puts("-- TEMP CONVERSION PROGRAM (C to F) --\n");
    float celcius = lower;
    while (celcius <= upper) {
        float fahrenheit = (9.f / 5.f) * (celcius + 32);
        printf("%3.0f %6.1f\n", celcius, fahrenheit);
        celcius += step;
    }
}
