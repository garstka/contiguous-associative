//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// Check that contiguous::map and it's iterators can be instantiated with an incomplete
// type.

#include "defs.h"

#ifndef MAP_REQUIRE_COMPLETE_TYPE
#include "catch.hpp"

#include "contiguous/map.h"

struct A {
    typedef contiguous::map<A, A> Map;
    int data;
    Map m;
    Map::iterator it;
    Map::const_iterator cit;
};

inline bool operator==(A const& L, A const& R) { return &L == &R; }
inline bool operator<(A const& L, A const& R)  { return L.data < R.data; }
TEST_CASE("map incomplete type pass") {
    A a;
}
#endif