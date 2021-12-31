// heap.cpp
// Kaushik Naresh

#include <iostream>
#include <stdio.h>


#include "heap.h"

#define TEST

template <typename Type>
MaxHeap<Type>::MaxHeap() {
    a_size = 0;
    a_empty = true;
}

// O(1)
template <typename Type>
bool MaxHeap<Type>::top(Type& a) const {
    if (a_size == 0) {
        return false;
    }
    a = arr[0];
    return true;
}

template <typename Type>
void MaxHeap<Type>::pop() {
    a_size--;
    if (a_size == 0) return ; // special case
    Type temp = arr[a_size];
    arr[a_size] = arr[0];
    arr[0] = temp;
    if (a_size == 1) return; // special case

    if (a_size == 2) { // special case
        if (arr[0] < arr[1]) {
            Type temp = arr[1];
            arr[1] = arr[0];
            arr[0] = temp;
            return;
        }
    }

    double i = 0;
    double j1 = (i*2) + 1;
    double j2 = (i*2) + 2; 

    while ((i <= (a_size -1)) && (j1 <= (a_size -1)) && (j2 <= (a_size -1))) {
        if (arr[j1] > arr[j2]) {
            if (arr[i] < arr[j1]) {
                temp = arr[j1];
                arr[j1] = arr[i];
                arr[i] = temp;

                i = j1;
                j1 = (i*2) + 1;
                j2 = (i*2) + 2; 
            } else return;
        } else {
            if (arr[i] < arr[j2]){
                temp = arr[j2];
                arr[j2] = arr[i];
                arr[i] = temp;

                i = j2;
                j1 = (i*2) + 1;
                j2 = (i*2) + 2; 
            } else return;

        }
    }
}

template <typename Type>
void MaxHeap<Type>::insert(const Type& a) {
    arr.push_back(a);
    a_size++;
    a_empty = false;

    if (a_size == 1) return;

    double j = a_size - 1;
    double i = floor((j - 1)/2);
    Type temp;
    do {
        if (arr[j] > arr[i]) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j = i;
        i = floor((j - 1)/2);
    } while (i >= 0 && j >= 0);

}

template <typename Type>
void MaxHeap<Type>:: print() const {
    for(int i = 0; i < a_size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

template <typename Type>
void MaxHeap<Type>:: printvec() const {
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }
}

#ifdef TEST
int main() {
    MaxHeap<int> h;
    h.insert(50);
    h.insert(10);
    h.insert(12);
    h.insert(5);
    h.insert(3);
    h.insert(1);
    h.insert(37);
    h.insert(2);
    h.insert(71);
    h.insert(1231);
    h.insert(0);
    h.insert(32);
    h.insert(73);
    h.insert(81);
    h.insert(17);
    h.insert(22);

    for(int i = 0; i < 16; i++) {
        h.pop();
    }

    h.printvec();    

    
    
    
    return 0;
}

#endif