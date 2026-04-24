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

    void pushBack (T value) {
        if (head == nullptr) {
            pushFront(value);
            return;
        }
        auto newNode = std::make_shared<SingleNode<T>>(value);
        auto current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        listSize++;
    }

    void removeLast(){
        if (head == nullptr) {throw std::runtime_error("List is empty");}
        if (head->next == nullptr) {
            removeFirst();
            return;
        }
        auto current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        current->next = nullptr;
        listSize--;
    }

    T at(int index) {
        if (index < 0 || index >= listSize){
            throw std::out_of_range ("Index out of range");
        }
        auto current = head;
        for (int i = 0; i<index; i++){
            current = current->next;
        }
        return current->data;
    }
};