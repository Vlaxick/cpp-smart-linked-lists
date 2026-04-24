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

    pushBack (T value) {
        if (head == nullptr) {
            pushFront(value);
            return;
        }
        auto newNode = std::make_shared<Node<T>>(value);
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
        listSize++;
    }

    removeLast(){
        if (head == nullptr) {throw std::runtime_error("List is empty");}
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev.lock();
            tail->next = nullptr;
        }
        listSize--;
    }

    at(int index) {
        if (index >= listSize){
            throw std::out_of_range ("Index out of range");
        }
        auto current = head;
        for (int i = 0; i<index; i++){
            current = current->next;
        }
        return current->data;
    }

    insertAt(int index, T value) {
       if (index < 0 || index > listSize) {throw std::out_of_range("Index out of range");}
       if (index == 0) {
           pushFront(value);
           return;
       }
       if (index == listSize) {
           pushBack(value);
           return;
       }
       auto current = head;
       for (int i = 0; i < index; i++) {
           current = current->next;
       }
         auto newNode = std::make_shared<Node<T>>(value);
         newNode -> next = current;
         newNode -> prev = current->prev;
         current->prev.lock()->next = newNode;
         current->prev = newNode;
         listSize++;
        }

};

    