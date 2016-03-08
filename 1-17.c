#include <stdio.h>

int get_line_length(char* line, int max_length);
void copy(char* to, char* from);
char* chomp(char* line);

int main() {
  const int MAX_LINE_LENGTH = 1000;
  const int MAX_LINES_FOUND = 10;
  const int THRESHOLD = 80;

  char line[MAX_LINE_LENGTH];
  char long_lines[MAX_LINES_FOUND][MAX_LINE_LENGTH];
  int length, lines_found = 0;
  
  while ((length = get_line_length(line, MAX_LINE_LENGTH)) > 0) {
    if (length - 1 > THRESHOLD)
      copy(long_lines[lines_found++], line);
  }

  for (int i = 0; i < lines_found; i++)
    puts(chomp(long_lines[i]));
  
  return 0;
}

int get_line_length(char* line, int max_length) {
  int character, length = 0;

  while (length < (max_length - 1) && (character = getchar()) != EOF) {
    line[length++] = character;

    if (character == '\n')
      break;
  }

  line[length] = '\0';
  return length;
}

void copy(char* to, char* from) {
  for (int i = 0; (to[i] = from[i]) != '\0'; i++);
}

char* chomp(char* line) {
  int i;
  for(i = 0; line[i] != '\n'; i++);
  line[i] = '\0';
  return line;
}
