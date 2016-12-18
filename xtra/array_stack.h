//
// Created by Adam Cardenas on 12/17/16.
//

#ifndef XTRA_XARRAYSTACK_H
#define XTRA_XARRAYSTACK_H

namespace xtra {

    template<typename A>
    class ArrayStack {

    public:
        bool empty();

        A peek();

        A pop();


        A push(A a);

        int search(A a);
    };

}


#endif //XTRA_XARRAYSTACK_H
