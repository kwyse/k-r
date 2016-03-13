// 2.9 : bitcount

#include "header.h"

int bitcount(unsigned x) {
  int iters = 0;
  int c = 0;
  for (; x != 0; x >>= 1) {
    if (x & 01)
      c++;

    iters++;
  }

  printf("Iters: %d\n", iters);
  return c;
}

int mybitcount(unsigned x) {
  int iters = 0;
  int c = 0;
  for (; x != 0; x &= (x - 1)) {
    c++;
    iters++;
  }

  printf("Iters: %d\n", iters);
  return c;
}

int bc(unsigned x) {
  int c = 0;
  for (; x != 0; x &= (x - 1), c++);
  return c;
}

int main() {
  putd(bitcount(437)); // 6
  putd(mybitcount(437));
  putd(bc(437));
  return 0;
}
