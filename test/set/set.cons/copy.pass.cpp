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

// set(const set& m);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "test_macros.h"
#include "test_compare.h"
#include "test_allocator.h"

TEST_CASE("set cons copy pass")
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
        typedef test_compare<std::less<int> > C;
        typedef test_allocator<V> A;
        contiguous::set<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
        contiguous::set<int, C, A> m = mo;
        REQUIRE(m.get_allocator() == A(7));
        REQUIRE(m.key_comp() == C(5));
        REQUIRE(m.size() == 3);
        REQUIRE(distance(m.begin(), m.end()) == 3);
        REQUIRE(*m.begin() == 1);
        REQUIRE(*next(m.begin()) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);

        REQUIRE(mo.get_allocator() == A(7));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 3);
        REQUIRE(distance(mo.begin(), mo.end()) == 3);
        REQUIRE(*mo.begin() == 1);
        REQUIRE(*next(mo.begin()) == 2);
        REQUIRE(*next(mo.begin(), 2) == 3);
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
        typedef other_allocator<V> A;
        contiguous::set<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
        contiguous::set<int, C, A> m = mo;
        REQUIRE(m.get_allocator() == A(-2));
        REQUIRE(m.key_comp() == C(5));
        REQUIRE(m.size() == 3);
        REQUIRE(distance(m.begin(), m.end()) == 3);
        REQUIRE(*m.begin() == 1);
        REQUIRE(*next(m.begin()) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);

        REQUIRE(mo.get_allocator() == A(7));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 3);
        REQUIRE(distance(mo.begin(), mo.end()) == 3);
        REQUIRE(*mo.begin() == 1);
        REQUIRE(*next(mo.begin()) == 2);
        REQUIRE(*next(mo.begin(), 2) == 3);
    }
#endif
}
