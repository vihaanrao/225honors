#include <vector>

class List {
private:
    std::vector<int> list_;
public:
    void insert(int number);
    void insertAt(int index, int value);
    void remove(int index);
    void print();
    int size() const;
    void insertFront(int value);
    void insertBack(int value);
    void removeFront();
    void removeBack();
    bool isEmpty() const;
};
