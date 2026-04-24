#pragma once
#include <iostream>
#include <memory>

template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;

    Node(T value) : data(value), next(nullptr), prev() {}
    ~Node(){
        //std::cout << "Node was destroyed" << std::endl;
    }
};

template <typename T>
struct SingleNode {
    T data;
    std::shared_ptr<SingleNode<T>> next;

    SingleNode(T value) : data(value), next(nullptr) {}
    ~SingleNode(){
        //std::cout << "Node was destroyed" << std::endl;
    }
};