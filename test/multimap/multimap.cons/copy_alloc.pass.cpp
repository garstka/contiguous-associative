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

// multimap(const multimap& m, const allocator_type& a);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("multimap cons copy alloc pass")
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
    contiguous::multimap<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A(7));
    contiguous::multimap<int, double, C, A> m(mo, A(3));
    REQUIRE(m == mo);
    REQUIRE(m.get_allocator() == A(3));
    REQUIRE(m.key_comp() == C(5));

    REQUIRE(mo.get_allocator() == A(7));
    REQUIRE(mo.key_comp() == C(5));
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
    contiguous::multimap<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A());
    contiguous::multimap<int, double, C, A> m(mo, A());
    REQUIRE(m == mo);
    REQUIRE(m.get_allocator() == A());
    REQUIRE(m.key_comp() == C(5));

    REQUIRE(mo.get_allocator() == A());
    REQUIRE(mo.key_comp() == C(5));
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
    contiguous::multimap<int, double, C, A> mo(ar, ar+sizeof(ar)/sizeof(ar[0]), C(5), A{});
    contiguous::multimap<int, double, C, A> m(mo, A{});
    REQUIRE(m == mo);
    REQUIRE(m.get_allocator() == A{});
    REQUIRE(m.key_comp() == C(5));

    REQUIRE(mo.get_allocator() == A{});
    REQUIRE(mo.key_comp() == C(5));
    }
#endif
}
