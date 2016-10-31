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

// pair<iterator,iterator>             equal_range(const key_type& k);
// pair<const_iterator,const_iterator> equal_range(const key_type& k) const;

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"
#include "is_transparent.h"

TEST_CASE("map ops equal range pass")
{
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double> M;
    {
        typedef std::pair<M::iterator, M::iterator> R;
        V ar[] =
        {
            V(5, 5),
            V(7, 6),
            V(9, 7),
            V(11, 8),
            V(13, 9),
            V(15, 10),
            V(17, 11),
            V(19, 12)
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
            V(5, 5),
            V(7, 6),
            V(9, 7),
            V(11, 8),
            V(13, 9),
            V(15, 10),
            V(17, 11),
            V(19, 12)
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
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double, std::less<int>, min_allocator<V>> M;
    {
        typedef std::pair<M::iterator, M::iterator> R;
        V ar[] =
        {
            V(5, 5),
            V(7, 6),
            V(9, 7),
            V(11, 8),
            V(13, 9),
            V(15, 10),
            V(17, 11),
            V(19, 12)
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
            V(5, 5),
            V(7, 6),
            V(9, 7),
            V(11, 8),
            V(13, 9),
            V(15, 10),
            V(17, 11),
            V(19, 12)
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
#endif
#if _LIBCPP_STD_VER > 11
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double, std::less<>> M;
    typedef std::pair<M::iterator, M::iterator> R;

    V ar[] =
    {
        V(5, 5),
        V(7, 6),
        V(9, 7),
        V(11, 8),
        V(13, 9),
        V(15, 10),
        V(17, 11),
        V(19, 12)
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

    r = m.equal_range(C2Int(5));
    REQUIRE(r.first == next(m.begin(), 0));
    REQUIRE(r.second == next(m.begin(), 1));
    r = m.equal_range(C2Int(7));
    REQUIRE(r.first == next(m.begin(), 1));
    REQUIRE(r.second == next(m.begin(), 2));
    r = m.equal_range(C2Int(9));
    REQUIRE(r.first == next(m.begin(), 2));
    REQUIRE(r.second == next(m.begin(), 3));
    r = m.equal_range(C2Int(11));
    REQUIRE(r.first == next(m.begin(), 3));
    REQUIRE(r.second == next(m.begin(), 4));
    r = m.equal_range(C2Int(13));
    REQUIRE(r.first == next(m.begin(), 4));
    REQUIRE(r.second == next(m.begin(), 5));
    r = m.equal_range(C2Int(15));
    REQUIRE(r.first == next(m.begin(), 5));
    REQUIRE(r.second == next(m.begin(), 6));
    r = m.equal_range(C2Int(17));
    REQUIRE(r.first == next(m.begin(), 6));
    REQUIRE(r.second == next(m.begin(), 7));
    r = m.equal_range(C2Int(19));
    REQUIRE(r.first == next(m.begin(), 7));
    REQUIRE(r.second == next(m.begin(), 8));
    r = m.equal_range(C2Int(4));
    REQUIRE(r.first == next(m.begin(), 0));
    REQUIRE(r.second == next(m.begin(), 0));
    r = m.equal_range(C2Int(6));
    REQUIRE(r.first == next(m.begin(), 1));
    REQUIRE(r.second == next(m.begin(), 1));
    r = m.equal_range(C2Int(8));
    REQUIRE(r.first == next(m.begin(), 2));
    REQUIRE(r.second == next(m.begin(), 2));
    r = m.equal_range(C2Int(10));
    REQUIRE(r.first == next(m.begin(), 3));
    REQUIRE(r.second == next(m.begin(), 3));
    r = m.equal_range(C2Int(12));
    REQUIRE(r.first == next(m.begin(), 4));
    REQUIRE(r.second == next(m.begin(), 4));
    r = m.equal_range(C2Int(14));
    REQUIRE(r.first == next(m.begin(), 5));
    REQUIRE(r.second == next(m.begin(), 5));
    r = m.equal_range(C2Int(16));
    REQUIRE(r.first == next(m.begin(), 6));
    REQUIRE(r.second == next(m.begin(), 6));
    r = m.equal_range(C2Int(18));
    REQUIRE(r.first == next(m.begin(), 7));
    REQUIRE(r.second == next(m.begin(), 7));
    r = m.equal_range(C2Int(20));
    REQUIRE(r.first == next(m.begin(), 8));
    REQUIRE(r.second == next(m.begin(), 8));
    }
    {
    typedef PrivateConstructor PC;
    typedef contiguous::map<PC, double, std::less<>> M;
    typedef std::pair<M::iterator, M::iterator> R;

    M m;
    m [ PC::make(5)  ] = 5;
    m [ PC::make(7)  ] = 6;
    m [ PC::make(9)  ] = 7;
    m [ PC::make(11) ] = 8;
    m [ PC::make(13) ] = 9;
    m [ PC::make(15) ] = 10;
    m [ PC::make(17) ] = 11;
    m [ PC::make(19) ] = 12;

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
