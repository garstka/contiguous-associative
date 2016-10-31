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

// multiset(multiset&& s);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("multiset cons move pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef int V;
        typedef test_compare<std::less<int> > C;
        typedef test_allocator<V> A;
        contiguous::multiset<int, C, A> mo(C(5), A(7));
        contiguous::multiset<int, C, A> m = std::move(mo);
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
        typedef test_compare<std::less<int> > C;
        typedef test_allocator<V> A;
        contiguous::multiset<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
        contiguous::multiset<int, C, A> m = std::move(mo);
        REQUIRE(m.get_allocator() == A(7));
        REQUIRE(m.key_comp() == C(5));
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

        REQUIRE(mo.get_allocator() == A(7));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
    }
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
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
        typedef test_compare<std::less<int> > C;
        typedef min_allocator<V> A;
        contiguous::multiset<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A());
        contiguous::multiset<int, C, A> m = std::move(mo);
        REQUIRE(m.get_allocator() == A());
        REQUIRE(m.key_comp() == C(5));
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

        REQUIRE(mo.get_allocator() == A());
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
    }
#endif
}
