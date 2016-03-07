// 1.24 : Lint

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* arr;
  size_t capacity;
  size_t size;
} Stack;

Stack* stack_new(size_t initial_capacity) {
  char* arr = malloc(sizeof(char) * initial_capacity);
  Stack* stack = malloc(sizeof(Stack));
  
  stack->arr = arr;
  stack->capacity = initial_capacity;
  stack->size = 0;
  return stack;
}

void stack_push(Stack* stack, char c) {
  if (stack->size >= stack->capacity) {
    stack->arr = realloc(stack->arr, sizeof(char) * stack->capacity * 2);
    stack->capacity *= 2;
  }
  
  stack->arr[stack->size++] = c;
}

bool stack_empty(Stack* stack) {
  return stack->size == 0;
}

char stack_peek(Stack* stack) {
  if (stack->size == 0)
    return '\0';

  return stack->arr[stack->size - 1];
}

char stack_pop(Stack* stack) {
  if (stack->size == 0)
    return '\0';

  stack->size--;
  return stack->arr[stack->size];
}

void stack_delete(Stack* stack) {
  free(stack->arr);
  free(stack);
}

//! Checks if the character is ignored during parsing
//!
//! This predicate determines if the character represented by the supplied index
//! is preceeded by a backslash, occurs within quotation marks, a comment block
//! or is otherwise ignored.
//!
//! \param str The input string to check the character against
//! \param i The index representing the character to check
//!
bool is_parsed(char* str, int16_t i) {
  if (str[i - 1] == '\\')
    return false;

  return true;
}

bool is_balanced_schar(char c) {
  return strchr("({['\"", c) != '\0';
}

bool is_balanced_echar(char c) {
  return strchr(")}]'\"", c) != '\0';
}

char get_balanced_char(char c) {
  char retchar = '\0';
  switch (c) {
  case '(': retchar = ')'; break;
  case '{': retchar = '}'; break;
  case '[': retchar = ']'; break;
  case '\'': retchar = '\''; break;
  case '"': retchar = '"'; break;
  }

  return retchar;
}

bool in_quote(Stack* stack) {
  if (stack_peek(stack) == '\0')
    return false;
  else
    return strchr("'\"", stack_peek(stack)) != '\0';
}

void check_balanced_chars(char* str) {
  Stack* stack = stack_new(8);
  
  size_t len = strlen(str);
  uint32_t linenum = 1, columnnum = 1;
  bool in_cblock = false;

  for (size_t i = 0; i < len; i++) {
    if (str[i] == '\n') {
      linenum++;
      columnnum = 1;
      continue;
    }

    if (str[i] == '/' && str[i + 1] == '*' && !in_cblock)
      in_cblock = true;
    else if (str[i] == '*' && str[i + 1] == '/' && in_cblock) {
      in_cblock = false;
      i++;
    }

    if (in_cblock)
      continue;
    
    if (is_balanced_schar(str[i]) && !in_quote(stack))
      stack_push(stack, str[i]);
    else if (is_balanced_echar(str[i])) {
      if (stack_peek(stack) == str[i] && in_quote(stack)) {
	stack_pop(stack);
	continue;
      } else if (!in_quote(stack)) {
      	char expected_echar = get_balanced_char(stack_pop(stack));
	char actual_echar = str[i];
	if (actual_echar != expected_echar) {
	  if (expected_echar == '\0')
	    printf("Error (line%d, column %d): Found unbalanced closing %c\n",
		   linenum, columnnum,
		   actual_echar);
	  else
	    printf("Error (line %d, column %d): Expected %c but found %c\n",
		   linenum, columnnum,
		   expected_echar, actual_echar);
	  stack_delete(stack);
	  exit(EXIT_FAILURE);
	}
      }
    }

    columnnum++;
  }

  bool is_chars_balanced = stack_empty(stack);
  if (!is_chars_balanced) {
    printf("Error: Found %c with no corresponding %c\n", stack_peek(stack),
	   get_balanced_char(stack_peek(stack)));
  }
  
  stack_delete(stack);
  if (!is_chars_balanced)
    exit(EXIT_FAILURE);
}

int main() {
  char* input = "{}'(]'[]{()}\"hello[[\"()/*[](*/(}";
  check_balanced_chars(input);
  return EXIT_SUCCESS;
}
