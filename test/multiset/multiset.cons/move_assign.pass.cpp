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

// multiset& operator=(multiset&& s);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("multiset cons move assign pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef MoveOnly V;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef test_allocator<V> A;
        typedef contiguous::multiset<MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A(7));
        V a2[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m2(I(a2), I(a2+sizeof(a2)/sizeof(a2[0])), C(5), A(7));
        M m3(C(3), A(7));
        m3 = std::move(m1);
        REQUIRE(m3 == m2);
        REQUIRE(m3.get_allocator() == A(7));
        REQUIRE(m3.key_comp() == C(5));
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
        REQUIRE(m1.empty());
#endif
    }
    {
        typedef MoveOnly V;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef test_allocator<V> A;
        typedef contiguous::multiset<MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A(7));
        V a2[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m2(I(a2), I(a2+sizeof(a2)/sizeof(a2[0])), C(5), A(7));
        M m3(C(3), A(5));
        m3 = std::move(m1);
        REQUIRE(m3 == m2);
        REQUIRE(m3.get_allocator() == A(5));
        REQUIRE(m3.key_comp() == C(5));
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
        REQUIRE(m1.empty());
#endif
    }
    {
        typedef MoveOnly V;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef other_allocator<V> A;
        typedef contiguous::multiset<MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A(7));
        V a2[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m2(I(a2), I(a2+sizeof(a2)/sizeof(a2[0])), C(5), A(7));
        M m3(C(3), A(5));
        m3 = std::move(m1);
        REQUIRE(m3 == m2);
        REQUIRE(m3.get_allocator() == A(7));
        REQUIRE(m3.key_comp() == C(5));
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
        REQUIRE(m1.empty());
#endif
    }
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
#if TEST_STD_VER >= 11
    {
        typedef MoveOnly V;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef min_allocator<V> A;
        typedef contiguous::multiset<MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A());
        V a2[] =
        {
            V(1),
            V(1),
            V(1),
            V(2),
            V(2),
            V(2),
            V(3),
            V(3),
            V(3)
        };
        M m2(I(a2), I(a2+sizeof(a2)/sizeof(a2[0])), C(5), A());
        M m3(C(3), A());
        m3 = std::move(m1);
        REQUIRE(m3 == m2);
        REQUIRE(m3.get_allocator() == A());
        REQUIRE(m3.key_comp() == C(5));
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
        REQUIRE(m1.empty());
#endif
    }
#endif
}
