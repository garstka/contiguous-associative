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

// multiset& operator=(const multiset& s);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"

TEST_CASE("multiset cons copy assign pass")
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
        contiguous::multiset<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(2));
        contiguous::multiset<int, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0])/2, C(3), A(7));
        m = mo;
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

        REQUIRE(mo.get_allocator() == A(2));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 9);
        REQUIRE(distance(mo.begin(), mo.end()) == 9);
        REQUIRE(*next(mo.begin(), 0) == 1);
        REQUIRE(*next(mo.begin(), 1) == 1);
        REQUIRE(*next(mo.begin(), 2) == 1);
        REQUIRE(*next(mo.begin(), 3) == 2);
        REQUIRE(*next(mo.begin(), 4) == 2);
        REQUIRE(*next(mo.begin(), 5) == 2);
        REQUIRE(*next(mo.begin(), 6) == 3);
        REQUIRE(*next(mo.begin(), 7) == 3);
        REQUIRE(*next(mo.begin(), 8) == 3);
    }
    {
        typedef int V;
        const V ar[] =
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
        contiguous::multiset<int> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        contiguous::multiset<int> *p = &m;
        m = *p;
        REQUIRE(m.size() == 9);
        REQUIRE(std::equal(m.begin(), m.end(), ar));
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
        typedef other_allocator<V> A;
        contiguous::multiset<int, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(2));
        contiguous::multiset<int, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0])/2, C(3), A(7));
        m = mo;
        REQUIRE(m.get_allocator() == A(2));
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

        REQUIRE(mo.get_allocator() == A(2));
        REQUIRE(mo.key_comp() == C(5));
        REQUIRE(mo.size() == 9);
        REQUIRE(distance(mo.begin(), mo.end()) == 9);
        REQUIRE(*next(mo.begin(), 0) == 1);
        REQUIRE(*next(mo.begin(), 1) == 1);
        REQUIRE(*next(mo.begin(), 2) == 1);
        REQUIRE(*next(mo.begin(), 3) == 2);
        REQUIRE(*next(mo.begin(), 4) == 2);
        REQUIRE(*next(mo.begin(), 5) == 2);
        REQUIRE(*next(mo.begin(), 6) == 3);
        REQUIRE(*next(mo.begin(), 7) == 3);
        REQUIRE(*next(mo.begin(), 8) == 3);
    }
}
