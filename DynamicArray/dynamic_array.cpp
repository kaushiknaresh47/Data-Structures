// dynamic_array.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>
#include "dynamic_array.h"
#define TEST

template <typename Type>
DynamicArray<Type>::DynamicArray(int maxSize){
    a_size = 0;
    data = new Type[maxSize];
}

template <typename Type>
bool DynamicArray<Type>::insert(const Type& a) {
    if (a_size == max_size) return false;
    data[a_size] = a;
    a_size++;
    return true;
}

template <typename Type>
bool DynamicArray<Type>::insert(const Type& a, const int pos) {
    if (pos >= a_size) return false;
    data[pos] = a;
    return true;
}

template <typename Type>
int DynamicArray<Type>::find(const Type& a) const {
    for(int i = 0; i < a_size; i++) {
        if (data[i] == a) {
            return i;
        }
    }
    return -1;
}

template <typename Type>
bool DynamicArray<Type>::remove(const Type& a) {
    int ind = find(a);
    if (ind > -1) {
        for(int i = ind; i < a_size -1; i++){
            data[i] = data[i+1];
        }
        data[a_size-1] == 0;
        a_size--;
        return true;
    } else return false;
}

template <typename Type>
bool DynamicArray<Type>::pop_back(Type& a) {
    if (a_size == 0) return false;
    a = data[a_size-1];
    data[a_size] = 0;
    a_size--;
    return true;
}


template <typename Type>
void DynamicArray<Type>::print() const {
    for(int i = 0; i < a_size; i++){
        std::cout << data[i] << std::endl;
    }
}

template <typename Type>
void DynamicArray<Type>::reverse() {
    if (a_size == 0) return;
    int temp;
    for(int i = 0; i < floor(a_size/2); i++) {
        temp = data[a_size - 1 - i];
        data[a_size - 1 - i] = data[i];
        data[i] = temp;
    }
}

#ifdef TEST
// Testing
int main() {
    int a = 4;
    DynamicArray<int> x(a);
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(5);
    x.reverse();
    x.print();
    std::cout << "popping last item" << std::endl;
    int y = 0;
    x.pop_back(y);
    std::cout << y << std::endl << std::endl;
    x.print();
    return 0;
}
#endif