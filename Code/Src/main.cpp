#include <iostream>

struct List {
  List(int data)
  : m_Info(data) {};
  List(int data, List* prev)
  : m_Info(data), m_Prev(prev) {};
  List(int data, List* prev, List* next)
  : m_Info(data), m_Prev(prev), m_Next(next) {};

  int m_Info = 0;
  List* m_Prev = nullptr;
  List* m_Next = nullptr;
};


int main()
{
  std::cout << "Lists\n\n";

  List l1(1);
  List l2(2);
  List l3(3);
  List l4(4);

  List l(92);

  
  l.m_Prev = &l4;
  l.m_Next = nullptr;

  l4.m_Prev = &l3;
  l4.m_Next = &l;

  l3.m_Prev = &l2;
  l3.m_Next = &l4;

  l2.m_Prev = &l1;
  l2.m_Next = &l3;

  l1.m_Prev = nullptr;
  l1.m_Next = &l2;

  List* ptr = &l;
  while(ptr->m_Prev != nullptr){
    std::cout << ptr->m_Info << ' ';
    ptr = ptr->m_Prev;
  }
  while(ptr->m_Next != nullptr){
    std::cout << ptr->m_Info << ' ';
    ptr = ptr->m_Next;
  }
  std::cout << ptr->m_Info;

  return 0;
}