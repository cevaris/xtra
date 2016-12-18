//
// Created by Adam Cardenas on 12/18/16.
//

#ifndef XTRA_ARRAY_BLOCKING_QUEUE_H
#define XTRA_ARRAY_BLOCKING_QUEUE_H


#include <chrono>
#include <vector>

namespace xtra {

    template<typename E>
    class ArrayBlockingQueue {

    public:

        ArrayBlockingQueue() {};

        ArrayBlockingQueue(int capacity) {};

        ArrayBlockingQueue(int capacity, bool fair) {};

        ArrayBlockingQueue(int capacity, bool fair, std::vector<E> c) {};

        bool add(E e);

        void clear();

        bool contains(E e);

        int drain_to(std::vector<E> c);

        int drain_to(std::vector<E> c, int max_elements);

        bool offer(E e);

        bool offer(E e, long timeout, std::chrono::duration<long> unit);

        E peak();

        E poll();

        void put(E e);

        int remaining_capacity();

        bool remove(E e);

        int size();

        E take();

        E *to_array();

        bool is_empty();


    };

}

#endif //XTRA_ARRAY_BLOCKING_QUEUE_H
