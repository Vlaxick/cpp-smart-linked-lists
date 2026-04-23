#pragma once
#include <iostream>
#include <memory>
#include "Node.h"

template <typename T>
class DoubleLinkedList {
    std::shared_ptr<Node<T>> head;
    int listSize;
    std::shared_ptr<Node<T>> tail;
    public:
    DoubleLinkedList() : head(nullptr), listSize(0) {};
    ~DoubleLinkedList() {
        while (head!=nullptr){
            removeFirst();
        }
    }
};

    