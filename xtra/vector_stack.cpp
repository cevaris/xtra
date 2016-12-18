//
// Created by Adam Cardenas on 12/17/16.
//
#include <iostream>
#include "vector_stack.h"


template<typename A>
bool xtra::VectorStack<A>::empty() {
    return data_.size() == 0;
}

template<typename A>
A xtra::VectorStack<A>::peek() {
    return 0;
}

template<typename A>
A xtra::VectorStack<A>::pop() {
    if (empty()) {
        throw EmptyStackException();
    }
    return 0;
}

template<typename A>
A xtra::VectorStack<A>::push(A a) {
    data_.push_back(a);
    next_index_++;
    return a;
}

template<typename A>
int xtra::VectorStack<A>::search(A a) {
    return a;
}

