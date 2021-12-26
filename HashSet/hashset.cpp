// hashset.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "hashset.h"

#define TEST

template <typename Type>
HashSet<Type>::HashSet() {
    c_empty = true;
    a_size = 0;
    for(int i = 0; i < MAXSIZE; i++) {
        bucks[i].inUse = false;
    }

}


template <typename Type>
bool HashSet<Type>::insert(const Type& a) {
    int hashval = hasher(a);
    if (!bucks[hashval].inUse) {
        bucks[hashval].vals.push_back(a);
        bucks[hashval].inUse = true;
        a_size++;
        c_empty = false;
        return true;
    } else if (std::find(bucks[hashval].vals.begin(), bucks[hashval].vals.end(), a) == bucks[hashval].vals.end()) {
        bucks[hashval].vals.push_back(a);
        a_size++;
        c_empty = false;
        return true;
    }
    return false;
}

template <typename Type>
bool HashSet<Type>::remove(const Type& a) {
    int hashval = hasher(a);
    if (std::find(bucks[hashval].vals.begin(), bucks[hashval].vals.end(), a) == bucks[hashval].vals.end()) {
        return false; // does not exist
    } else {
        bucks[hashval].vals.erase(std::remove(bucks[hashval].vals.begin(), bucks[hashval].vals.end(), a), bucks[hashval].vals.end());
        if (bucks[hashval].vals.empty()) {bucks[hashval].inUse = false;}
        a_size--;
        if (a_size == 0) c_empty = true;
        return true;
    }
}

template <typename Type>
bool HashSet<Type>::find(const Type& a) {
    int hashval = hasher(a);
    if (std::find(bucks[hashval].vals.begin(), bucks[hashval].vals.end(), a) == bucks[hashval].vals.end()) {
        return false; // does not exist
    }
    return true;
}

template <typename Type>
void HashSet<Type>::print() const {
    int i = 0;
    int j = 0;
    while(i < a_size && j < MAXSIZE) {
        if (bucks[j].inUse) {
            for(int k = 0; k < bucks[j].vals.size(); k++) {
                std::cout << bucks[j].vals[k] << std::endl;
                i++;
            }
            j++;
        } else {
            j++;
        }
    }
}


#ifdef TEST
int main() {
    HashSet<std::string> x;
    x.insert("1");
    x.insert("abc");
    x.print();
    x.remove("1");
    std::cout << "1 is removed" << std::endl;
    x.print();
    return 0;
}
#endif