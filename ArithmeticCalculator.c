#include <stdio.h>

 float calculate(float a, float b, char op) {
 switch(op) {
  case '+': return a + b;
  case '-': return a - b;
  case '*': return a * b;
  case '/': if(b != 0) return a / b;
 }
 return 0; // Return 0 if operation is not recognized or division by zero
 }
 
 int main() {
 float result = calculate(5, 3, '+');
 printf("The result is %f\n", result);
 return 0;
}
