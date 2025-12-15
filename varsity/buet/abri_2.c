#include <stdio.h>

int main() {
  double num1, num2;
  char operator;

  scanf("%lf %lf %c", &num1, &num2, &operator);

  // printf("%c\n", operator);
  double result;
  switch (operator) {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = num1 * num2;
    break;
  case '/':
    if (num2 == 0.0) {
      printf("Nothing can be divided by 0!\n");
      return 1;
    }
    result = num1 / num2;
    break;
  default:
    printf("Operator not specified!\n");
    return 1;
  }
  printf("%0.2lf\n", result);
  return 0;
}