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

// size_type erase(const key_type& k);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("map modifiers erase key pass")
{
    {
        typedef contiguous::map<int, double> M;
        typedef std::pair<int, double> P;
        typedef M::size_type R;
        P ar[] =
        {
            P(1, 1.5),
            P(2, 2.5),
            P(3, 3.5),
            P(4, 4.5),
            P(5, 5.5),
            P(6, 6.5),
            P(7, 7.5),
            P(8, 8.5),
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 8);
        R s = m.erase(9);
        REQUIRE(s == 0);
        REQUIRE(m.size() == 8);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == 1.5);
        REQUIRE(next(m.begin())->first == 2);
        REQUIRE(next(m.begin())->second == 2.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 3.5);
        REQUIRE(next(m.begin(), 3)->first == 4);
        REQUIRE(next(m.begin(), 3)->second == 4.5);
        REQUIRE(next(m.begin(), 4)->first == 5);
        REQUIRE(next(m.begin(), 4)->second == 5.5);
        REQUIRE(next(m.begin(), 5)->first == 6);
        REQUIRE(next(m.begin(), 5)->second == 6.5);
        REQUIRE(next(m.begin(), 6)->first == 7);
        REQUIRE(next(m.begin(), 6)->second == 7.5);
        REQUIRE(next(m.begin(), 7)->first == 8);
        REQUIRE(next(m.begin(), 7)->second == 8.5);

        s = m.erase(4);
        REQUIRE(m.size() == 7);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == 1.5);
        REQUIRE(next(m.begin())->first == 2);
        REQUIRE(next(m.begin())->second == 2.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 3.5);
        REQUIRE(next(m.begin(), 3)->first == 5);
        REQUIRE(next(m.begin(), 3)->second == 5.5);
        REQUIRE(next(m.begin(), 4)->first == 6);
        REQUIRE(next(m.begin(), 4)->second == 6.5);
        REQUIRE(next(m.begin(), 5)->first == 7);
        REQUIRE(next(m.begin(), 5)->second == 7.5);
        REQUIRE(next(m.begin(), 6)->first == 8);
        REQUIRE(next(m.begin(), 6)->second == 8.5);

        s = m.erase(1);
        REQUIRE(m.size() == 6);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 3);
        REQUIRE(next(m.begin())->second == 3.5);
        REQUIRE(next(m.begin(), 2)->first == 5);
        REQUIRE(next(m.begin(), 2)->second == 5.5);
        REQUIRE(next(m.begin(), 3)->first == 6);
        REQUIRE(next(m.begin(), 3)->second == 6.5);
        REQUIRE(next(m.begin(), 4)->first == 7);
        REQUIRE(next(m.begin(), 4)->second == 7.5);
        REQUIRE(next(m.begin(), 5)->first == 8);
        REQUIRE(next(m.begin(), 5)->second == 8.5);

        s = m.erase(8);
        REQUIRE(m.size() == 5);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 3);
        REQUIRE(next(m.begin())->second == 3.5);
        REQUIRE(next(m.begin(), 2)->first == 5);
        REQUIRE(next(m.begin(), 2)->second == 5.5);
        REQUIRE(next(m.begin(), 3)->first == 6);
        REQUIRE(next(m.begin(), 3)->second == 6.5);
        REQUIRE(next(m.begin(), 4)->first == 7);
        REQUIRE(next(m.begin(), 4)->second == 7.5);

        s = m.erase(3);
        REQUIRE(m.size() == 4);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 6);
        REQUIRE(next(m.begin(), 2)->second == 6.5);
        REQUIRE(next(m.begin(), 3)->first == 7);
        REQUIRE(next(m.begin(), 3)->second == 7.5);

        s = m.erase(6);
        REQUIRE(m.size() == 3);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 7);
        REQUIRE(next(m.begin(), 2)->second == 7.5);

        s = m.erase(7);
        REQUIRE(m.size() == 2);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);

        s = m.erase(2);
        REQUIRE(m.size() == 1);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 5);
        REQUIRE(m.begin()->second == 5.5);

        s = m.erase(5);
        REQUIRE(m.size() == 0);
        REQUIRE(s == 1);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::map<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
        typedef std::pair<int, double> P;
        typedef M::size_type R;
        P ar[] =
        {
            P(1, 1.5),
            P(2, 2.5),
            P(3, 3.5),
            P(4, 4.5),
            P(5, 5.5),
            P(6, 6.5),
            P(7, 7.5),
            P(8, 8.5),
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 8);
        R s = m.erase(9);
        REQUIRE(s == 0);
        REQUIRE(m.size() == 8);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == 1.5);
        REQUIRE(next(m.begin())->first == 2);
        REQUIRE(next(m.begin())->second == 2.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 3.5);
        REQUIRE(next(m.begin(), 3)->first == 4);
        REQUIRE(next(m.begin(), 3)->second == 4.5);
        REQUIRE(next(m.begin(), 4)->first == 5);
        REQUIRE(next(m.begin(), 4)->second == 5.5);
        REQUIRE(next(m.begin(), 5)->first == 6);
        REQUIRE(next(m.begin(), 5)->second == 6.5);
        REQUIRE(next(m.begin(), 6)->first == 7);
        REQUIRE(next(m.begin(), 6)->second == 7.5);
        REQUIRE(next(m.begin(), 7)->first == 8);
        REQUIRE(next(m.begin(), 7)->second == 8.5);

        s = m.erase(4);
        REQUIRE(m.size() == 7);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == 1.5);
        REQUIRE(next(m.begin())->first == 2);
        REQUIRE(next(m.begin())->second == 2.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 3.5);
        REQUIRE(next(m.begin(), 3)->first == 5);
        REQUIRE(next(m.begin(), 3)->second == 5.5);
        REQUIRE(next(m.begin(), 4)->first == 6);
        REQUIRE(next(m.begin(), 4)->second == 6.5);
        REQUIRE(next(m.begin(), 5)->first == 7);
        REQUIRE(next(m.begin(), 5)->second == 7.5);
        REQUIRE(next(m.begin(), 6)->first == 8);
        REQUIRE(next(m.begin(), 6)->second == 8.5);

        s = m.erase(1);
        REQUIRE(m.size() == 6);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 3);
        REQUIRE(next(m.begin())->second == 3.5);
        REQUIRE(next(m.begin(), 2)->first == 5);
        REQUIRE(next(m.begin(), 2)->second == 5.5);
        REQUIRE(next(m.begin(), 3)->first == 6);
        REQUIRE(next(m.begin(), 3)->second == 6.5);
        REQUIRE(next(m.begin(), 4)->first == 7);
        REQUIRE(next(m.begin(), 4)->second == 7.5);
        REQUIRE(next(m.begin(), 5)->first == 8);
        REQUIRE(next(m.begin(), 5)->second == 8.5);

        s = m.erase(8);
        REQUIRE(m.size() == 5);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 3);
        REQUIRE(next(m.begin())->second == 3.5);
        REQUIRE(next(m.begin(), 2)->first == 5);
        REQUIRE(next(m.begin(), 2)->second == 5.5);
        REQUIRE(next(m.begin(), 3)->first == 6);
        REQUIRE(next(m.begin(), 3)->second == 6.5);
        REQUIRE(next(m.begin(), 4)->first == 7);
        REQUIRE(next(m.begin(), 4)->second == 7.5);

        s = m.erase(3);
        REQUIRE(m.size() == 4);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 6);
        REQUIRE(next(m.begin(), 2)->second == 6.5);
        REQUIRE(next(m.begin(), 3)->first == 7);
        REQUIRE(next(m.begin(), 3)->second == 7.5);

        s = m.erase(6);
        REQUIRE(m.size() == 3);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 7);
        REQUIRE(next(m.begin(), 2)->second == 7.5);

        s = m.erase(7);
        REQUIRE(m.size() == 2);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);

        s = m.erase(2);
        REQUIRE(m.size() == 1);
        REQUIRE(s == 1);
        REQUIRE(m.begin()->first == 5);
        REQUIRE(m.begin()->second == 5.5);

        s = m.erase(5);
        REQUIRE(m.size() == 0);
        REQUIRE(s == 1);
    }
#endif
}
