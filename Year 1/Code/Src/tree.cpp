#include <iostream>
#include <cstdint>
#include <memory>

struct Node
{
  Node() = default;
  Node(int data, Node *left, Node *right)
      : m_Data(data), m_Left(left), m_Right(right) {}
  Node(int data)
      : m_Data(data), m_Left(nullptr), m_Right(nullptr) {}

  int m_Data = 0;
  std::unique_ptr<Node> m_Left = nullptr;
  std::unique_ptr<Node> m_Right = nullptr;
};

struct Node *newNode(int data)
{
  Node *newNode = new Node;

  newNode->m_Data = data;
  newNode->m_Left = nullptr;
  newNode->m_Right = nullptr;

  return newNode;
}

void preOrder(const std::unique_ptr<Node>& temp, bool newLine = true, int spaceBefore = 6, int spaceAfter = 3)
{
  // TODO: MAKE IT WORK WITL ANY AMOUNT OF TREE NODES 
  if (temp != nullptr)
  {
    std::string spaceBeforeStr = "";
    std::string spaceAfterStr = "";
    for(uint32_t i = 0; i < spaceBefore; i++)
      spaceBeforeStr += " ";
    for(uint32_t i = 0; i < spaceAfter; i++)
      spaceAfterStr += " ";

    std::cout << spaceBeforeStr << temp->m_Data;
    if(newLine)
      std::cout << '\n';
    
    
    preOrder(temp->m_Left, false, spaceBefore-2, 0);
    std::cout << spaceAfterStr;
    preOrder(temp->m_Right, true, 0, 0);
  }
}

void inOrder(const std::unique_ptr<Node>& temp)
{
  if (temp != NULL)
  {
    inOrder(temp->m_Left);
    std::cout << "  " << temp->m_Data;
    inOrder(temp->m_Right);
  }
}

void postOrder(const std::unique_ptr<Node>& temp)
{
  if (temp != NULL)
  {
    postOrder(temp->m_Left);
    postOrder(temp->m_Right);
    std::cout << "  " << temp->m_Data;
  }
}

int main()
{
  std::unique_ptr<Node> root = std::make_unique<Node>(1);
  root->m_Left = std::make_unique<Node>(2);
  root->m_Right = std::make_unique<Node>(3);
  root->m_Right->m_Right = std::make_unique<Node>(4);

  preOrder(root);
  
  return 0;
}