#include <stdio.h>

int main() {
  int number;
  scanf("%d", &number);

  int largest, second_largest;
  // Default values
  largest = second_largest = -1;

  int temp = number;
  while (temp) {
    int cur_number = temp % 10;
    temp /= 10;

    if (largest < cur_number) {
      largest = cur_number;
    }
  }
  temp = number;

  // Second search
  while (temp) {
    int cur_number = temp % 10;
    temp /= 10;

    if (second_largest < cur_number && cur_number != largest) {
      second_largest = cur_number;
    }
  }

  if (second_largest == -1) {
    printf("All numbers are equal!");
  } else {
    printf("%d\n", second_largest);
  }
  return 0;
}