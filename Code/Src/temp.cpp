#include <iostream>
#define написать1(x) std::cout << x << '\n'
#define написать2(x1, x2) std::cout << x1 << x2 << '\n'
#define главная int main
#define вернуть return
#define спросить(x) std::cin >> x
#define число int 


главная(){
  число в = 0;
  спросить(в);

  написать1(в);

  вернуть 0;
}