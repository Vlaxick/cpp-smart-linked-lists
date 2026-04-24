#pragma once
#include <iostream>
#include <memory>
#include "Node.h"

template <typename T>
class SingleLinkedList {
    std::shared_ptr<SingleNode<T>> head;
    int listSize;
    public:
    SingleLinkedList() : head(nullptr), listSize(0) {};
    ~SingleLinkedList() {
        while (head!=nullptr){
            removeFirst();
        }
    }
};