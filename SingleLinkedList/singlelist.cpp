// singlelist.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>
#include "singlelist.h"
#define TEST

template <typename Type>
SingleList<Type>::SingleList() {
    a_size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename Type>
SingleList<Type>::~SingleList() {
    Node* p = head;
    Node* n = head;
    while (n) {
        n = p->next;
        delete p;
        p = n;
    }
}

// O(1)
template <typename Type>
bool SingleList<Type>::insert(const Type& a) {
    Node* n = new Node;
    n->val = a;
    n->next = nullptr;
    if(!head) {
        head = n;
        a_size++;
        tail = n;
        return true;
    }
    tail->next = n;
    tail = n;
    a_size++;
    return true;
}

// O(N)
template <typename Type>
bool SingleList<Type>::insert(const Type& a, const int pos) {
    if (pos > a_size) {
        return false;
    }
    if (pos == a_size) {
        return insert(a);
    }
    Node* p = head;
    for(int i = 0; i < pos; i++){
        p = p->next;
    }
    Node* n = new Node;
    n->next = p->next;
    n->val = a;
    p->next = n;
    a_size++;
    return true;
}

// O(N)
template <typename Type>
int SingleList<Type>::find(const Type& a) const {
    if (a_size == 0) return -1;
    Node* p = head;
    int pos = 0;
    while(p) {
        if (p->val == a) return pos;
        pos++;
        p = p->next;
    }
    return -1;
}

// O(N)
template <typename Type>
bool SingleList<Type>::remove(const Type& a) {
    if (a_size == 0) return false;
    Node* p = head;
    Node* n = head;
    // case 1 first node
    if (head->val == a) {
        p = head;
        head = head->next;
        delete p;
        a_size--;
        return true;
    }
    // case 2 any other node
    n = head->next;
    while(n) {
        if (n->val == a) {
            p->next = n->next;
            delete n;
            a_size--;
            return true;
        } 
        p = n;
        n = n->next;
    }
    return false;
}

// O(N)
template <typename Type>
void SingleList<Type>::print() const {
    Node* p = head;
    while(p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
}

// O(N)
template <typename Type>
void SingleList<Type>::reverse() {
    if (a_size == 0) return;
    if (a_size == 1) return;
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    Node* temp = tail;
    tail = head;
    head = temp;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

// O(N)
template <typename Type>
bool SingleList<Type>::get(int ind, Type& a) const {
    if (ind > a_size) return false;
    Node* p = head;
    for(int i = 0; i < ind; i++) {
        p = p->next;
    }
    a = p->val;
    return true;
}

#ifdef TEST
int main() {
    SingleList<int> x;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.print();

    x.remove(3);
    x.reverse();

    x.print();
    return 0;
}
#endif