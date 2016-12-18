//
// Created by Adam Cardenas on 12/18/16.
//

#ifndef XTRA_ARRAY_BLOCKING_QUEUE_H
#define XTRA_ARRAY_BLOCKING_QUEUE_H


#include <chrono>
#include <vector>
#include <array>
#include "exceptions.h"

namespace xtra {

    template<typename E, size_t N>
    class ArrayBlockingQueue {

    public:

        ArrayBlockingQueue<E, N>() {
            data_ = std::array<E, N>();
        };

        ArrayBlockingQueue<E, N>(std::array<E, N> c) {
            if (N < c.size()) {
                throw IllegalArgumentException("not enough capacity");
            }

            // new array with size N
            data_ = std::array<E, N>();
            // foreach new input element, add to queue
            for (const auto &e : c) {
                add(e);
            }
        };

        ArrayBlockingQueue(int capacity, bool fair) {
            throw std::runtime_error("Not Implemented");
        };

        ArrayBlockingQueue(int capacity, bool fair, std::vector<E> c) {
            throw std::runtime_error("Not Implemented");
        };


        bool add(E e);

        void clear();

        bool contains(E e);

        int drain_to(std::vector<E> c);

        int drain_to(std::vector<E> c, int max_elements);

        bool offer(E e);

        bool offer(E e, long timeout, std::chrono::duration<long> unit);

        E peek();

        E poll();

        void put(E e);

        int remaining_capacity();

        bool remove(E e);

        unsigned int size();

        E take();

        E *to_array();

        bool is_empty();

        std::string to_string();

    private:

        std::array<E, N> data_;
        unsigned int head_idx_ = 0;
        unsigned int tail_idx_ = 0;
        unsigned int curr_size_ = 0;

    };

}

#endif //XTRA_ARRAY_BLOCKING_QUEUE_H
