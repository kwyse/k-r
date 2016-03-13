// 2.8 : right rotate bits

#include <stdio.h>

void putd(int d) {
  printf("%d\n", d);
}

// Get n bits from position p in x
unsigned int getbits(unsigned int x, int p, int n) {
  // return (x >> (p + 1 - n)) & ~(~0 << n);

  // x = 111000

  // Move desired bit range to the end of the word
  unsigned int right_adjusted_word = x >> (p + 1 - n); // x = 56 = 00001110

  unsigned int all_ones = ~0; // Do this to make it independent of word size? Maybe not...
  unsigned int zeros_in_right_n_bits = all_ones << n; // 11111000
  unsigned int ones_in_right_n_bits = ~zeros_in_right_n_bits; // 00000111

  // Mask bits to ignore more significant bits
  unsigned int bits_in_range = right_adjusted_word & ones_in_right_n_bits; // 00000110 = 6

  return bits_in_range;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // mask = value with range of bits to be changed set to 1
  // value = (value & ~mask) | (newvalue & mask)

  // 111000, 4, 3, 101
  unsigned desired_bits = getbits(y, n - 1, n); // 101
  unsigned correctly_positioned_bits = desired_bits << (p + 1 - n); // 10100
  unsigned mask = (~(~0 << n)) << (p + 1 - n); //correctly_positioned_bits | 0; // 11100

  unsigned ret = (x & ~mask) | (correctly_positioned_bits & mask); //110100
  return ret;
}

unsigned bitcount(unsigned x) {
  unsigned count = 0;
  for (; x; count++)
    x >>= 1;

  return count;
}

unsigned rightrot(unsigned x, int n) {
  unsigned bits_to_rotate = getbits(x, n - 1, n);
  unsigned rotated_with_lost_bits = x >> n;
  unsigned bit_count = bitcount(x);
  unsigned rotated_x = setbits(rotated_with_lost_bits, bit_count - 1, n, bits_to_rotate);

  return rotated_x;
}
  
int main() {
  putd(rightrot(300, 3)); // 293
  putd(rightrot(685, 5)); // 437
  return 0;
}
