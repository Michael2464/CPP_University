#include <iostream>
#define написать(x) std::cout << x << '\n'
#define написать2(x1, x2) std::cout << x1 << x2 << '\n'
#define главная int main
#define вернуть return
#define спросить(x) std::cin >> x
#define число int 


главная(){
  число в = 0;
  спросить(в);

  написать(в);

  вернуть 0;
}

