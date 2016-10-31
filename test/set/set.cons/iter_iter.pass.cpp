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
//     set(InputIterator first, InputIterator last);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "test_iterators.h"
#include "min_allocator.h"

TEST_CASE("set cons iter iter pass")
{
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
    contiguous::set<V> m(input_iterator<const int*>(ar),
                  input_iterator<const int*>(ar+sizeof(ar)/sizeof(ar[0])));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == 1);
    REQUIRE(*next(m.begin()) == 2);
    REQUIRE(*next(m.begin(), 2) == 3);
    }
#if TEST_STD_VER >= 11
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
    contiguous::set<V, std::less<int>, min_allocator<int>> m(input_iterator<const int*>(ar),
                  input_iterator<const int*>(ar+sizeof(ar)/sizeof(ar[0])));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == 1);
    REQUIRE(*next(m.begin()) == 2);
    REQUIRE(*next(m.begin(), 2) == 3);
    }
#endif
}
