#include "list.h"

#include <iostream>

// void List::insert(int number) {
//     list_.insert(std::upper_bound( list_.begin(), list_.end(), number), number);
// }

void List::insertAt(int index, int value) {
    auto it = list_.begin();
    std::advance(it, index);
    list_.insert(it, value);
}

int List::size() const {
    return list_.size();
}


void List::remove(int index) {
    auto it = list_.begin();
    
    while(index-- > 0) {
        ++it;
    }

    list_.erase(it);
}

void List::print() {

    for( int num : list_) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void List::insertFront(int value) {
    list_.push_front(value);
}

void List::insertBack(int value) {
    list_.push_back(value);
}

void List::removeFront() {
    if (!list_.empty()) {
        list_.pop_front();
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
