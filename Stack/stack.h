// stack.h
// Kaushik Naresh

#define MAX_SIZE 100

template <typename Type>
class Stack {
public:
    Stack();
    Stack(int max_size);
    ~Stack();

    void push(const Type& a);
    void pop(Type& a);
    bool top(Type& a);
private:
    int a_size;
    int m_size;
    Type* data;
};