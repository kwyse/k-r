#include <stdio.h>

int get_line_length(char* line);
char* reverse(char str[]);

int main() {
  char input[] = "hot damn, son!";
  printf("Before reverse: '%s'\n", input);
  printf("After reverse: '%s'\n", reverse(input));
  
  return 0;
}

int get_line_length(char* line) {
  int length;
  for (length = 0; line[length] != '\n' && line[length] != '\0'; length++);
  return ++length;
}

char* reverse(char str[]) {
  int length = get_line_length(str);
  for (int i = 0, j = length - 2; i < (length - 1) / 2 && j >= (length - 1) / 2; i++, j--) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }

  return str;
}
