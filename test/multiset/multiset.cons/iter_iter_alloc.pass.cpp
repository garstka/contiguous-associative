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

// template <class InputIterator>
//     multiset(InputIterator first, InputIterator last,
//         const value_compare& comp, const allocator_type& a);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "test_iterators.h"
#include "test_compare.h"
#include "test_allocator.h"

TEST_CASE("multiset cons iter iter alloc pass")
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
    typedef test_compare<std::less<V> > C;
    typedef test_allocator<V> A;
    contiguous::multiset<V, C, A> m(input_iterator<const V*>(ar),
                        input_iterator<const V*>(ar+sizeof(ar)/sizeof(ar[0])),
                        C(5), A(7));
    REQUIRE(m.value_comp() == C(5));
    REQUIRE(m.get_allocator() == A(7));
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
    }
#if _LIBCPP_STD_VER > 11
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
    typedef test_allocator<V> A;
    typedef test_compare<std::less<int> > C;
    A a;
    contiguous::multiset<V, C, A> m(ar, ar+sizeof(ar)/sizeof(ar[0]), a);

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
    REQUIRE(m.get_allocator() == a);
    }
#endif
}
