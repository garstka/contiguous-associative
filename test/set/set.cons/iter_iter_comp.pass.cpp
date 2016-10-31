//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class set

// template <class InputIterator>
//     set(InputIterator first, InputIterator last, const value_compare& comp);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "test_iterators.h"
#include "test_compare.h"

TEST_CASE("set cons iter iter comp pass")
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
    contiguous::set<V, C> m(input_iterator<const V*>(ar),
                     input_iterator<const V*>(ar+sizeof(ar)/sizeof(ar[0])), C(5));
    REQUIRE(m.value_comp() == C(5));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == 1);
    REQUIRE(*next(m.begin()) == 2);
    REQUIRE(*next(m.begin(), 2) == 3);
}
