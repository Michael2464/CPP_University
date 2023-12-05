#include <iostream>
#include <cstdint>

template <typename T>
class Calculator
{
public:
  // ADD INITIALIZED LIST (so that we can add as many data as we want)
  Calculator() = default;
  Calculator(T a, T b)
      : m_A(a), m_B(b) {}
  
private:
  T m_A;
  T m_B;
};

int main()
{

  return 0;
}