// singlelist.h
// Kaushik Naresh

template <typename Type>
class SingleList {
public:
    SingleList();
    ~SingleList();

    bool insert(const Type& a);
    bool insert(const Type& a, const int pos);
    int find(const Type& a) const;
    bool remove(const Type& a);
    void print() const;
    void reverse();
    bool get(int ind, Type& a) const;

    // Inline Methods
    int size() {return a_size;};
    bool empty() {if (a_size) {return false;} else {return true;}};
private:
    struct Node {
        Type val;
        Node* next;
    };
    int a_size;
    Node* head;
    Node* tail;
};