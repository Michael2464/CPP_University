#include <iostream>
#include <cstdint>
#include <cmath>

float factorial(float n){
  float result = 1;
  for (float i = 1; i <=n; i+=1.0f){
    result *= i; 
  }
  return result;
}

float f(float n) {
  float result = 0;
  for (float i = 1; i <= n; i+=1.0f){
    result += 1 / sqrt(factorial(i) + 3.0f);
  }
  return result;
}

int main() {
  float eps = 0.001;
  float p = 1.0f;
  float s = 0.0f;
  float n = 1.0f;

  while(p > eps){
    p = (1.0f / sqrt(n*n + 4*n + 3)) * f(n);
    p *= (int)n%2 == 0 ? 1 : -1;
    s += p;
    n += 1.0f;
  }
  std::cout << "Result: " << s << '\n';

  return 0;
}