// 1.21 : Entab

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void entab(const char* instr, char outstr[], uint8_t tabstop) {
  if (tabstop == 0)
    return;
  
  size_t len = strlen(instr);
  size_t spaces = 0;
  for (; spaces < len && instr[spaces] == ' '; spaces++);

  size_t tabs = spaces / tabstop;
  size_t extra_spaces = spaces % tabstop;

  strcpy(outstr, instr);
  for (size_t i = tabs + extra_spaces; i < len - spaces + tabs + extra_spaces; i++)
    outstr[i] = outstr[i + spaces - tabs - extra_spaces];

  outstr[len - spaces + tabs + extra_spaces] = '\0';
  for (size_t i = 0; i < tabs; i++)
    outstr[i] = '\t';
}
  

int main() {
  char input[]= "                  This is a string";
  char output[strlen(input)];
  entab(input, output, 8);
  puts(input);
  puts(output);
}
