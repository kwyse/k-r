#include <stdio.h>
#include <stdint.h>

double ctof(int32_t celcius) {
  return (9.f / 5.f) * (celcius + 32);
}

int main() {
  const uint8_t lower = 0;
  const uint16_t upper = 300;
  const uint8_t step = 20;

  puts("-- TEMP CONVERSION PROGRAM (C to F) --\n");
  for (double celcius = lower; celcius <= upper; celcius += step)
    printf("%3.0f %6.1f\n", celcius, ctof(celcius));

  return 0;
}
