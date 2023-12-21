#include <iostream>
#include <stdint.h>
#include <vector>

template<typename T>
class Stack
{
public:
  Stack() = default;
  Stack(uint32_t size) { m_Elements.resize(size); }

  uint32_t size(){
    return (uint32_t)m_Elements.size();
  }

  void push(const T& elem){
    m_Elements.emplace_back(elem);
  }

  void pop(){
    if(!this->empty())
      m_Elements.pop_back();
  }

  bool empty(){
    return m_Elements.empty();
  }

  T get(){
    return m_Elements[m_Elements.size() - 1];
  }

private:
  std::vector<T> m_Elements;
};

int main()
{
  Stack<int> stack(10);

  for(uint32_t i = 0; i < 10; i++){
    stack.push(i);
  }

  for(uint32_t i = 0; i < stack.size(); i++){
    std::cout << stack.get() << '\n';
    stack.pop();
  }


  return 0;
}