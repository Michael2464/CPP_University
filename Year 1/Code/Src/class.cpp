#include <iostream>
#include <cstdint>
#include <cmath>
#include <initializer_list>

class Calculator
{
public:
  // ADD INITIALIZED LIST (so that we can add as many data as we want)
  template <typename T>
  inline static T Add(const T &a, const T &b) { return a + b; }
  template <typename T>
  inline static T Add(const std::initializer_list<T> &data)
  {
    T result = (T)0;
    for (const auto &d : data)
      result += d;
    return result;
  }
  template <typename T>
  inline static T Multiply(const T &a, const T &b) { return a * b; }
  template <typename T>
  inline static T Multiply(const std::initializer_list<T> &data)
  {
    T result = (T)1;
    for (const auto &d : data)
      result *= d;
    return result;
  }
  template <typename T>
  inline static T Divide(const T &a, const T &b) { return a / b; }
  template <typename T>
  inline static T Substruct(const T &a, const T &b) { return a - b; }
  template <typename T>
  inline static T Substruct(const std::initializer_list<T> &data)
  {
    T result = (T)0;
    for (const auto &d : data)
      result -= d;
    return result;
  }
  template <typename T>
  inline static T Pow(const T &a, const T &b) { return pow(a, b); }

};

int main()
{
  std::cout << Calculator::Substruct({3.3f, 4.4f, 5.5f}) << '\n';
  std::cout << Calculator::Pow(3.3f, 4.4f);

  return 0;
}