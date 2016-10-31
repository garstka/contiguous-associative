//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class map

// template <class InputIterator>
//     map(InputIterator first, InputIterator last, const key_compare& comp);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "test_compare.h"
#include "min_allocator.h"

TEST_CASE("map cons iter iter comp pass")
{
    {
    typedef std::pair<const int, double> V;
    V ar[] =
    {
        V(1, 1),
        V(1, 1.5),
        V(1, 2),
        V(2, 1),
        V(2, 1.5),
        V(2, 2),
        V(3, 1),
        V(3, 1.5),
        V(3, 2),
    };
    typedef test_compare<std::less<int> > C;
    contiguous::map<int, double, C> m(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5));
    REQUIRE(m.key_comp() == C(5));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));
    }
#if TEST_STD_VER >= 11
    {
    typedef std::pair<const int, double> V;
    V ar[] =
    {
        V(1, 1),
        V(1, 1.5),
        V(1, 2),
        V(2, 1),
        V(2, 1.5),
        V(2, 2),
        V(3, 1),
        V(3, 1.5),
        V(3, 2),
    };
    typedef test_compare<std::less<int> > C;
    contiguous::map<int, double, C, min_allocator<std::pair<const int, double>>> m(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5));
    REQUIRE(m.key_comp() == C(5));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));
    }
#endif
}
