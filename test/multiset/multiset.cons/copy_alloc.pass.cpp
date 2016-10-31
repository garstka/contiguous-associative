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

// multiset(const multiset& m, const allocator_type& a);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"

TEST_CASE("multiset cons copy alloc pass")
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
    contiguous::multiset<int, C, A> m(mo, A(3));
    REQUIRE(m.get_allocator() == A(3));
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
