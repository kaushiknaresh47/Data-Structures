// doublelist.h
// Approximation of STL List
// Kaushik Naresh

template <typename Type>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert(const Type& a );
    bool insert(const Type& a, int ind);

    bool find(const Type& a) const;
    bool remove(const Type& a);

    bool get(Type& a, int ind) const;

    void reverse();
    void print() const;

    // inline methods
    int size() {return a_size;};
    bool empty() {if (a_size == 0) return false; else return true;};
private:
    struct Node {
        Type val;
        Node* next;
        Node* prev;
    };
    int a_size;
    Node* head;
    Node* tail;
};