// queue.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>

#include "queue.h"

#define TEST

template <typename Type>
Queue<Type>::Queue() {
    a_size = 0;
    head = tail = nullptr;
}

template <typename Type>
Queue<Type>::~Queue() {
    Node* n = head;
    Node* p = head;
    while(n) {
        n = p->next;
        delete p;
        p = n;
    }
}


// O(1)
template <typename Type>
void Queue<Type>::push(const Type& a) {
    if (a_size == 0) {
        Node* n = new Node;
        n->next = nullptr;
        head = n;
        tail = n;
        n->val = a;
        a_size++;
        return;
    }
    Node* n = new Node;
    n->next = nullptr;
    n->val = a;
    tail->next = n;
    tail = n;
    a_size++;
}

// O(1)
template <typename Type>
void Queue<Type>::pop(Type& a) {
    if (a_size == 0) return;
    if (a_size == 1) {
        a = head->val;
        Node* p = head;
        delete p;
        head = tail = nullptr;
        a_size--;
        return;
    }
    Node* p = head;
    head = head->next;
    a = p->val;
    delete p;
    a_size--;
}

// O(1)
template <typename Type>
void Queue<Type>::front(Type& a) const{
    if (a_size == 0) return;
    a = head->val;
}

// O(1)
template <typename Type>
void Queue<Type>::back(Type& a) const{
    if (a_size == 0) return;
    a = tail->val;
}

#ifdef TEST
int main() {
    Queue<int> x;
    std::cout << "start test" << std::endl;
    x.push(1);
    std::cout << "pushed 1" << std::endl;
    x.push(2);
    x.push(3);
    x.push(4);

    int a;
    x.front(a);
    std::cout << a << std::endl; // 1
    x.back(a);
    std::cout << a << std::endl; // 4

    x.pop(a);
    std::cout << a << std::endl; // 1

    x.pop(a);
    std::cout << a << std::endl; // 2

    x.pop(a);
    std::cout << a << std::endl; // 3

    x.pop(a);
    std::cout << a << std::endl; // 4

    return 0;
}
#endif