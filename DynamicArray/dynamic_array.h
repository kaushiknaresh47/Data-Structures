// dynamic_array.h
// Approximation of STL vector
// Kaushik Naresh

template <typename Type>
class DynamicArray{
public:
    DynamicArray(int maxSize);
    ~DynamicArray(){delete [] data;};

    bool insert(const Type& a);
    bool insert(const Type& a, const int pos);
    int find(const Type& a) const;
    bool remove(const Type& a);
    bool pop_back(Type& a);
    void print() const;
    void reverse();

    // Inline Methods
    Type get(int ind) const {return data[ind];};
    int size() {return a_size;};
    bool empty() {if (a_size) {return false;} else {return true;}};
private:
    Type* data;
    int a_size;
    int max_size;
};