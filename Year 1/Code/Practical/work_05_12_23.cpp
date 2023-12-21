#include <iostream>
#include <cstdint>
#include <cmath>

// Это просто функция, возвращающая факториал числа
// типо factorial(3) = 3*2*1 = 6 
float factorial(float n){
  float result = 1;
  for (float i = 1; i <=n; i+=1.0f){
    result *= i; 
  }
  return result;
}

// Это какая-то отдельная функция, которую я использую в основной
// в твоей задачи вроде такого нет, можешь удалить
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
    p = (1.0f / sqrt(n*n + 4*n + 3)) * f(n); // вот тут основная функция 
    p *= (int)n%2 == 0 ? 1 : -1; // У меня менялся знак в зависимости от четности, поэтому я это тут проверял
    s += p;
    n += 1.0f;
  }
  std::cout << "Result: " << s << '\n';

  return 0;
}