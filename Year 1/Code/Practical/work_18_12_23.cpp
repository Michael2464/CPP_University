#include <iostream>
#include <stdint.h>
#include <fstream>
#include <array>
#include <string>
#include <cmath>

void a16_5()
{
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
  if (read.is_open())
  {
    int i = 0;
    for (uint32_t i = 0; i < elements.size(); i++)
    {
      std::getline(read, str, ' ');
      int elem = std::stoi(str);
      middle += abs((float)elem);
      // std::cout << elem << '\n';
      elements[i] = std::stoi(str);
    }
  }
  middle = middle / (float)elements.size();
  // std::cout << middle << '\n';

  // New text file
  for (uint32_t i = 0; i < elements.size(); i++)
  {
    float elem = elements[i] < 0 ? (float)elements[i] / middle : (float)elements[i];
    write << elem << ' ';
  }

  write.close();
  read.close();
}

struct AEROFLOT
{
  std::string destination;
  std::string number;
  std::string type;
};

void b16_5()
{
  const uint32_t Amount = 3;
  std::ofstream write;
  std::ifstream read;
  write.open("file.txt");

  // Filling array
  for (uint32_t i = 0; i < Amount; i++)
  {
    AEROFLOT aero;

    std::cout << "Enter destination: ";
    std::getline(std::cin, aero.destination);
    write << aero.destination << '\n';

    std::cout << "Enter type: ";
    std::getline(std::cin, aero.type);
    write << aero.type << "\n";

    std::cout << "Enter number: ";
    std::getline(std::cin, aero.number);
    write << aero.number << "\n";

    std::cout << "-------------------------\n";
  }
  write.close();

  std::array<AEROFLOT, Amount> elements;
  read.open("file.txt");
  if (read.is_open())
  {
    for (uint32_t i = 0; i < Amount; i++)
    {
      std::string str;

      std::getline(read, str, '\n');
      std::cout << "Destination " << i+1 << ") " << str << '\n';
      elements[i].destination = str;

      std::getline(read, str, '\n');
      std::cout << "Type " << i+1 << ") " << str << '\n';
      elements[i].type = str;

      std::getline(read, str, '\n');
      std::cout << "Number " << i+1 << ") " <<  str << '\n';
      elements[i].number = str;
    }
    std::cout << "----------------------------\n";
  }
  read.close();

  // Type
  std::string type;
  std::cout << "Enter type to search: ";
  std::getline(std::cin, type, '\n');

  bool has = false;
  for(uint32_t i = 0; i < Amount; i++){
    if(elements[i].type == type){
      std::cout << "Destination: " << elements[i].destination << '\n';
      std::cout << "Number: " <<  elements[i].number << '\n';
      std::cout << "-------------------------\n";
      has = true;
    }
  }
  if(has==false)
    std::cout << "The Aeroflot with type '" << type << "' doesn't exist!\n"; 
}

int main()
{
  b16_5();

  return 0;
}