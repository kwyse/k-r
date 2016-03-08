#include <stdio.h>

int get_line_length(char* line);
void copy(char* to, char* from);
char* chomp(char line[]);

int main() {
  char input[] = "line with tab and newline\t\t \n";
  printf("Length before chomp: %d\n", get_line_length(input));
  printf("Length after chomp: %d\n", get_line_length(chomp(input)));

  return 0;
}

int get_line_length(char* line) {
  int length;
  for (length = 0; line[length] != '\n' && line[length] != '\0'; length++);
  return ++length;
}

void copy(char* to, char* from) {
  for (int i = 0; (to[i] = from[i]) != '\0'; i++);
}

char* chomp(char line[]) {
  int i;
  for (i = 0; line[i] != '\n'; i++);
  line[i] = '\0';

  i--;
  while (line[i] == ' ' || line[i] == '\t')
    line[i--] = '\0';

  return line;
}
