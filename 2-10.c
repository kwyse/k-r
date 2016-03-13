// 2.10 : lower

#include "header.h"

char lower(char c) {
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main() {
  printf("%c\n", lower('G'));
  printf("%c\n", lower('A'));
  printf("%c\n", lower('K'));
  printf("%c\n", lower('Z'));
  printf("%c\n", lower('z'));
  printf("%c\n", lower(':'));
  return 0;
}
