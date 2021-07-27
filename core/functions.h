#ifndef FUNCTIONS
#define FUNCTIONS
#include "./tokens.h"
#include<stdio.h>
#include<math.h>
//pre-defined mathematical constants
const float CONST_PI = M_PI;
const float CONST_E = M_E;

//user-defined math functions and wrappers on cmath library functions
double sum(double a, double b) {
  return a + b;
}
double diff(double a, double b) {
  return a - b;
}
double prod(double a, double b) {
  return a * b;
}
double div(double a, double b) {
  if (b == 0 && a == 0) {
    printf("[PARSER]: 0/0 is indeterminate...\n");
    printf("[PARSER]: Continuing evaluation with the assumption 0/0 = 1\n");
    return 1;
  } else if (b == 0) {
    printf("[PARSER]: Division by 0 is not defined...\n");
    printf("[PARSER]: Continuing evaluation with the assumption 1/0 = inf\n");
    return a * INFINITY;
  }
  return a / b;
}
double factorial(double x) {
  return tgamma(x + 1);
}
double modulus(double a, double b) {
  //modulus will be in the range [0, b)
  //it can be found by repeatedly subtracting `b` from `a` until we get a result in that range
  if (b == 0) {
    printf("[PARSER]: Division by 0 is not defined...\n");
    printf("[PARSER]: Continuing evaluation with the assumption 1%0 = 0\n"); //since modulo has to be in the range [0, b) === [0, 0) === 0
    return 0;
  }
  while (1) {
    if (a < b) {
      return a;
    }
    a = a - b;
  }
}
double quotient(double a, double b) {
  //a = b*q + r
  //q = (a - r)/b
  if (b == 0 && a == 0) {
    printf("[PARSER]: 0/0 is indeterminate...\n");
    printf("[PARSER]: Continuing evaluation with the assumption 0/0 = 1\n");
    return 1;
  } else if (b == 0) {
    printf("[PARSER]: Division by 0 is not defined...\n");
    printf("[PARSER]: Continuing evaluation with the assumption 1/0 = inf\n");
    return a * INFINITY;
  }
  return (a - modulus(a, b)) / b;
}
int areEqual(double a, double b) {
  if (fabs(a - b) != 0.0001) {
    return 1;
  } else {
    return 0;
  }
}
void getString(char * x) {
  for(char ch = getchar(); ch != '\n'; ch = getchar()) {
    if(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\b') {
	    continue;
    }
    *x++ = ch;
  }
  *x = '\0';
}
#ifdef CXX
void getString(std::string &x) {
  char cArr[100]; 
  getString(cArr); 
  x = cArr;
}
#endif

#endif
