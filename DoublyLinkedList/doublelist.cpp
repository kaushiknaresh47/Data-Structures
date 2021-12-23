// doublelist.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>

#include "doublelist.h"

#define TEST

// O(1)
template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(){
    a_size = 0;
    head = nullptr;
    tail = nullptr;
}

// O(N)
template <typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList(){
    Node *p, *n;
    p = n = head;
    while(n) {
        n = p->next;
        delete p;
        p = n;
    }
}

// O(1)
template <typename Type>
void DoublyLinkedList<Type>::insert(const Type& a){
    if (a_size == 0) {
        Node* n = new Node;
        n->val = a;
        n->next = nullptr;
        n->prev = nullptr;
        tail = n;
        head = n;
        a_size++;
        return;
    }
    Node* n = new Node;
    n->val = a;
    n->next = nullptr;
    n->prev = tail;
    tail->next = n;
    tail = n;
    a_size++;
}

// O(N)
template <typename Type>
bool DoublyLinkedList<Type>::insert(const Type& a, int ind){
    if (ind > a_size) {
        return false;
    }
    if (ind == 0) {
        Node* p = head;
        Node* n = new Node;
        n->val = a;
        n->next = p;
        n->prev = nullptr;
        p->prev = n;
        head = n;
        a_size++;
        return true;
    }
    Node* p = head;
    for(int i = 0; i < ind; i++) {
        p=p->next;
    }
    Node* n = new Node;
    n->val = a;
    n->next = p;
    n->prev = p->prev;

    if (p->prev) p->prev->next = n;

    p->prev = n;
    a_size++;
    return true;
}

// O(N)
template <typename Type>
bool DoublyLinkedList<Type>::find(const Type& a) const{
    Node* p = head;
    while(p) {
        if (p->val == a) {
            return true;
        }
    }
    return false;
}

// O(N)
template <typename Type>
bool DoublyLinkedList<Type>::remove(const Type& a) {
    Node* p = head;
    while(p) {
        if (p->val == a) {
            if (p->prev) {
                p->prev->next = p->next;
            }
            if (p->next){
                p->next->prev = p->prev;
            }
            if (p == head) head = p->next;
            if (p == tail) tail = p->prev;
            a_size--;
            return true;
        }
        p = p->next;
    }
    return false;
}

/*
template <typename Type>
bool DoublyLinkedList<Type>::remove(int ind) {
    if (ind > a_size || empty()) return false;
    Node* p = head;
    for(int i = 0; i < ind; i++) {
        p = p->next;
    }
    if (p->prev) {
        p->prev->next = p->next;
    }
    if (p->next){
        p->next->prev = p->prev;
    }
    if (p == head) head = p->next;
    if (p == tail) tail = p->prev;
    a_size--;
    return true;
}
*/

template <typename Type>
bool DoublyLinkedList<Type>:: get(Type& a, int ind) const {
    if (ind > a_size || empty()) return false;
    Node* p = head;
    for(int i = 0; i < ind; i++) {
        p=p->next;
    }
    a = p->val;
    return true;
}

template <typename Type>
void DoublyLinkedList<Type>::reverse(){
    if (a_size <= 1) return;
    Node* c = head;
    Node* temp = tail;
    tail = head;
    head = temp;
    temp = nullptr;
    while (c) {
        temp = c->prev;
        c->prev = c->next;
        c->next = temp;
        c = c->prev;
    }
}

template <typename Type>
void DoublyLinkedList<Type>::print() const{
    Node* p = head;
    while(p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
}


#ifdef TEST
int main() {
    DoublyLinkedList<int> x;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(5);

    std::cout << "Full" << std::endl;
    x.print();

    std::cout << "No 3" << std::endl;
    x.remove(3);


    x.insert(5, 2);
    x.reverse();
    std::cout << "Reverse (no 3)" << std::endl;
    x.print();

    return 0;
}
#endif