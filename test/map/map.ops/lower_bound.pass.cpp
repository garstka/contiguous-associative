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

//       iterator lower_bound(const key_type& k);
// const_iterator lower_bound(const key_type& k) const;

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"
#include "is_transparent.h"

TEST_CASE("map ops lower bound pass")
{
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double> M;
    {
        typedef M::iterator R;
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
        R r = m.lower_bound(5);
        REQUIRE(r == m.begin());
        r = m.lower_bound(7);
        REQUIRE(r == next(m.begin()));
        r = m.lower_bound(9);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(11);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(13);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(15);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(17);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(19);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.lower_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.lower_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    {
        typedef M::const_iterator R;
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
        R r = m.lower_bound(5);
        REQUIRE(r == m.begin());
        r = m.lower_bound(7);
        REQUIRE(r == next(m.begin()));
        r = m.lower_bound(9);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(11);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(13);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(15);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(17);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(19);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.lower_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.lower_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    }
#if TEST_STD_VER >= 11
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double, std::less<int>, min_allocator<V>> M;
    {
        typedef M::iterator R;
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
        R r = m.lower_bound(5);
        REQUIRE(r == m.begin());
        r = m.lower_bound(7);
        REQUIRE(r == next(m.begin()));
        r = m.lower_bound(9);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(11);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(13);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(15);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(17);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(19);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.lower_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.lower_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    {
        typedef M::const_iterator R;
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
        R r = m.lower_bound(5);
        REQUIRE(r == m.begin());
        r = m.lower_bound(7);
        REQUIRE(r == next(m.begin()));
        r = m.lower_bound(9);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(11);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(13);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(15);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(17);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(19);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(4);
        REQUIRE(r == next(m.begin(), 0));
        r = m.lower_bound(6);
        REQUIRE(r == next(m.begin(), 1));
        r = m.lower_bound(8);
        REQUIRE(r == next(m.begin(), 2));
        r = m.lower_bound(10);
        REQUIRE(r == next(m.begin(), 3));
        r = m.lower_bound(12);
        REQUIRE(r == next(m.begin(), 4));
        r = m.lower_bound(14);
        REQUIRE(r == next(m.begin(), 5));
        r = m.lower_bound(16);
        REQUIRE(r == next(m.begin(), 6));
        r = m.lower_bound(18);
        REQUIRE(r == next(m.begin(), 7));
        r = m.lower_bound(20);
        REQUIRE(r == next(m.begin(), 8));
    }
    }
#endif
#if LIBCPP_STD_VER > 11
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double, std::less <>> M;
    typedef M::iterator R;

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
    R r = m.lower_bound(5);
    REQUIRE(r == m.begin());
    r = m.lower_bound(7);
    REQUIRE(r == next(m.begin()));
    r = m.lower_bound(9);
    REQUIRE(r == next(m.begin(), 2));
    r = m.lower_bound(11);
    REQUIRE(r == next(m.begin(), 3));
    r = m.lower_bound(13);
    REQUIRE(r == next(m.begin(), 4));
    r = m.lower_bound(15);
    REQUIRE(r == next(m.begin(), 5));
    r = m.lower_bound(17);
    REQUIRE(r == next(m.begin(), 6));
    r = m.lower_bound(19);
    REQUIRE(r == next(m.begin(), 7));
    r = m.lower_bound(4);
    REQUIRE(r == next(m.begin(), 0));
    r = m.lower_bound(6);
    REQUIRE(r == next(m.begin(), 1));
    r = m.lower_bound(8);
    REQUIRE(r == next(m.begin(), 2));
    r = m.lower_bound(10);
    REQUIRE(r == next(m.begin(), 3));
    r = m.lower_bound(12);
    REQUIRE(r == next(m.begin(), 4));
    r = m.lower_bound(14);
    REQUIRE(r == next(m.begin(), 5));
    r = m.lower_bound(16);
    REQUIRE(r == next(m.begin(), 6));
    r = m.lower_bound(18);
    REQUIRE(r == next(m.begin(), 7));
    r = m.lower_bound(20);
    REQUIRE(r == next(m.begin(), 8));

    r = m.lower_bound(C2Int(5));
    REQUIRE(r == m.begin());
    r = m.lower_bound(C2Int(7));
    REQUIRE(r == next(m.begin()));
    r = m.lower_bound(C2Int(9));
    REQUIRE(r == next(m.begin(), 2));
    r = m.lower_bound(C2Int(11));
    REQUIRE(r == next(m.begin(), 3));
    r = m.lower_bound(C2Int(13));
    REQUIRE(r == next(m.begin(), 4));
    r = m.lower_bound(C2Int(15));
    REQUIRE(r == next(m.begin(), 5));
    r = m.lower_bound(C2Int(17));
    REQUIRE(r == next(m.begin(), 6));
    r = m.lower_bound(C2Int(19));
    REQUIRE(r == next(m.begin(), 7));
    r = m.lower_bound(C2Int(4));
    REQUIRE(r == next(m.begin(), 0));
    r = m.lower_bound(C2Int(6));
    REQUIRE(r == next(m.begin(), 1));
    r = m.lower_bound(C2Int(8));
    REQUIRE(r == next(m.begin(), 2));
    r = m.lower_bound(C2Int(10));
    REQUIRE(r == next(m.begin(), 3));
    r = m.lower_bound(C2Int(12));
    REQUIRE(r == next(m.begin(), 4));
    r = m.lower_bound(C2Int(14));
    REQUIRE(r == next(m.begin(), 5));
    r = m.lower_bound(C2Int(16));
    REQUIRE(r == next(m.begin(), 6));
    r = m.lower_bound(C2Int(18));
    REQUIRE(r == next(m.begin(), 7));
    r = m.lower_bound(C2Int(20));
    REQUIRE(r == next(m.begin(), 8));
    }

    {
    typedef PrivateConstructor PC;
    typedef contiguous::map<PC, double, std::less<>> M;
    typedef M::iterator R;

    M m;
    m [ PC::make(5)  ] = 5;
    m [ PC::make(7)  ] = 6;
    m [ PC::make(9)  ] = 7;
    m [ PC::make(11) ] = 8;
    m [ PC::make(13) ] = 9;
    m [ PC::make(15) ] = 10;
    m [ PC::make(17) ] = 11;
    m [ PC::make(19) ] = 12;

    R r = m.lower_bound(5);
    REQUIRE(r == m.begin());
    r = m.lower_bound(7);
    REQUIRE(r == next(m.begin()));
    r = m.lower_bound(9);
    REQUIRE(r == next(m.begin(), 2));
    r = m.lower_bound(11);
    REQUIRE(r == next(m.begin(), 3));
    r = m.lower_bound(13);
    REQUIRE(r == next(m.begin(), 4));
    r = m.lower_bound(15);
    REQUIRE(r == next(m.begin(), 5));
    r = m.lower_bound(17);
    REQUIRE(r == next(m.begin(), 6));
    r = m.lower_bound(19);
    REQUIRE(r == next(m.begin(), 7));
    r = m.lower_bound(4);
    REQUIRE(r == next(m.begin(), 0));
    r = m.lower_bound(6);
    REQUIRE(r == next(m.begin(), 1));
    r = m.lower_bound(8);
    REQUIRE(r == next(m.begin(), 2));
    r = m.lower_bound(10);
    REQUIRE(r == next(m.begin(), 3));
    r = m.lower_bound(12);
    REQUIRE(r == next(m.begin(), 4));
    r = m.lower_bound(14);
    REQUIRE(r == next(m.begin(), 5));
    r = m.lower_bound(16);
    REQUIRE(r == next(m.begin(), 6));
    r = m.lower_bound(18);
    REQUIRE(r == next(m.begin(), 7));
    r = m.lower_bound(20);
    REQUIRE(r == next(m.begin(), 8));
    }
#endif
}
