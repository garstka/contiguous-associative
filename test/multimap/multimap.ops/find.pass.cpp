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

//       iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "min_allocator.h"
#include "private_constructor.hpp"
#include "is_transparent.h"

TEST_CASE("multimap ops find pass")
{
    typedef std::pair<const int, double> V;
    {
    typedef contiguous::multimap<int, double> M;
    {
        typedef M::iterator R;
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
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.find(5);
        REQUIRE(r == m.begin());
        r = m.find(6);
        REQUIRE(r == m.end());
        r = m.find(7);
        REQUIRE(r == next(m.begin(), 3));
        r = m.find(8);
        REQUIRE(r == m.end());
        r = m.find(9);
        REQUIRE(r == next(m.begin(), 6));
        r = m.find(10);
        REQUIRE(r == m.end());
    }
    {
        typedef M::const_iterator R;
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
        R r = m.find(5);
        REQUIRE(r == m.begin());
        r = m.find(6);
        REQUIRE(r == m.end());
        r = m.find(7);
        REQUIRE(r == next(m.begin(), 3));
        r = m.find(8);
        REQUIRE(r == m.end());
        r = m.find(9);
        REQUIRE(r == next(m.begin(), 6));
        r = m.find(10);
        REQUIRE(r == m.end());
    }
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::multimap<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
    {
        typedef M::iterator R;
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
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.find(5);
        REQUIRE(r == m.begin());
        r = m.find(6);
        REQUIRE(r == m.end());
        r = m.find(7);
        REQUIRE(r == next(m.begin(), 3));
        r = m.find(8);
        REQUIRE(r == m.end());
        r = m.find(9);
        REQUIRE(r == next(m.begin(), 6));
        r = m.find(10);
        REQUIRE(r == m.end());
    }
    {
        typedef M::const_iterator R;
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
        R r = m.find(5);
        REQUIRE(r == m.begin());
        r = m.find(6);
        REQUIRE(r == m.end());
        r = m.find(7);
        REQUIRE(r == next(m.begin(), 3));
        r = m.find(8);
        REQUIRE(r == m.end());
        r = m.find(9);
        REQUIRE(r == next(m.begin(), 6));
        r = m.find(10);
        REQUIRE(r == m.end());
    }
    }
#endif
#if LIBCPP_STD_VER > 11
    {
    typedef std::pair<const int, double> V;
    typedef contiguous::multimap<int, double, std::less<>> M;
    typedef M::iterator R;

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
        M m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        R r = m.find(5);
        REQUIRE(r == m.begin());
        r = m.find(6);
        REQUIRE(r == m.end());
        r = m.find(7);
        REQUIRE(r == next(m.begin(), 3));
        r = m.find(8);
        REQUIRE(r == m.end());
        r = m.find(9);
        REQUIRE(r == next(m.begin(), 6));
        r = m.find(10);
        REQUIRE(r == m.end());

        r = m.find(C2Int(5));
        REQUIRE(r == m.begin());
        r = m.find(C2Int(6));
        REQUIRE(r == m.end());
        r = m.find(C2Int(7));
        REQUIRE(r == next(m.begin(), 3));
        r = m.find(C2Int(8));
        REQUIRE(r == m.end());
        r = m.find(C2Int(9));
        REQUIRE(r == next(m.begin(), 6));
        r = m.find(C2Int(10));
        REQUIRE(r == m.end());
    }

    {
    typedef PrivateConstructor PC;
    typedef contiguous::multimap<PC, double, std::less<>> M;
    typedef M::iterator R;

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

    R r = m.find(5);
    REQUIRE(r == m.begin());
    r = m.find(6);
    REQUIRE(r == m.end());
    r = m.find(7);
    REQUIRE(r == next(m.begin(), 3));
    r = m.find(8);
    REQUIRE(r == m.end());
    r = m.find(9);
    REQUIRE(r == next(m.begin(), 6));
    r = m.find(10);
    REQUIRE(r == m.end());
    }
#endif
}
