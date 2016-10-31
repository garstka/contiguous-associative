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

// size_type count(const key_type& k) const;

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"
#include "is_transparent.h"

TEST_CASE("multimap ops count pass")
{
    typedef std::pair<const int, double> V;
    {
    typedef contiguous::multimap<int, double> M;
    {
        typedef M::size_type R;
        V ar[] =
        {
            V(5, 1),
            V(5, 2),
            V(5, 3),
            V(7, 1),
            V(7, 2),
            V(7, 3),
            V(9, 1),
            V(9, 2),
            V(9, 3)
        };
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.count(4);
        REQUIRE(r == 0);
        r = m.count(5);
        REQUIRE(r == 3);
        r = m.count(6);
        REQUIRE(r == 0);
        r = m.count(7);
        REQUIRE(r == 3);
        r = m.count(8);
        REQUIRE(r == 0);
        r = m.count(9);
        REQUIRE(r == 3);
        r = m.count(10);
        REQUIRE(r == 0);
    }
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::multimap<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
    {
        typedef M::size_type R;
        V ar[] =
        {
            V(5, 1),
            V(5, 2),
            V(5, 3),
            V(7, 1),
            V(7, 2),
            V(7, 3),
            V(9, 1),
            V(9, 2),
            V(9, 3)
        };
        const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.count(4);
        REQUIRE(r == 0);
        r = m.count(5);
        REQUIRE(r == 3);
        r = m.count(6);
        REQUIRE(r == 0);
        r = m.count(7);
        REQUIRE(r == 3);
        r = m.count(8);
        REQUIRE(r == 0);
        r = m.count(9);
        REQUIRE(r == 3);
        r = m.count(10);
        REQUIRE(r == 0);
    }
    }
#endif

#if _LIBCPP_STD_VER > 11
    {
    typedef contiguous::multimap<int, double, std::less<>> M;
    typedef M::size_type R;
    V ar[] =
    {
        V(5, 1),
        V(5, 2),
        V(5, 3),
        V(7, 1),
        V(7, 2),
        V(7, 3),
        V(9, 1),
        V(9, 2),
        V(9, 3)
    };
    const M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
    R r = m.count(4);
    REQUIRE(r == 0);
    r = m.count(5);
    REQUIRE(r == 3);
    r = m.count(6);
    REQUIRE(r == 0);
    r = m.count(7);
    REQUIRE(r == 3);
    r = m.count(8);
    REQUIRE(r == 0);
    r = m.count(9);
    REQUIRE(r == 3);
    r = m.count(10);
    REQUIRE(r == 0);

    r = m.count(C2Int(4));
    REQUIRE(r == 0);
    r = m.count(C2Int(5));
    REQUIRE(r == 3);
    r = m.count(C2Int(6));
    REQUIRE(r == 0);
    r = m.count(C2Int(7));
    REQUIRE(r == 3);
    r = m.count(C2Int(8));
    REQUIRE(r == 0);
    r = m.count(C2Int(9));
    REQUIRE(r == 3);
    r = m.count(C2Int(10));
    REQUIRE(r == 0);
    }

    {
    typedef PrivateConstructor PC;
    typedef contiguous::multimap<PC, double, std::less<>> M;
    typedef M::size_type R;

    M m;
    m.insert ( std::make_pair<PC, double> ( PC::make(5), 1 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(5), 2 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(5), 3 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(7), 1 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(7), 2 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(7), 3 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(9), 1 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(9), 2 ));
    m.insert ( std::make_pair<PC, double> ( PC::make(9), 3 ));

    R r = m.count(4);
    REQUIRE(r == 0);
    r = m.count(5);
    REQUIRE(r == 3);
    r = m.count(6);
    REQUIRE(r == 0);
    r = m.count(7);
    REQUIRE(r == 3);
    r = m.count(8);
    REQUIRE(r == 0);
    r = m.count(9);
    REQUIRE(r == 3);
    r = m.count(10);
    REQUIRE(r == 0);
    }
#endif
}
