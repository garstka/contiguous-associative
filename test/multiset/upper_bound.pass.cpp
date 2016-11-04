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

//       iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"

TEST_CASE("multiset upper bound pass")
{
    {
    typedef int V;
    typedef contiguous::multiset<int> M;
    {
        typedef M::iterator R;
        V ar[] =
        {
            5,
            5,
            5,
            7,
            7,
            7,
            9,
            9,
            9
        };
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 9));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 9));
    }
    {
        typedef M::const_iterator R;
        V ar[] =
        {
            5,
            5,
            5,
            7,
            7,
            7,
            9,
            9,
            9
        };
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 9));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 9));
    }
    }
#if TEST_STD_VER >= 11
    {
    typedef int V;
    typedef contiguous::multiset<int, std::less<int>, min_allocator<int>> M;
    {
        typedef M::iterator R;
        V ar[] =
        {
            5,
            5,
            5,
            7,
            7,
            7,
            9,
            9,
            9
        };
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 9));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 9));
    }
    {
        typedef M::const_iterator R;
        V ar[] =
        {
            5,
            5,
            5,
            7,
            7,
            7,
            9,
            9,
            9
        };
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.upper_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.upper_bound(5);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(6);
        REQUIRE(r == next(m.begin(), 3));
        r = m.upper_bound(7);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(8);
        REQUIRE(r == next(m.begin(), 6));
        r = m.upper_bound(9);
        REQUIRE(r == next(m.begin(), 9));
        r = m.upper_bound(11);
        REQUIRE(r == next(m.begin(), 9));
    }
    }
#endif
#if LIBCPP_STD_VER > 11
    {
    typedef int V;
    typedef contiguous::multiset<V, std::less<>> M;

    typedef M::iterator R;
    V ar[] =
    {
        5,
        5,
        5,
        7,
        7,
        7,
        9,
        9,
        9
    };
    M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
    R r = m.upper_bound(4);
    REQUIRE(r == next(m.begin(), 0));
    r = m.upper_bound(5);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(6);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(7);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(8);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(9);
    REQUIRE(r == next(m.begin(), 9));
    r = m.upper_bound(11);
    REQUIRE(r == next(m.begin(), 9));
    }

    {
    typedef PrivateConstructor V;
    typedef contiguous::multiset<V, std::less<>> M;

    typedef M::iterator R;
    M m;
    m.insert ( V::make ( 5 ));
    m.insert ( V::make ( 5 ));
    m.insert ( V::make ( 5 ));
    m.insert ( V::make ( 7 ));
    m.insert ( V::make ( 7 ));
    m.insert ( V::make ( 7 ));
    m.insert ( V::make ( 9 ));
    m.insert ( V::make ( 9 ));
    m.insert ( V::make ( 9 ));

    R r = m.upper_bound(4);
    REQUIRE(r == next(m.begin(), 0));
    r = m.upper_bound(5);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(6);
    REQUIRE(r == next(m.begin(), 3));
    r = m.upper_bound(7);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(8);
    REQUIRE(r == next(m.begin(), 6));
    r = m.upper_bound(9);
    REQUIRE(r == next(m.begin(), 9));
    r = m.upper_bound(11);
    REQUIRE(r == next(m.begin(), 9));
    }
#endif
}
