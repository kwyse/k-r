// 1.20 : Detab

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void detab(const char* instr, char outstr[], uint8_t tabstop) {
  size_t len = strlen(instr);

  size_t tabs = 0;
  for (; tabs < len && instr[tabs] == '\t'; tabs++);

  size_t spaces = tabs * tabstop;
  strcpy(outstr, instr);
  for (size_t i = len + spaces - tabs - 1; (int) i >= tabs; i--)
    outstr[i] = outstr[i - spaces + tabs];

  outstr[len + spaces - tabs] = '\0';
  for (size_t i = 0; i < spaces; i++)
    outstr[i] = ' ';
}

int main() {
  char* input = "\t\tThis is a string";
  char output[strlen(input) + 15];
  detab(input, output, 8);
  puts(input);
  puts(output);
}
