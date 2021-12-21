// queue.h
// Kaushik Naresh

template <typename Type>
class Queue {
public:
    Queue();
    ~Queue();

    void push(const Type& a);
    void pop(Type& a);
    void front(Type& a) const;
    void back(Type& a) const;

    // Inline methods
    int size() {return a_size;};

private:
    struct Node {
        Type val;
        Node* next;
    };
    
    Node* head;
    Node* tail;
    int a_size;
};