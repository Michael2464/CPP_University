#include <iostream>
#include <cstdint>

#include <ctime>
#include <array>

typedef std::array<int, 10> Array;

void PrintArray(const Array& arr){
    for (uint32_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int main(){
    srand(0);
    Array arr;
    
    
    for (uint32_t i = 0; i < arr.size(); i++)
        arr[i] = rand() % 20;
    PrintArray(arr);
    
    for (uint32_t i = 0; i < arr.size(); i++){
        int min = arr[i];
        int index = i;
        for (uint32_t j = i; j < arr.size(); j++){
            if(arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        int save = arr[i];
        arr[i] = min;
        arr[index] = save;
    }    

    PrintArray(arr);

    return 0;
}