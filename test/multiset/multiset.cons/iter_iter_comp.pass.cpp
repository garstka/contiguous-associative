//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class multiset

// template <class InputIterator>
//     multiset(InputIterator first, InputIterator last, const value_compare& comp);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "test_iterators.h"
#include "test_compare.h"

TEST_CASE("multiset cons iter iter comp pass")
{
    typedef int V;
    V ar[] =
    {
        1,
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        3
    };
    typedef test_compare<std::less<V> > C;
    contiguous::multiset<V, C> m(input_iterator<const V*>(ar),
                     input_iterator<const V*>(ar+sizeof(ar)/sizeof(ar[0])), C(5));
    REQUIRE(m.value_comp() == C(5));
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    REQUIRE(*next(m.begin(), 0) == 1);
    REQUIRE(*next(m.begin(), 1) == 1);
    REQUIRE(*next(m.begin(), 2) == 1);
    REQUIRE(*next(m.begin(), 3) == 2);
    REQUIRE(*next(m.begin(), 4) == 2);
    REQUIRE(*next(m.begin(), 5) == 2);
    REQUIRE(*next(m.begin(), 6) == 3);
    REQUIRE(*next(m.begin(), 7) == 3);
    REQUIRE(*next(m.begin(), 8) == 3);
}
