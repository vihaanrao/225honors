#include <list>

class List {
private:
    std::list<int> list_;
public:
    void insert(int number);
    void insertAt(int index, int value);
    int size() const;
    void remove(int index);
    void print();
    void insertFront(int value);
    void insertBack(int value);
    void removeFront();
    void removeBack();
    bool isEmpty() const;
};
