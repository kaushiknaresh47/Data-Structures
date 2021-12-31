// heap.h
// Kaushik Naresh

#include <vector>


/*
 _ _ _ _ _ _ _ 
|1|2|3|4|5|6|7|
 - - - - - - -

 0 1 2 3 4 5 6

ind of left child  : (i*2) + 1
ind of right child : (i*2) + 2
parent node        : floor((i-1)/2)


        1
      /   \
    2       3
   / \     / \
  4   5   6   7

*/

template <typename Type>
class MaxHeap {
public:
    MaxHeap();

    bool top(Type& a) const;
    void pop();
    void insert(const Type& a);

    int size() const {return a_size;}
    bool empty() const {return a_empty;}
    
    void print() const;
    void printvec() const;
private:
    int a_size;
    bool a_empty;
    std::vector<Type> arr;
};