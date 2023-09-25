#include "vector.h"
#include <iostream>

void List::insert(int number) {

    // list_.insert(std::upper_bound( list_.begin(), list_.end(), number), number);
    auto it = list_.begin();
    while (it != list_.end() && (*it < number)) {
        ++it;
    }
    list_.insert(it,number);
    }

void List::insertAt(int index, int value) {
    list_.insert(list_.begin() + index, value);
}

void List::remove(int index) {
    auto it = list_.begin();

    // it += index;
    while(index-- > 0) {
        ++it;
    }

    list_.erase(it);
}

int List::size() const {
    return list_.size();
}

void List::print() {

    for( int num : list_) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void List::insertFront(int value) {
    list_.insert(list_.begin(), value);
}

void List::insertBack(int value) {
    list_.push_back(value);
}

void List::removeFront() {
    if (!list_.empty()) {
        list_.erase(list_.begin());
    }
}

void List::removeBack() {
    if (!list_.empty()) {
        list_.pop_back();
    }
}

bool List::isEmpty() const {
    return list_.empty();
}
