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

    removeFirst(){
        if (head == nullptr) {throw std::runtime_error("List is empty");}
        head = head->next;
        if (head != nullptr) {
            head->prev.reset();
        }
        listSize--;
    }

    pushFront(T value) {
        auto newNode = std::make_shared<Node<T>>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        listSize++;
    }
};

    