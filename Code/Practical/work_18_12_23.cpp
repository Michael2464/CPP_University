#include <iostream>
#include <stdint.h>
#include <ctime>
#include <fstream>
#include <random>
#include <string>
#include <array>
#include <cmath>

void a16_5(){
  srand(time(0));

  std::ifstream read;
  std::ofstream write;
  read.open("file.txt");
  write.open("file_output.txt");

#if 0
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> distr(-10, 10);

  // Writing to file 
  const uint32_t Size = 20;
  for(uint32_t i = 0; i < Size; i++){
    int randomNumber = distr(eng);
    write << randomNumber << ' ';
  }
#endif

  std::array<int, 20> elements;
  std::string str;
  float middle = 0.0f; 
  if(read.is_open())
  {
    int i = 0;
    for(uint32_t i = 0; i < elements.size(); i++) {
      std::getline(read, str, ' ');
      int elem = std::stoi(str);
      middle += abs((float)elem);
      //std::cout << elem << '\n';
      elements[i] = std::stoi(str);
    }
  }
  middle = middle / (float)elements.size();
 // std::cout << middle << '\n';

  // New text file
  for(uint32_t i = 0; i < elements.size(); i++){
    float elem = elements[i] < 0 ? (float)elements[i]/middle : (float)elements[i];
    write << elem << ' ';
  }

  write.close();
  read.close();
}

struct AEROFLOT{
  std::string destination;
  int number;
  std::string type;
};

void b16_5()
{
  const int Amount = 7;
  // Filling array
  for(uint32_t i = 0; i < Amount; i++)
  {
    AEROFLOT aero;
    std::cout << "Enter destination: ";
    std::getline(std::cin, aero.destination);
    std::cout << "Enter number: ";
    std::cin >> aero.number;
    std::cout << "Enter type(string): ";
    std::getline(std::cin, aero.type);
  }
  
}


int main() {
  b16_5();
  
  return 0;
}