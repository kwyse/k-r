// 4.1 : Find substring from right side

#include "header.h"

int strrindex(const char* s, const char* t);

int strrindex(const char* s, const char* t) {
  for (size_t i = strlen(s) - 1; (int) i >= 0; i--) {
    size_t k = 0;
    for (size_t j = i; s[j] == t[k] && t[k] != '\0'; j++, k++);
    if (k > 0 && t[k] == '\0')
      return (int) i;
  }

  return -1;
}

int main() {
  putd(strrindex("hell is no heaven nor hello", "he"));

  return 0;
}
