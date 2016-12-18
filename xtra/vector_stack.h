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

        VectorStack<A>();

        VectorStack<A>(A *);

        ~VectorStack<A>();

        bool empty();

        A peek();

        A pop();


        A push(A);

        int search(A);

    private:
        std::vector<A> data_;
    };

}


#endif //XTRA_XARRAYSTACK_H
