//
// Created by Adam Cardenas on 12/20/16.
//

#include "array_circular_queue.h"

template<typename E, size_t N>
bool xtra::ArrayCircularQueue<E, N>::add(E e) {
    if (size() == N) {
        throw IllegalStateException("queue is full");
    }

    data_[ptr_write_] = e;
    circular_inc(ptr_write_);
    curr_size_++;

    return true;
}

template<typename E, size_t N>
bool xtra::ArrayCircularQueue<E, N>::is_empty() {
    return size() == 0;
}

template<typename E, size_t N>
unsigned int xtra::ArrayCircularQueue<E, N>::size() {
    return curr_size_;
}

template<typename E, size_t N>
void xtra::ArrayCircularQueue<E, N>::clear() {
    data_ = std::array<E, N>();
    curr_size_ = 0;
}

template<typename E, size_t N>
void xtra::ArrayCircularQueue<E, N>::pop(E &e) {
    if (is_empty()) {
        return;
    }

    e = data_[ptr_read_];
    circular_inc(ptr_read_);
    curr_size_--;
}

template<typename E, size_t N>
void xtra::ArrayCircularQueue<E, N>::peek(E &e) {
    if (is_empty()) {
        return;
    }
    e = data_[ptr_read_];
}

template<typename E, size_t N>
void xtra::ArrayCircularQueue<E, N>::circular_inc(unsigned int &ptr) {
    if (ptr == N - 1) {
        ptr = 0;
    } else {
        ptr++;
    }
}