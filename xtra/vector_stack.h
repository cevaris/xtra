//
// Created by Adam Cardenas on 12/17/16.
//

#ifndef XTRA_XARRAYSTACK_H
#define XTRA_XARRAYSTACK_H

#include <vector>

namespace xtra {

    /*
     * Vector based Stack implementation, referenced from Java Stack
     * https://docs.oracle.com/javase/8/docs/api/java/util/Stack.html
     *
     * O(1): empty
     * O(1): pop
     * O(1): push
     * O(1): peek
     * O(n): search
     *
     */
    template<typename A>
    class VectorStack {

    public:

        VectorStack<A>() {
            data_ = std::vector<A>();
        }

        VectorStack<A>(std::vector<A> ls) {
            data_ = std::vector<A>(ls);
            curr_size_ = ls.size();
        };

        ~VectorStack<A>() {
            data_ = std::vector<A>();
        };

        bool empty();

        A peek();

        A pop();


        A push(A);

        int search(A);

    private:
        std::vector<A> data_;
        unsigned long curr_size_ = 0;
    };


    class EmptyStackException : public std::runtime_error {
    public:
        EmptyStackException() : runtime_error("operation on empty stack") {};
    };
}


#endif //XTRA_XARRAYSTACK_H
