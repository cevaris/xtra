//
// Created by Adam Cardenas on 12/18/16.
//

#ifndef XTRA_EXCEPTIONS_H
#define XTRA_EXCEPTIONS_H

#include <stdexcept>

namespace xtra {
    class IllegalArgumentException : public std::runtime_error {
    public:

        IllegalArgumentException(const std::string &msg) :
                runtime_error(msg) {};
    };

    class IllegalStateException : public std::runtime_error {
    public:

        IllegalStateException(const std::string &msg) : runtime_error(msg) {};
    };
}

#endif //XTRA_EXCEPTIONS_H
