// dynamic_array.h
// Kaushik Naresh

template <typename Type>
class DynamicArray{
public:
    DynamicArray(const Type* a);
    //~DynamicArray();

    //void insert(const Type a);
    //void insert(const Type a, const int pos);

    //void remove(const Type a);

    //void reverse();

    //bool find(const Type a) const;
    Type get(int ind) const;
    
    //int size();
    //bool empty();

    void print() const;
private:
    Type data;
    int size;
    int max_size;
};