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
//     multimap(InputIterator first, InputIterator last,
//              const key_compare& comp, const allocator_type& a);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("multimap cons iter iter comp alloc pass")
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
    typedef test_allocator<V> A;
    contiguous::multimap<int, double, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
    REQUIRE(m.get_allocator() == A(7));
    REQUIRE(m.key_comp() == C(5));
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
    typedef test_compare<std::less<int> > C;
    typedef min_allocator<V> A;
    contiguous::multimap<int, double, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A());
    REQUIRE(m.get_allocator() == A());
    REQUIRE(m.key_comp() == C(5));
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
    typedef explicit_allocator<V> A;
    contiguous::multimap<int, double, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A{});
    REQUIRE(m.get_allocator() == A{});
    REQUIRE(m.key_comp() == C(5));
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
#endif
}
