// 2.3 : Hex to int

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int htoi(const char* str) {
  int ret = 0;

  size_t i = 0;
  if (str[0] == '0' && tolower(str[1]) == 'x')
    i = 2;

  for (; i < strlen(str); i++) {
    if (isxdigit(str[i])) {
      ret = ret * 16 + toupper(str[i]) - '0';
      if (isalpha(str[i]))
	ret -= ('A' - '9' - 1);
    } else {
      fprintf(stderr, "Unrecognised hexidecimal digit: %c\n", str[i]);
      exit(EXIT_FAILURE);
    }
  }

  return ret;
}

int main() {
  printf("htoi for 0x8E: %d\n", htoi("8E"));
  printf("htoi for 0xFF: %d\n", htoi("0xFF"));
  printf("htoi for 0xFF: %d\n", htoi("0X123"));
  return EXIT_SUCCESS;
}
