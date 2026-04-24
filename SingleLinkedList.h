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

    void removeFirst(){
        if (head == nullptr) {throw std::runtime_error("List is empty");}
        head = head->next;
        listSize--;
    }

    void pushFront(T value) {
        auto newNode = std::make_shared<SingleNode<T>>(value);
        newNode->next = head;
        head = newNode;
        listSize++;
    }
};