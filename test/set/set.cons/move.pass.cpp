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

// set(set&& s);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("set cons move pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef int V;
        typedef test_compare<std::less<int> > C;
        typedef test_allocator<V> A;
        contiguous::set<int, C, A> mo(C(5), A(7));
        contiguous::set<int, C, A> m = std::move(mo);
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
        contiguous::set<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
        contiguous::set<int, C, A> m = std::move(mo);
        REQUIRE(m.get_allocator() == A(7));
        REQUIRE(m.key_comp() == C(5));
        REQUIRE(m.size() == 3);
        REQUIRE(distance(m.begin(), m.end()) == 3);
        REQUIRE(*m.begin() == 1);
        REQUIRE(*next(m.begin()) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);

        REQUIRE(mo.get_allocator() == A(7));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
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
        typedef test_compare<std::less<int> > C;
        typedef min_allocator<V> A;
        contiguous::set<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A());
        contiguous::set<int, C, A> m = std::move(mo);
        REQUIRE(m.get_allocator() == A());
        REQUIRE(m.key_comp() == C(5));
        REQUIRE(m.size() == 3);
        REQUIRE(distance(m.begin(), m.end()) == 3);
        REQUIRE(*m.begin() == 1);
        REQUIRE(*next(m.begin()) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);

        REQUIRE(mo.get_allocator() == A());
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 0);
        REQUIRE(distance(mo.begin(), mo.end()) == 0);
    }
#endif
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
