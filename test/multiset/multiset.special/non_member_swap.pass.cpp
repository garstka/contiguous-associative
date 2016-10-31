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

// void swap(multiset& m);
#include "defs.h"

#include "contiguous/multiset.h"
#include "contiguous/set.h"
#include "catch.hpp"
#include "test_allocator.h"
#include "test_compare.h"

TEST_CASE("multiset special non member swap pass")
{
    typedef int V;
    {
    typedef contiguous::multiset<int> M;
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
            5,
            6,
            7,
            8,
            9,
            10,
            11,
            12
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
            1,
            2,
            3,
            4
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
            1,
            2,
            3,
            4
        };
        V ar2[] =
        {
            5,
            6,
            7,
            8,
            9,
            10,
            11,
            12
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
        typedef contiguous::set<int, C, A> M;
        V ar1[] =
        {
            1,
            2,
            3,
            4
        };
        V ar2[] =
        {
            5,
            6,
            7,
            8,
            9,
            10,
            11,
            12
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
        typedef contiguous::set<int, C, A> M;
        V ar1[] =
        {
            1,
            2,
            3,
            4
        };
        V ar2[] =
        {
            5,
            6,
            7,
            8,
            9,
            10,
            11,
            12
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
}
