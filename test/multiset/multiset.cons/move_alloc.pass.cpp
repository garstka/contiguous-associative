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

// multiset(multiset&& s, const allocator_type& a);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "test_compare.h"
#include "test_allocator.h"
#include "Counter.h"

TEST_CASE("multiset cons move alloc pass")
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
        M m3(std::move(m1), A(7));
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
        M m3(std::move(m1), A(5));
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
        M m3(std::move(m1), A(5));
        REQUIRE(m3 == m2);
        REQUIRE(m3.get_allocator() == A(5));
        REQUIRE(m3.key_comp() == C(5));
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
        REQUIRE(m1.empty());
#endif
    }
#ifndef IGNORE_LIBCXX_SPECIFIC
    {
        typedef Counter<int> V;
        typedef std::less<V> C;
        typedef test_allocator<V> A;
        typedef contiguous::multiset<V, C, A> M;
        typedef V* I;
        Counter_base::gConstructed = 0;
        {
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
            const size_t num = sizeof(a1)/sizeof(a1[0]);
            REQUIRE(Counter_base::gConstructed == num);

            M m1(I(a1), I(a1+num), C(), A());
            REQUIRE(Counter_base::gConstructed == 2*num);

            M m2(m1);
            REQUIRE(m2 == m1);
            REQUIRE(Counter_base::gConstructed == 3*num);

            M m3(std::move(m1), A());
            REQUIRE(m3 == m2);
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
            REQUIRE(m1.empty());
#endif
            REQUIRE(Counter_base::gConstructed == 3*num);

            {
            M m4(std::move(m2), A(5));
            REQUIRE(Counter_base::gConstructed == 3*num);
            REQUIRE(m4 == m3);
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
            REQUIRE(m2.empty());
#endif
            }
            REQUIRE(Counter_base::gConstructed == 2*num);
        }
        REQUIRE(Counter_base::gConstructed == 0);
    }
#endif
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
