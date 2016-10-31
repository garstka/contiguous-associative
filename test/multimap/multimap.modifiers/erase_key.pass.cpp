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

// size_type erase(const key_type& k);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multimap modifiers erase key pass")
{
    {
        typedef contiguous::multimap<int, double> M;
        typedef std::pair<int, double> P;
        typedef M::size_type I;
        P ar[] =
        {
            P(1, 1),
            P(1, 1.5),
            P(1, 2),
            P(2, 1),
            P(2, 1.5),
            P(2, 2),
            P(3, 1),
            P(3, 1.5),
            P(3, 2),
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 9);
        I i = m.erase(2);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 3);
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 1);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1.5);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 2);

        i = m.erase(2);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 0);
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 1);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1.5);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 2);

        i = m.erase(3);
        REQUIRE(i == 3);
        REQUIRE(m.size() == 3);
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);

        i = m.erase(1);
        REQUIRE(m.size() == 0);
        REQUIRE(i == 3);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::multimap<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
        typedef std::pair<int, double> P;
        typedef M::size_type I;
        P ar[] =
        {
            P(1, 1),
            P(1, 1.5),
            P(1, 2),
            P(2, 1),
            P(2, 1.5),
            P(2, 2),
            P(3, 1),
            P(3, 1.5),
            P(3, 2),
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 9);
        I i = m.erase(2);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 3);
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 1);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1.5);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 2);

        i = m.erase(2);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 0);
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 1);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1.5);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 2);

        i = m.erase(3);
        REQUIRE(i == 3);
        REQUIRE(m.size() == 3);
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);

        i = m.erase(1);
        REQUIRE(m.size() == 0);
        REQUIRE(i == 3);
    }
#endif
}
