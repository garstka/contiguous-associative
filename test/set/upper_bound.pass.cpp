//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class set

//       iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"

TEST_CASE("set upper bound pass")
{
    {
    typedef int V;
    typedef contiguous::set<int> M;
    {
        typedef M::iterator R;
        V ar[] =
        {
            5,
            7,
            9,
            11,
            13,
            15,
            17,
            19
        };
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(13);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(15);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(17);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(19);
        REQUIRE(r == next(m.begin(), 8));
        r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    {
        typedef M::const_iterator R;
        V ar[] =
        {
            5,
            7,
            9,
            11,
            13,
            15,
            17,
            19
        };
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(13);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(15);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(17);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(19);
        REQUIRE(r == next(m.begin(), 8));
        r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    }
#if TEST_STD_VER >= 11
    {
    typedef int V;
    typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
    {
        typedef M::iterator R;
        V ar[] =
        {
            5,
            7,
            9,
            11,
            13,
            15,
            17,
            19
        };
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(13);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(15);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(17);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(19);
        REQUIRE(r == next(m.begin(), 8));
        r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    {
        typedef M::const_iterator R;
        V ar[] =
        {
            5,
            7,
            9,
            11,
            13,
            15,
            17,
            19
        };
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(13);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(15);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(17);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(19);
        REQUIRE(r == next(m.begin(), 8));
        r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.upper_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.upper_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.upper_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.upper_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    }
#endif
#if _LIBCPP_STD_VER > 11
    {
    typedef int V;
    typedef contiguous::set<V, std::less<>> M;
    typedef M::iterator R;

    V ar[] =
    {
        5,
        7,
        9,
        11,
        13,
        15,
        17,
        19
    };
    M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
    R r = m.upper_bound(5);
    REQUIRE(r == next(m.begin(), 1));
    r = m.upper_bound(7);
    REQUIRE(r == next(m.begin(), 2));
    r = m.upper_bound(9);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(11);
    REQUIRE(r == next(m.begin(), 4));
    r = m.upper_bound(13);
    REQUIRE(r == next(m.begin(), 5));
    r = m.upper_bound(15);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(17);
    REQUIRE(r == next(m.begin(), 7));
    r = m.upper_bound(19);
    REQUIRE(r == next(m.begin(), 8));
    r = m.upper_bound(4);
    REQUIRE(r == next(m.begin(), 0));
    r = m.upper_bound(6);
    REQUIRE(r == next(m.begin(), 1));
    r = m.upper_bound(8);
    REQUIRE(r == next(m.begin(), 2));
    r = m.upper_bound(10);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(12);
    REQUIRE(r == next(m.begin(), 4));
    r = m.upper_bound(14);
    REQUIRE(r == next(m.begin(), 5));
    r = m.upper_bound(16);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(18);
    REQUIRE(r == next(m.begin(), 7));
    r = m.upper_bound(20);
    REQUIRE(r == next(m.begin(), 8));
    }

    {
    typedef PrivateConstructor V;
    typedef contiguous::set<V, std::less<>> M;
    typedef M::iterator R;

    M m;
    m.insert ( V::make ( 5 ));
    m.insert ( V::make ( 7 ));
    m.insert ( V::make ( 9 ));
    m.insert ( V::make ( 11 ));
    m.insert ( V::make ( 13 ));
    m.insert ( V::make ( 15 ));
    m.insert ( V::make ( 17 ));
    m.insert ( V::make ( 19 ));

    R r = m.upper_bound(5);
    REQUIRE(r == next(m.begin(), 1));
    r = m.upper_bound(7);
    REQUIRE(r == next(m.begin(), 2));
    r = m.upper_bound(9);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(11);
    REQUIRE(r == next(m.begin(), 4));
    r = m.upper_bound(13);
    REQUIRE(r == next(m.begin(), 5));
    r = m.upper_bound(15);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(17);
    REQUIRE(r == next(m.begin(), 7));
    r = m.upper_bound(19);
    REQUIRE(r == next(m.begin(), 8));
    r = m.upper_bound(4);
    REQUIRE(r == next(m.begin(), 0));
    r = m.upper_bound(6);
    REQUIRE(r == next(m.begin(), 1));
    r = m.upper_bound(8);
    REQUIRE(r == next(m.begin(), 2));
    r = m.upper_bound(10);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(12);
    REQUIRE(r == next(m.begin(), 4));
    r = m.upper_bound(14);
    REQUIRE(r == next(m.begin(), 5));
    r = m.upper_bound(16);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(18);
    REQUIRE(r == next(m.begin(), 7));
    r = m.upper_bound(20);
    REQUIRE(r == next(m.begin(), 8));
    }
#endif
}
