// 4.2 : atof

#include <ctype.h>
#include <math.h>
#include "header.h"

double atof(const char* s);

double atof(const char* s) {
  size_t i = 0;
  for (; isspace(s[i]); i++);

  int sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  double val = 0.0, power = 1.0;
  while (isdigit(s[i]))
    val = val * 10 + (s[i++] - '0'); // *= takes all of rhs, low precedence

  if (s[i] == '.')
    i++;

  while (isdigit(s[i])) {
    val = val * 10 + (s[i++] - '0');
    power *= 10;
  }

  double exp = 0.0;
  if (s[i] == 'e' || s[i] == 'E') {
    int exp_sign = (s[++i] == '-') ? -1 : 1;
    double exp_mantissa = 0.0, exp_exp = 1.0;

    while (isdigit(s[i]))
      exp_mantissa = exp_mantissa * 10 + (s[i++] - '0');

    if (s[i] == '.')
	i++;

    while (isdigit(s[i])) {
      exp_mantissa = exp_mantissa * 10 + (s[i++] - '0');
      exp_exp *= 10;
    }

    exp = exp_sign * (exp_mantissa / exp_exp);
  }

  return sign * (val / power) * pow(10, exp);
}

int main() {
  putf(atof("12.23"));
  putf(atof("12.23e4"));
  putf(atof("3242.2344e-22"));

  return 0;
}
