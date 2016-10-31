//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef DEFAULTONLY_H
#define DEFAULTONLY_H

#include <cassert>

class DefaultOnly
{
    int data_;

    DefaultOnly(const DefaultOnly&);
    DefaultOnly& operator=(const DefaultOnly&);
public:
    static int count;

    DefaultOnly() : data_(-1) {++count;}
    ~DefaultOnly() {data_ = 0; --count;}

    friend bool operator==(const DefaultOnly& x, const DefaultOnly& y)
        {return x.data_ == y.data_;}
    friend bool operator< (const DefaultOnly& x, const DefaultOnly& y)
        {return x.data_ < y.data_;}
};

#ifndef MOVED_TO_CPP_FILE
int DefaultOnly::count = 0;
#endif

#endif  // DEFAULTONLY_H
