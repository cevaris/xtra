//
// Created by Adam Cardenas on 12/17/16.
//
#include <iostream>
#include "vector_stack.h"


template<typename A>
bool xtra::VectorStack<A>::empty() {
    return curr_size_ == 0;
}

template<typename A>
A xtra::VectorStack<A>::peek() {
    if (empty()) {
        throw EmptyStackException();
    }

    return data_[curr_size_ - 1];
}

template<typename A>
A xtra::VectorStack<A>::pop() {
    if (empty()) {
        throw EmptyStackException();
    }

    A curr_value = data_[curr_size_ - 1];
    if (curr_size_ > 0) {
        curr_size_--;
    }

    return curr_value;
}

template<typename A>
A xtra::VectorStack<A>::push(A a) {

    data_.push_back(a);
    curr_size_++;

    return a;
}

template<typename A>
int xtra::VectorStack<A>::search(A a) {
    auto it = std::find(data_.begin(), data_.end(), a);
    if (it == data_.end()) {
        return -1;

    } else {
        // index value in 1-based not 0-based
        return std::distance(data_.begin(), it) + 1;
    }
}

