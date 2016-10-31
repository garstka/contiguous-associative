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

// multimap(multimap&& m, const allocator_type& a);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"
#include "Counter.h"

TEST_CASE("multimap cons move alloc pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef std::pair<MoveOnly, MoveOnly> V;
        typedef std::pair<const MoveOnly, MoveOnly> VC;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef test_allocator<VC> A;
        typedef contiguous::multimap<MoveOnly, MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A(7));
        V a2[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
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
        typedef std::pair<MoveOnly, MoveOnly> V;
        typedef std::pair<const MoveOnly, MoveOnly> VC;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef test_allocator<VC> A;
        typedef contiguous::multimap<MoveOnly, MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A(7));
        V a2[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
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
        typedef std::pair<MoveOnly, MoveOnly> V;
        typedef std::pair<const MoveOnly, MoveOnly> VC;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef other_allocator<VC> A;
        typedef contiguous::multimap<MoveOnly, MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A(7));
        V a2[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
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
        typedef Counter<int> T;
        typedef std::pair<int, T> V;
        typedef std::pair<const int, T> VC;
        typedef test_allocator<VC> A;
        typedef std::less<int> C;
        typedef contiguous::multimap<const int, T, C, A> M;
        typedef V* I;
        Counter_base::gConstructed = 0;
        {
            V a1[] =
            {
                V(1, 1),
                V(1, 2),
                V(1, 3),
                V(2, 1),
                V(2, 2),
                V(2, 3),
                V(3, 1),
                V(3, 2),
                V(3, 3)
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
#if TEST_STD_VER >= 11
    {
        typedef std::pair<MoveOnly, MoveOnly> V;
        typedef std::pair<const MoveOnly, MoveOnly> VC;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef min_allocator<VC> A;
        typedef contiguous::multimap<MoveOnly, MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A());
        V a2[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
        };
        M m2(I(a2), I(a2+sizeof(a2)/sizeof(a2[0])), C(5), A());
        M m3(std::move(m1), A());
        REQUIRE(m3 == m2);
        REQUIRE(m3.get_allocator() == A());
        REQUIRE(m3.key_comp() == C(5));
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
        REQUIRE(m1.empty());
#endif
    }
    {
        typedef std::pair<MoveOnly, MoveOnly> V;
        typedef std::pair<const MoveOnly, MoveOnly> VC;
        typedef test_compare<std::less<MoveOnly> > C;
        typedef explicit_allocator<VC> A;
        typedef contiguous::multimap<MoveOnly, MoveOnly, C, A> M;
        typedef std::move_iterator<V*> I;
        V a1[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
        };
        M m1(I(a1), I(a1+sizeof(a1)/sizeof(a1[0])), C(5), A{});
        V a2[] =
        {
            V(1, 1),
            V(1, 2),
            V(1, 3),
            V(2, 1),
            V(2, 2),
            V(2, 3),
            V(3, 1),
            V(3, 2),
            V(3, 3)
        };
        M m2(I(a2), I(a2+sizeof(a2)/sizeof(a2[0])), C(5), A{});
        M m3(std::move(m1), A{});
        REQUIRE(m3 == m2);
        REQUIRE(m3.get_allocator() == A{});
        REQUIRE(m3.key_comp() == C(5));
#ifndef ALLOWED_NON_EMPTY_AFTER_MOVE
        REQUIRE(m1.empty());
#endif
    }
#endif
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
