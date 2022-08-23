#include <stdio.h>

float operation(float a, float b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b == 0) {
        printf("Error: division by zero\n");
        return 1;
      }
      return a / b;
    default:
      return 0;
  }
}

int main() {
  float a, b;
  char op;
  printf("Enter the operation to be realized: ");
  scanf("%f %c %f", &a, &op, &b);
  printf("%.2f %c %.2f = %.2f\n", a, op, b, operation(a, b, op));
  return 0;
}