// binarysearch.cpp
// Kaushik Naresh

#include <stdio.h>
#include <iostream>
#include <cassert>

#define TEST

template <typename Type>
bool recursiveBinarySearch(Type* arr, int start, int end, const Type& val) {
    // assumptions:
    //      arr is sorted
    //      0 <= start <= end <= size-1
    //      (where size is the no. of elements in arr)
    //      Type has a comparison defined
    if (start == end) {
        if (arr[start] == val) return true;
        return false;
    }
    int mid = floor((start + end)/2);
    if (val > arr[mid]) {
        return recursiveBinarySearch(arr, mid+1, end, val);
    } else if (val < arr[mid]) {
        return recursiveBinarySearch(arr, start, mid-1, val);
    } else return true;
};

template <typename Type>
bool iterativeBinarySearch(Type* arr, int start, int end, const Type& val) {
    // assumptions:
    //      arr is sorted
    //      0 <= start <= end <= size-1
    //      (where size is the no. of elements in arr)
    //      Type has a comparison defined
    int mid;
    while(start <= end) {
        mid = floor((start + end)/2);
        if (val < arr[mid]){
            end = mid-1;
        } else if (val > arr[mid]) {
            start = mid+1;
        } else return true;

        if (start == end) {
            if (arr[start] == val) return true;
        }
    }
    return false;
};


#ifdef TEST
int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i++) {
        assert(recursiveBinarySearch(a,0,9,a[i]));
        assert(iterativeBinarySearch(a,0,9,a[i]));
    }
    assert(!recursiveBinarySearch(a,0,9,0));
    assert(!recursiveBinarySearch(a,0,9,1212));
    assert(!iterativeBinarySearch(a,0,9,0));
    assert(!iterativeBinarySearch(a,0,9,1212));

    return 0;
}
#endif

