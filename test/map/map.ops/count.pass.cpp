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

// size_type count(const key_type& k) const;

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"
#include "is_transparent.h"

TEST_CASE("map ops count pass")
{
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double> M;
    {
        typedef M::size_type R;
        V ar[] =
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
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.count(5);
        REQUIRE(r == 1);
        r = m.count(6);
        REQUIRE(r == 1);
        r = m.count(7);
        REQUIRE(r == 1);
        r = m.count(8);
        REQUIRE(r == 1);
        r = m.count(9);
        REQUIRE(r == 1);
        r = m.count(10);
        REQUIRE(r == 1);
        r = m.count(11);
        REQUIRE(r == 1);
        r = m.count(12);
        REQUIRE(r == 1);
        r = m.count(4);
        REQUIRE(r == 0);
    }
    }
#if TEST_STD_VER >= 11
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double, std::less<int>, min_allocator<V>> M;
    {
        typedef M::size_type R;
        V ar[] =
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
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.count(5);
        REQUIRE(r == 1);
        r = m.count(6);
        REQUIRE(r == 1);
        r = m.count(7);
        REQUIRE(r == 1);
        r = m.count(8);
        REQUIRE(r == 1);
        r = m.count(9);
        REQUIRE(r == 1);
        r = m.count(10);
        REQUIRE(r == 1);
        r = m.count(11);
        REQUIRE(r == 1);
        r = m.count(12);
        REQUIRE(r == 1);
        r = m.count(4);
        REQUIRE(r == 0);
    }
    }
#endif
#if LIBCPP_STD_VER > 11
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::map<int, double, std::less <>> M;
    typedef M::size_type R;

    V ar[] =
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
    const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
    R r = m.count(5);
    REQUIRE(r == 1);
    r = m.count(6);
    REQUIRE(r == 1);
    r = m.count(7);
    REQUIRE(r == 1);
    r = m.count(8);
    REQUIRE(r == 1);
    r = m.count(9);
    REQUIRE(r == 1);
    r = m.count(10);
    REQUIRE(r == 1);
    r = m.count(11);
    REQUIRE(r == 1);
    r = m.count(12);
    REQUIRE(r == 1);
    r = m.count(4);
    REQUIRE(r == 0);

    r = m.count(C2Int(5));
    REQUIRE(r == 1);
    r = m.count(C2Int(6));
    REQUIRE(r == 1);
    r = m.count(C2Int(7));
    REQUIRE(r == 1);
    r = m.count(C2Int(8));
    REQUIRE(r == 1);
    r = m.count(C2Int(9));
    REQUIRE(r == 1);
    r = m.count(C2Int(10));
    REQUIRE(r == 1);
    r = m.count(C2Int(11));
    REQUIRE(r == 1);
    r = m.count(C2Int(12));
    REQUIRE(r == 1);
    r = m.count(C2Int(4));
    REQUIRE(r == 0);
    }

    {
    typedef PrivateConstructor PC;
    typedef contiguous::map<PC, double, std::less<>> M;
    typedef M::size_type R;

    M m;
    m [ PC::make(5)  ] = 5;
    m [ PC::make(6)  ] = 6;
    m [ PC::make(7)  ] = 7;
    m [ PC::make(8)  ] = 8;
    m [ PC::make(9)  ] = 9;
    m [ PC::make(10) ] = 10;
    m [ PC::make(11) ] = 11;
    m [ PC::make(12) ] = 12;

    R r = m.count(5);
    REQUIRE(r == 1);
    r = m.count(6);
    REQUIRE(r == 1);
    r = m.count(7);
    REQUIRE(r == 1);
    r = m.count(8);
    REQUIRE(r == 1);
    r = m.count(9);
    REQUIRE(r == 1);
    r = m.count(10);
    REQUIRE(r == 1);
    r = m.count(11);
    REQUIRE(r == 1);
    r = m.count(12);
    REQUIRE(r == 1);
    r = m.count(4);
    REQUIRE(r == 0);
    }
#endif
}
