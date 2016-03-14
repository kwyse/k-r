// 3.1 : Binary search

#include <time.h>
#include "header.h"

int binsearch(int x, int v[], int n) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }

  return -1;
}

int mybs(int x, int v[], int n) {
  int low = 0, high = n - 1, mid = (low + high) / 2;
  while (low <= high && v[mid] != x) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else {
      low = mid + 1;
    }
  }

  if (v[mid] == x)
    return mid;
  else
    return -1;
}

int main() {
  int input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
  putd(binsearch(5, input, 15));
  putd(binsearch(9, input, 15));
  putd(mybs(5, input, 15));
  putd(mybs(9, input, 15));

  clock_t binsearch_clock = clock();
  binsearch(5, input, 15);
  binsearch_clock = clock() - binsearch_clock;

  clock_t mybs_clock = clock();
  mybs(5, input, 15);
  mybs_clock = clock() - mybs_clock;

  printf("binsearch time:\t%0.6fs\nmybs time:\t%0.6fs\n",
	 ((float) binsearch_clock) / CLOCKS_PER_SEC * 1000,
	 ((float) mybs_clock) / CLOCKS_PER_SEC * 1000);

  return 0;
}
