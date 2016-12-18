//
// Created by Adam Cardenas on 12/17/16.
//

#ifndef XTRA_XARRAYSTACK_H
#define XTRA_XARRAYSTACK_H

#include <vector>

namespace xtra {

    template<typename A>
    class VectorStack {

    public:

        VectorStack<A>() {
            data_ = std::vector<A>();
        }

        VectorStack<A>(std::vector<A> ls) {
            data_ = std::vector<A>(ls);
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
        int next_index_ = 0;
    };


    class EmptyStackException : public std::runtime_error {
    public:
        EmptyStackException() : runtime_error("operation on empty stack") {};
    };
}


#endif //XTRA_XARRAYSTACK_H
