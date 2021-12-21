// stack.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>

#include "stack.h"

#define TEST

template <typename Type>
Stack<Type>::Stack() {
    m_size = MAX_SIZE;
    a_size = 0;
    data = new Type[m_size];
}

template <typename Type>
Stack<Type>::Stack(int max_size) {
    m_size = max_size;
    a_size = 0;
    data = new Type[m_size];
}

template <typename Type>
Stack<Type>::~Stack() {
    delete [] data;
}

// O(1)
template <typename Type>
void Stack<Type>:: push(const Type& a) {
    data[a_size] = a;
    a_size++;
}

// O(1)
template <typename Type>
void Stack<Type>:: pop(Type& a) {
    if (a_size == 0) return;
    a = data[a_size - 1];
    a_size--;
}

// O(1)
template <typename Type>
bool Stack<Type>::top(Type& a) {
    if (a_size == 0) return false;
    a = data[a_size -1];
}


#ifdef TEST
int main() {
    Stack<int> x;

    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);

    int a;
    x.pop(a);
    std::cout << a << std::endl; // 4

    x.pop(a);
    std::cout << a << std::endl; // 3

    x.pop(a);
    std::cout << a << std::endl; // 2

    x.pop(a);
    std::cout << a << std::endl; // 1

    return 0;
}
#endif