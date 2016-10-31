//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// Check that contiguous::multiset and it's iterators can be instantiated with an incomplete
// type.

#include "defs.h"

#include "catch.hpp"

#include "contiguous/multiset.h"

struct A {
    typedef contiguous::multiset<A> Set;
    int data;
    Set m;
    Set::iterator it;
    Set::const_iterator cit;
};

inline bool operator==(A const& L, A const& R) { return &L == &R; }
inline bool operator<(A const& L, A const& R)  { return L.data < R.data; }
TEST_CASE("multiset incomplete type pass") {
    A a;
}
