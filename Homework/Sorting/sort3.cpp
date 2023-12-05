#include <iostream>
#include <ctime>
#include <array>
#include <cstdint>

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

    for (uint32_t i = 1; i < arr.size(); i++){
        for (uint32_t j = i; j > 0; j--){
            if(arr[j] < arr[j-1]){
                int save = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = save;
            }
        }
    }    

    PrintArray(arr);

    return 0;
}