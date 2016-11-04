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

// pair<iterator,iterator>             equal_range(const key_type& k);
// pair<const_iterator,const_iterator> equal_range(const key_type& k) const;

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"

TEST_CASE("set equal range pass")
{
    {
    typedef int V;
    typedef contiguous::set<int> M;
    {
        typedef std::pair<M::iterator, M::iterator> R;
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
        R r = m.equal_range(5);
        REQUIRE(r.first == next(m.begin(), 0));
        REQUIRE(r.second == next(m.begin(), 1));
        r = m.equal_range(7);
        REQUIRE(r.first == next(m.begin(), 1));
        REQUIRE(r.second == next(m.begin(), 2));
        r = m.equal_range(9);
        REQUIRE(r.first == next(m.begin(), 2));
        REQUIRE(r.second == next(m.begin(), 3));
        r = m.equal_range(11);
        REQUIRE(r.first == next(m.begin(), 3));
        REQUIRE(r.second == next(m.begin(), 4));
        r = m.equal_range(13);
        REQUIRE(r.first == next(m.begin(), 4));
        REQUIRE(r.second == next(m.begin(), 5));
        r = m.equal_range(15);
        REQUIRE(r.first == next(m.begin(), 5));
        REQUIRE(r.second == next(m.begin(), 6));
        r = m.equal_range(17);
        REQUIRE(r.first == next(m.begin(), 6));
        REQUIRE(r.second == next(m.begin(), 7));
        r = m.equal_range(19);
        REQUIRE(r.first == next(m.begin(), 7));
        REQUIRE(r.second == next(m.begin(), 8));
        r = m.equal_range(4);
        REQUIRE(r.first == next(m.begin(), 0));
        REQUIRE(r.second == next(m.begin(), 0));
        r = m.equal_range(6);
        REQUIRE(r.first == next(m.begin(), 1));
        REQUIRE(r.second == next(m.begin(), 1));
        r = m.equal_range(8);
        REQUIRE(r.first == next(m.begin(), 2));
        REQUIRE(r.second == next(m.begin(), 2));
        r = m.equal_range(10);
        REQUIRE(r.first == next(m.begin(), 3));
        REQUIRE(r.second == next(m.begin(), 3));
        r = m.equal_range(12);
        REQUIRE(r.first == next(m.begin(), 4));
        REQUIRE(r.second == next(m.begin(), 4));
        r = m.equal_range(14);
        REQUIRE(r.first == next(m.begin(), 5));
        REQUIRE(r.second == next(m.begin(), 5));
        r = m.equal_range(16);
        REQUIRE(r.first == next(m.begin(), 6));
        REQUIRE(r.second == next(m.begin(), 6));
        r = m.equal_range(18);
        REQUIRE(r.first == next(m.begin(), 7));
        REQUIRE(r.second == next(m.begin(), 7));
        r = m.equal_range(20);
        REQUIRE(r.first == next(m.begin(), 8));
        REQUIRE(r.second == next(m.begin(), 8));
    }
    {
        typedef std::pair<M::const_iterator, M::const_iterator> R;
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
        R r = m.equal_range(5);
        REQUIRE(r.first == next(m.begin(), 0));
        REQUIRE(r.second == next(m.begin(), 1));
        r = m.equal_range(7);
        REQUIRE(r.first == next(m.begin(), 1));
        REQUIRE(r.second == next(m.begin(), 2));
        r = m.equal_range(9);
        REQUIRE(r.first == next(m.begin(), 2));
        REQUIRE(r.second == next(m.begin(), 3));
        r = m.equal_range(11);
        REQUIRE(r.first == next(m.begin(), 3));
        REQUIRE(r.second == next(m.begin(), 4));
        r = m.equal_range(13);
        REQUIRE(r.first == next(m.begin(), 4));
        REQUIRE(r.second == next(m.begin(), 5));
        r = m.equal_range(15);
        REQUIRE(r.first == next(m.begin(), 5));
        REQUIRE(r.second == next(m.begin(), 6));
        r = m.equal_range(17);
        REQUIRE(r.first == next(m.begin(), 6));
        REQUIRE(r.second == next(m.begin(), 7));
        r = m.equal_range(19);
        REQUIRE(r.first == next(m.begin(), 7));
        REQUIRE(r.second == next(m.begin(), 8));
        r = m.equal_range(4);
        REQUIRE(r.first == next(m.begin(), 0));
        REQUIRE(r.second == next(m.begin(), 0));
        r = m.equal_range(6);
        REQUIRE(r.first == next(m.begin(), 1));
        REQUIRE(r.second == next(m.begin(), 1));
        r = m.equal_range(8);
        REQUIRE(r.first == next(m.begin(), 2));
        REQUIRE(r.second == next(m.begin(), 2));
        r = m.equal_range(10);
        REQUIRE(r.first == next(m.begin(), 3));
        REQUIRE(r.second == next(m.begin(), 3));
        r = m.equal_range(12);
        REQUIRE(r.first == next(m.begin(), 4));
        REQUIRE(r.second == next(m.begin(), 4));
        r = m.equal_range(14);
        REQUIRE(r.first == next(m.begin(), 5));
        REQUIRE(r.second == next(m.begin(), 5));
        r = m.equal_range(16);
        REQUIRE(r.first == next(m.begin(), 6));
        REQUIRE(r.second == next(m.begin(), 6));
        r = m.equal_range(18);
        REQUIRE(r.first == next(m.begin(), 7));
        REQUIRE(r.second == next(m.begin(), 7));
        r = m.equal_range(20);
        REQUIRE(r.first == next(m.begin(), 8));
        REQUIRE(r.second == next(m.begin(), 8));
    }
    }
#if TEST_STD_VER >= 11
    {
    typedef int V;
    typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
    typedef std::pair<M::iterator, M::iterator> R;
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
    R r = m.equal_range(5);
    REQUIRE(r.first == next(m.begin(), 0));
    REQUIRE(r.second == next(m.begin(), 1));
    r = m.equal_range(7);
    REQUIRE(r.first == next(m.begin(), 1));
    REQUIRE(r.second == next(m.begin(), 2));
    r = m.equal_range(9);
    REQUIRE(r.first == next(m.begin(), 2));
    REQUIRE(r.second == next(m.begin(), 3));
    r = m.equal_range(11);
    REQUIRE(r.first == next(m.begin(), 3));
    REQUIRE(r.second == next(m.begin(), 4));
    r = m.equal_range(13);
    REQUIRE(r.first == next(m.begin(), 4));
    REQUIRE(r.second == next(m.begin(), 5));
    r = m.equal_range(15);
    REQUIRE(r.first == next(m.begin(), 5));
    REQUIRE(r.second == next(m.begin(), 6));
    r = m.equal_range(17);
    REQUIRE(r.first == next(m.begin(), 6));
    REQUIRE(r.second == next(m.begin(), 7));
    r = m.equal_range(19);
    REQUIRE(r.first == next(m.begin(), 7));
    REQUIRE(r.second == next(m.begin(), 8));
    r = m.equal_range(4);
    REQUIRE(r.first == next(m.begin(), 0));
    REQUIRE(r.second == next(m.begin(), 0));
    r = m.equal_range(6);
    REQUIRE(r.first == next(m.begin(), 1));
    REQUIRE(r.second == next(m.begin(), 1));
    r = m.equal_range(8);
    REQUIRE(r.first == next(m.begin(), 2));
    REQUIRE(r.second == next(m.begin(), 2));
    r = m.equal_range(10);
    REQUIRE(r.first == next(m.begin(), 3));
    REQUIRE(r.second == next(m.begin(), 3));
    r = m.equal_range(12);
    REQUIRE(r.first == next(m.begin(), 4));
    REQUIRE(r.second == next(m.begin(), 4));
    r = m.equal_range(14);
    REQUIRE(r.first == next(m.begin(), 5));
    REQUIRE(r.second == next(m.begin(), 5));
    r = m.equal_range(16);
    REQUIRE(r.first == next(m.begin(), 6));
    REQUIRE(r.second == next(m.begin(), 6));
    r = m.equal_range(18);
    REQUIRE(r.first == next(m.begin(), 7));
    REQUIRE(r.second == next(m.begin(), 7));
    r = m.equal_range(20);
    REQUIRE(r.first == next(m.begin(), 8));
    REQUIRE(r.second == next(m.begin(), 8));
    }
#endif
#if LIBCPP_STD_VER > 11
    {
    typedef int V;
    typedef contiguous::set<V, std::less<>> M;
    {
        typedef std::pair<M::iterator, M::iterator> R;
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
        R r = m.equal_range(5);
        REQUIRE(r.first == next(m.begin(), 0));
        REQUIRE(r.second == next(m.begin(), 1));
        r = m.equal_range(7);
        REQUIRE(r.first == next(m.begin(), 1));
        REQUIRE(r.second == next(m.begin(), 2));
        r = m.equal_range(9);
        REQUIRE(r.first == next(m.begin(), 2));
        REQUIRE(r.second == next(m.begin(), 3));
        r = m.equal_range(11);
        REQUIRE(r.first == next(m.begin(), 3));
        REQUIRE(r.second == next(m.begin(), 4));
        r = m.equal_range(13);
        REQUIRE(r.first == next(m.begin(), 4));
        REQUIRE(r.second == next(m.begin(), 5));
        r = m.equal_range(15);
        REQUIRE(r.first == next(m.begin(), 5));
        REQUIRE(r.second == next(m.begin(), 6));
        r = m.equal_range(17);
        REQUIRE(r.first == next(m.begin(), 6));
        REQUIRE(r.second == next(m.begin(), 7));
        r = m.equal_range(19);
        REQUIRE(r.first == next(m.begin(), 7));
        REQUIRE(r.second == next(m.begin(), 8));
        r = m.equal_range(4);
        REQUIRE(r.first == next(m.begin(), 0));
        REQUIRE(r.second == next(m.begin(), 0));
        r = m.equal_range(6);
        REQUIRE(r.first == next(m.begin(), 1));
        REQUIRE(r.second == next(m.begin(), 1));
        r = m.equal_range(8);
        REQUIRE(r.first == next(m.begin(), 2));
        REQUIRE(r.second == next(m.begin(), 2));
        r = m.equal_range(10);
        REQUIRE(r.first == next(m.begin(), 3));
        REQUIRE(r.second == next(m.begin(), 3));
        r = m.equal_range(12);
        REQUIRE(r.first == next(m.begin(), 4));
        REQUIRE(r.second == next(m.begin(), 4));
        r = m.equal_range(14);
        REQUIRE(r.first == next(m.begin(), 5));
        REQUIRE(r.second == next(m.begin(), 5));
        r = m.equal_range(16);
        REQUIRE(r.first == next(m.begin(), 6));
        REQUIRE(r.second == next(m.begin(), 6));
        r = m.equal_range(18);
        REQUIRE(r.first == next(m.begin(), 7));
        REQUIRE(r.second == next(m.begin(), 7));
        r = m.equal_range(20);
        REQUIRE(r.first == next(m.begin(), 8));
        REQUIRE(r.second == next(m.begin(), 8));
        }
    }
    {
    typedef PrivateConstructor V;
    typedef contiguous::set<V, std::less<>> M;
    typedef std::pair<M::iterator, M::iterator> R;

    M m;
    m.insert ( V::make ( 5 ));
    m.insert ( V::make ( 7 ));
    m.insert ( V::make ( 9 ));
    m.insert ( V::make ( 11 ));
    m.insert ( V::make ( 13 ));
    m.insert ( V::make ( 15 ));
    m.insert ( V::make ( 17 ));
    m.insert ( V::make ( 19 ));

    R r = m.equal_range(5);
    REQUIRE(r.first == next(m.begin(), 0));
    REQUIRE(r.second == next(m.begin(), 1));
    r = m.equal_range(7);
    REQUIRE(r.first == next(m.begin(), 1));
    REQUIRE(r.second == next(m.begin(), 2));
    r = m.equal_range(9);
    REQUIRE(r.first == next(m.begin(), 2));
    REQUIRE(r.second == next(m.begin(), 3));
    r = m.equal_range(11);
    REQUIRE(r.first == next(m.begin(), 3));
    REQUIRE(r.second == next(m.begin(), 4));
    r = m.equal_range(13);
    REQUIRE(r.first == next(m.begin(), 4));
    REQUIRE(r.second == next(m.begin(), 5));
    r = m.equal_range(15);
    REQUIRE(r.first == next(m.begin(), 5));
    REQUIRE(r.second == next(m.begin(), 6));
    r = m.equal_range(17);
    REQUIRE(r.first == next(m.begin(), 6));
    REQUIRE(r.second == next(m.begin(), 7));
    r = m.equal_range(19);
    REQUIRE(r.first == next(m.begin(), 7));
    REQUIRE(r.second == next(m.begin(), 8));
    r = m.equal_range(4);
    REQUIRE(r.first == next(m.begin(), 0));
    REQUIRE(r.second == next(m.begin(), 0));
    r = m.equal_range(6);
    REQUIRE(r.first == next(m.begin(), 1));
    REQUIRE(r.second == next(m.begin(), 1));
    r = m.equal_range(8);
    REQUIRE(r.first == next(m.begin(), 2));
    REQUIRE(r.second == next(m.begin(), 2));
    r = m.equal_range(10);
    REQUIRE(r.first == next(m.begin(), 3));
    REQUIRE(r.second == next(m.begin(), 3));
    r = m.equal_range(12);
    REQUIRE(r.first == next(m.begin(), 4));
    REQUIRE(r.second == next(m.begin(), 4));
    r = m.equal_range(14);
    REQUIRE(r.first == next(m.begin(), 5));
    REQUIRE(r.second == next(m.begin(), 5));
    r = m.equal_range(16);
    REQUIRE(r.first == next(m.begin(), 6));
    REQUIRE(r.second == next(m.begin(), 6));
    r = m.equal_range(18);
    REQUIRE(r.first == next(m.begin(), 7));
    REQUIRE(r.second == next(m.begin(), 7));
    r = m.equal_range(20);
    REQUIRE(r.first == next(m.begin(), 8));
    REQUIRE(r.second == next(m.begin(), 8));
    }
#endif
}
