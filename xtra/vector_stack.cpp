//
// Created by Adam Cardenas on 12/17/16.
//
#include <iostream>
#include "vector_stack.h"

template<typename A>
bool xtra::VectorStack<A>::empty() {
    return this->data_.size() == 0;
}

template<typename A>
A xtra::VectorStack<A>::peek() {
    return 0;
}

template<typename A>
A xtra::VectorStack<A>::pop() {
    return 0;
}

template<typename A>
A xtra::VectorStack<A>::push(A a) {
    return a;
}

template<typename A>
int xtra::VectorStack<A>::search(A a) {
    return a;
}

template<typename A>
xtra::VectorStack<A>::VectorStack() {
    std::vector<A> a;
    this->data_ = a;
}

template<typename A>
xtra::VectorStack<A>::VectorStack(A ls[]) {
    std::vector<A> a(ls, ls + sizeof(ls) + sizeof(ls[0]));
    this->data_ = a;
}

template<typename A>
xtra::VectorStack<A>::~VectorStack() {
    std::vector<A>().swap(this->data_);
}
