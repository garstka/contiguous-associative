//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class multimap

// template <class InputIterator>
//     multimap(InputIterator first, InputIterator last);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multimap cons iter iter pass")
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
    contiguous::multimap<int, double> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(1, 1.5));
    REQUIRE(*next(m.begin(), 2) == V(1, 2));
    REQUIRE(*next(m.begin(), 3) == V(2, 1));
    REQUIRE(*next(m.begin(), 4) == V(2, 1.5));
    REQUIRE(*next(m.begin(), 5) == V(2, 2));
    REQUIRE(*next(m.begin(), 6) == V(3, 1));
    REQUIRE(*next(m.begin(), 7) == V(3, 1.5));
    REQUIRE(*next(m.begin(), 8) == V(3, 2));
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
    contiguous::multimap<int, double, std::less<int>, min_allocator<V>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(1, 1.5));
    REQUIRE(*next(m.begin(), 2) == V(1, 2));
    REQUIRE(*next(m.begin(), 3) == V(2, 1));
    REQUIRE(*next(m.begin(), 4) == V(2, 1.5));
    REQUIRE(*next(m.begin(), 5) == V(2, 2));
    REQUIRE(*next(m.begin(), 6) == V(3, 1));
    REQUIRE(*next(m.begin(), 7) == V(3, 1.5));
    REQUIRE(*next(m.begin(), 8) == V(3, 2));
    }
#if LIBCPP_STD_VER > 11
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
    typedef min_allocator<std::pair<const int, double>> A;
    A a;
    contiguous::multimap<int, double, std::less<int>, A> m(ar, ar+sizeof(ar)/sizeof(ar[0]), a);
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(1, 1.5));
    REQUIRE(*next(m.begin(), 2) == V(1, 2));
    REQUIRE(*next(m.begin(), 3) == V(2, 1));
    REQUIRE(*next(m.begin(), 4) == V(2, 1.5));
    REQUIRE(*next(m.begin(), 5) == V(2, 2));
    REQUIRE(*next(m.begin(), 6) == V(3, 1));
    REQUIRE(*next(m.begin(), 7) == V(3, 1.5));
    REQUIRE(*next(m.begin(), 8) == V(3, 2));
    REQUIRE(m.get_allocator() == a);
    }
#endif
#endif
}
