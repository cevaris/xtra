//
// Created by Adam Cardenas on 12/20/16.
//

#ifndef XTRA_ARRAY_CIRCULAR_QUEUE_H
#define XTRA_ARRAY_CIRCULAR_QUEUE_H

#include <array>
#include <string>
#include "exceptions.h"


namespace xtra {

    template<typename E, size_t N>
    class ArrayCircularQueue {

    public:

        ArrayCircularQueue<E, N>() {
            data_ = std::array<E, N>();
        };

        ArrayCircularQueue<E, N>(std::array<E, N> c) {
            if (N < c.size()) {
                throw IllegalArgumentException("not enough capacity");
            }

            data_ = std::array<E, N>();
            for (const auto &e : c) {
                add(e);
            }
        };

        bool add(E e);

        bool is_empty();

        bool offer(E e);

        void peek(E &e);

        void pop(E &e);

        unsigned int size();

        void clear();


    private:
        std::array<E, N> data_;
        unsigned int curr_size_ = 0;

        unsigned int ptr_read_ = 0;
        unsigned int ptr_write_ = 0;


        void circular_inc(unsigned int &ptr);
    };

}

#endif //XTRA_ARRAY_CIRCULAR_QUEUE_H
