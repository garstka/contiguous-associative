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

// template <class Key, class T, class Compare, class Allocator>
//   void
//   swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"
#include "test_allocator.h"
#include "test_compare.h"
#include "min_allocator.h"

TEST_CASE("map special non member swap pass")
{
    typedef std::pair<const int, double> V;
    {
    typedef contiguous::map<int, double> M;
    {
        M m1;
        M m2;
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    {
        V ar2[] =
        {
            V(5, 5),
            V(6, 6),
            V(7, 7),
            V(8, 8),
            V(9, 9),
            V(10, 10),
            V(11, 11),
            V(12, 12)
        };
        M m1;
        M m2(ar2, ar2+sizeof(ar2)/sizeof(ar2[0]));
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    {
        V ar1[] =
        {
            V(1, 1),
            V(2, 2),
            V(3, 3),
            V(4, 4)
        };
        M m1(ar1, ar1+sizeof(ar1)/sizeof(ar1[0]));
        M m2;
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    {
        V ar1[] =
        {
            V(1, 1),
            V(2, 2),
            V(3, 3),
            V(4, 4)
        };
        V ar2[] =
        {
            V(5, 5),
            V(6, 6),
            V(7, 7),
            V(8, 8),
            V(9, 9),
            V(10, 10),
            V(11, 11),
            V(12, 12)
        };
        M m1(ar1, ar1+sizeof(ar1)/sizeof(ar1[0]));
        M m2(ar2, ar2+sizeof(ar2)/sizeof(ar2[0]));
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    }
#ifndef IGNORE_ILLEGAL_SWAP
    {
        typedef test_allocator<V> A;
        typedef test_compare<std::less<int> > C;
        typedef contiguous::map<int, double, C, A> M;
        V ar1[] =
        {
            V(1, 1),
            V(2, 2),
            V(3, 3),
            V(4, 4)
        };
        V ar2[] =
        {
            V(5, 5),
            V(6, 6),
            V(7, 7),
            V(8, 8),
            V(9, 9),
            V(10, 10),
            V(11, 11),
            V(12, 12)
        };
        M m1(ar1, ar1+sizeof(ar1)/sizeof(ar1[0]), C(1), A(1));
        M m2(ar2, ar2+sizeof(ar2)/sizeof(ar2[0]), C(2), A(2));
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
        REQUIRE(m1.key_comp() == C(2));
        REQUIRE(m1.get_allocator() == A(1));
        REQUIRE(m2.key_comp() == C(1));
        REQUIRE(m2.get_allocator() == A(2));
    }
#endif
    {
        typedef other_allocator<V> A;
        typedef test_compare<std::less<int> > C;
        typedef contiguous::map<int, double, C, A> M;
        V ar1[] =
        {
            V(1, 1),
            V(2, 2),
            V(3, 3),
            V(4, 4)
        };
        V ar2[] =
        {
            V(5, 5),
            V(6, 6),
            V(7, 7),
            V(8, 8),
            V(9, 9),
            V(10, 10),
            V(11, 11),
            V(12, 12)
        };
        M m1(ar1, ar1+sizeof(ar1)/sizeof(ar1[0]), C(1), A(1));
        M m2(ar2, ar2+sizeof(ar2)/sizeof(ar2[0]), C(2), A(2));
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
        REQUIRE(m1.key_comp() == C(2));
        REQUIRE(m1.get_allocator() == A(2));
        REQUIRE(m2.key_comp() == C(1));
        REQUIRE(m2.get_allocator() == A(1));
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::map<int, double, std::less<int>, min_allocator<V>> M;
    {
        M m1;
        M m2;
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    {
        V ar2[] =
        {
            V(5, 5),
            V(6, 6),
            V(7, 7),
            V(8, 8),
            V(9, 9),
            V(10, 10),
            V(11, 11),
            V(12, 12)
        };
        M m1;
        M m2(ar2, ar2+sizeof(ar2)/sizeof(ar2[0]));
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    {
        V ar1[] =
        {
            V(1, 1),
            V(2, 2),
            V(3, 3),
            V(4, 4)
        };
        M m1(ar1, ar1+sizeof(ar1)/sizeof(ar1[0]));
        M m2;
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    {
        V ar1[] =
        {
            V(1, 1),
            V(2, 2),
            V(3, 3),
            V(4, 4)
        };
        V ar2[] =
        {
            V(5, 5),
            V(6, 6),
            V(7, 7),
            V(8, 8),
            V(9, 9),
            V(10, 10),
            V(11, 11),
            V(12, 12)
        };
        M m1(ar1, ar1+sizeof(ar1)/sizeof(ar1[0]));
        M m2(ar2, ar2+sizeof(ar2)/sizeof(ar2[0]));
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
    }
    }
    {
        typedef min_allocator<V> A;
        typedef test_compare<std::less<int> > C;
        typedef contiguous::map<int, double, C, A> M;
        V ar1[] =
        {
            V(1, 1),
            V(2, 2),
            V(3, 3),
            V(4, 4)
        };
        V ar2[] =
        {
            V(5, 5),
            V(6, 6),
            V(7, 7),
            V(8, 8),
            V(9, 9),
            V(10, 10),
            V(11, 11),
            V(12, 12)
        };
        M m1(ar1, ar1+sizeof(ar1)/sizeof(ar1[0]), C(1), A());
        M m2(ar2, ar2+sizeof(ar2)/sizeof(ar2[0]), C(2), A());
        M m1_save = m1;
        M m2_save = m2;
        swap(m1, m2);
        REQUIRE(m1 == m2_save);
        REQUIRE(m2 == m1_save);
        REQUIRE(m1.key_comp() == C(2));
        REQUIRE(m1.get_allocator() == A());
        REQUIRE(m2.key_comp() == C(1));
        REQUIRE(m2.get_allocator() == A());
    }
#endif
}
