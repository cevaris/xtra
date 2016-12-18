//
// Created by Adam Cardenas on 12/18/16.
//

#include <sstream>
#include "array_blocking_queue.h"


template<typename E, size_t N>
bool xtra::ArrayBlockingQueue<E, N>::is_empty() {
    return curr_size_ == 0;
}

template<typename E, size_t N>
unsigned int xtra::ArrayBlockingQueue<E, N>::size() {
    return curr_size_;
}

template<typename E, size_t N>
bool xtra::ArrayBlockingQueue<E, N>::add(E e) {

    data_[tail_idx_] = e;
    tail_idx_++;
    curr_size_++;

    return true;
}

template<typename E, size_t N>
E xtra::ArrayBlockingQueue<E, N>::peek() {
    return data_[head_idx_];
}

template<typename E, size_t N>
std::string xtra::ArrayBlockingQueue<E, N>::to_string() {
    std::string str = "";
    for (int temp = 0; temp < N; temp++)
        str += data_[temp];
    return str;
}

