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

// multimap(multimap&& m);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("multimap cons move pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    typedef std::pair<const int, double> V;
    {
        typedef test_compare<std::less<int> > C;
        typedef test_allocator<V> A;
        contiguous::multimap<int, double, C, A> mo(C(5), A(7));
        contiguous::multimap<int, double, C, A> m = std::move(mo);
        REQUIRE(m.get_allocator() == A(7));
        REQUIRE(m.key_comp() == C(5));
        REQUIRE(m.size() == 0);
        REQUIRE(distance(m.begin(), m.end()) == 0);

        REQUIRE(mo.get_allocator() == A(7));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
    }
    {
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
        contiguous::multimap<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
        contiguous::multimap<int, double, C, A> m = std::move(mo);
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

        REQUIRE(mo.get_allocator() == A(7));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
    }
#if TEST_STD_VER >= 11
    {
        typedef test_compare<std::less<int> > C;
        typedef min_allocator<V> A;
        contiguous::multimap<int, double, C, A> mo(C(5), A());
        contiguous::multimap<int, double, C, A> m = std::move(mo);
        REQUIRE(m.get_allocator() == A());
        REQUIRE(m.key_comp() == C(5));
        REQUIRE(m.size() == 0);
        REQUIRE(distance(m.begin(), m.end()) == 0);

        REQUIRE(mo.get_allocator() == A());
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
    }
    {
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
        contiguous::multimap<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A());
        contiguous::multimap<int, double, C, A> m = std::move(mo);
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

        REQUIRE(mo.get_allocator() == A());
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
    }
#endif
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
