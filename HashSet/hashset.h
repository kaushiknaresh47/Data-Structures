// hashset.h
// Approximation of unordered_set
// Kaushik Naresh

#include <functional>
#include <vector>
#define MAXSIZE 250

template <typename Type>
class HashSet {
public:
    HashSet();

    bool insert(const Type& a);
    bool remove(const Type& a);
    bool find(const Type& a);

    void print() const;

    // inline functions
    int size() {return a_size;}
    bool empty() {return c_empty;}
    int hasher(const Type& a) {return hashf(a) % 250;}
private:
    std::hash<Type> hashf;
    bool c_empty;
    int a_size;
    struct Bucket{
        bool inUse;
        std::vector<Type> vals;
    };
    Bucket bucks[MAXSIZE];
};