// 2.1 : Primitive type ranges

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void print_ranges(char* name, bool is_signed, size_t size) {
  if (is_signed)
    printf("%s ranges from %.0f to %.0f\n", name,
	   pow(2, (size * 8) - 1) * -1,
	   pow(2, (size * 8) - 1) - 1);
  else
    printf("%s ranges from 0 to %.0f\n", name, pow(2, size * 8));
}
  
int main() {
  print_ranges("int", true, sizeof(int));
  print_ranges("signed int", true, sizeof(signed int));
  print_ranges("unsigned int", false, sizeof(unsigned int));
  print_ranges("short int", true, sizeof(short int));
  print_ranges("signed short int", true, sizeof(signed short int));
  print_ranges("unsigned short int", false, sizeof(unsigned short int));
  print_ranges("long int", true, sizeof(long int));
  print_ranges("signed long int", true, sizeof(signed long int));
  print_ranges("unsigned long int", false, sizeof(unsigned long int));
  print_ranges("long long int", true, sizeof(long long int));

  print_ranges("char", true, sizeof(char));
  print_ranges("signed char", true, sizeof(signed char));
  print_ranges("unsigned char", false, sizeof(unsigned char));

  print_ranges("float", true, sizeof(float));
  print_ranges("double", true, sizeof(double));
  print_ranges("long double", true, sizeof(long double));

  return 0;
}
