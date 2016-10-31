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

// map(const map& m, const allocator_type& a);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("map cons copy alloc pass")
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
    contiguous::map<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
    contiguous::map<int, double, C, A> m(mo, A(3));
    REQUIRE(m.get_allocator() == A(3));
    REQUIRE(m.key_comp() == C(5));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));

    REQUIRE(mo.get_allocator() == A(7));
    REQUIRE(mo.key_comp() == C(5));
    REQUIRE(mo.size() == 3);
    REQUIRE(distance(mo.begin(), mo.end()) == 3);
    REQUIRE(*mo.begin() == V(1, 1));
    REQUIRE(*next(mo.begin()) == V(2, 1));
    REQUIRE(*next(mo.begin(), 2) == V(3, 1));
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
    contiguous::map<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A());
    contiguous::map<int, double, C, A> m(mo, A());
    REQUIRE(m.get_allocator() == A());
    REQUIRE(m.key_comp() == C(5));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));

    REQUIRE(mo.get_allocator() == A());
    REQUIRE(mo.key_comp() == C(5));
    REQUIRE(mo.size() == 3);
    REQUIRE(distance(mo.begin(), mo.end()) == 3);
    REQUIRE(*mo.begin() == V(1, 1));
    REQUIRE(*next(mo.begin()) == V(2, 1));
    REQUIRE(*next(mo.begin(), 2) == V(3, 1));
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
    contiguous::map<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A{});
    contiguous::map<int, double, C, A> m(mo, A{});
    REQUIRE(m.get_allocator() == A());
    REQUIRE(m.key_comp() == C(5));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));

    REQUIRE(mo.get_allocator() == A());
    REQUIRE(mo.key_comp() == C(5));
    REQUIRE(mo.size() == 3);
    REQUIRE(distance(mo.begin(), mo.end()) == 3);
    REQUIRE(*mo.begin() == V(1, 1));
    REQUIRE(*next(mo.begin()) == V(2, 1));
    REQUIRE(*next(mo.begin(), 2) == V(3, 1));
    }
#endif
}
