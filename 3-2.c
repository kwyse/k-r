// 3.2 : Display escape sequences

#include "header.h"

void escape(const char* s, char t[]) {
  size_t j = 0;
  for (size_t i = 0; i < strlen(s); i++) {
    switch (s[i]) {
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    default:
      t[j++] = s[i];
    }
  }

  t[j] = '\0';
}

void rescape(const char* s, char t[]) {
  size_t j = 0;
  for (size_t i = 0; i < strlen(s); i++) {
    if (s[i] == '\\') {
      switch (s[++i]) {
      case 't':
	t[j++] = '\t';
	break;
      case 'n':
	t[j++] = '\n';
      }
    } else
      t[j++] = s[i];
  }

  t[j] = '\0';
}

int main() {
  char output[50];
  escape("this\nis\t\ta\n\ttest\n", output);
  puts(output);

  char reoutput[100];
  rescape(output, reoutput);
  puts(reoutput);
  return 0;
}
