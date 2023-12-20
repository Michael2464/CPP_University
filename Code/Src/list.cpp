#include <iostream>
#include <vector>
#include <stdint.h>

struct List;

typedef std::vector<List*> ListArray;

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

void PrintList(List* head) {
  List* ptr = head;
  while(ptr->m_Next != nullptr){
    std::cout << ptr->m_Info << '\n';
    ptr = ptr->m_Next;
  }
  while(ptr->m_Prev != nullptr){
    std::cout << ptr->m_Info << '\n';
    ptr = ptr->m_Prev;
  }
  std::cout << ptr->m_Info;
}

void ConnectLists(ListArray& vector)
{
  for(size_t i = 0; i < vector.size()-1; i++){
    vector[i]->m_Next = vector[i+1];
  }
  for(size_t i = vector.size()-1; i > 0; i--){
    vector[i]->m_Prev = vector[i-1];
  }
}

int main()
{
  List l1(1);
  List l2(2);
  List l3(3);
  List l4(4);

  List l(92);

  ListArray arr{&l, &l1, &l2, &l3, &l4};

  ConnectLists(arr);

#if 0
  l.m_Prev = nullptr;
  l.m_Next = &l1;

  l1.m_Prev = &l;
  l1.m_Next = &l2;

  l2.m_Prev = &l1;
  l2.m_Next = &l3;

  l3.m_Prev = &l2;
  l3.m_Next = &l4;

  l4.m_Prev = &l3;
  l4.m_Next = nullptr;
#endif

  PrintList(&l);

  return 0;
}