// dynamic_array.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>
#include "dynamic_array.h"

template <typename Type>
DynamicArray<Type>::DynamicArray(const Type* a){
    size = 1;
    max_size = 1;
    data = *a;
}

template <typename Type>
Type DynamicArray<Type>::get(int ind) const{
    return data;
}

template <typename Type>
void DynamicArray<Type>::print() const {
    std::cout << this->get(1) << std::endl;
}






// Testing
int main() {
    int a = 4;
    DynamicArray<int> x(&a);
    x.print();
    return 0;
}
