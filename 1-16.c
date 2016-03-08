#include <stdio.h>

int get_line_length(char* line, int max_length);
void copy(char* to, char* from);
void chomp(char* line);

int main() {
  const int MAX_LINE_LENGTH = 1000;

  int max_length = 0;
  char current_line[MAX_LINE_LENGTH];
  char longest_line[MAX_LINE_LENGTH];

  int current_length;
  while ((current_length = get_line_length(current_line, MAX_LINE_LENGTH)) > 0) {
    if (current_length > max_length) {
      max_length = current_length;
      copy(longest_line, current_line);
    }
  }

  if (max_length > 0) {
    chomp(longest_line);
    printf("Longest line (%d chars): '%s'\n", max_length - 1, longest_line);
  } else
    puts("No lines found!");

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

void chomp(char* line) {
  int i;
  for(i = 0; line[i] != '\n'; i++);
  line[i] = '\0';
}
