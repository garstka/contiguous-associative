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

// iterator erase(const_iterator position);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

struct TemplateConstructor
{
    template<typename T>
    TemplateConstructor (const T&) {}
};

bool operator<(const TemplateConstructor&, const TemplateConstructor&) { return false; }

TEST_CASE("map modifiers erase iter pass")
{
    {
        typedef contiguous::map<int, double> M;
        typedef std::pair<int, double> P;
        typedef M::iterator I;
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
        I i = m.erase(next(m.cbegin(), 3));
        REQUIRE(m.size() == 7);
        REQUIRE(i == next(m.begin(), 3));
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

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 6);
        REQUIRE(i == m.begin());
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

        i = m.erase(next(m.cbegin(), 5));
        REQUIRE(m.size() == 5);
        REQUIRE(i == m.end());
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

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin()));
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 6);
        REQUIRE(next(m.begin(), 2)->second == 6.5);
        REQUIRE(next(m.begin(), 3)->first == 7);
        REQUIRE(next(m.begin(), 3)->second == 7.5);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 3);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 7);
        REQUIRE(next(m.begin(), 2)->second == 7.5);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 1);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(m.begin()->first == 5);
        REQUIRE(m.begin()->second == 5.5);

        i = m.erase(m.cbegin());
        REQUIRE(m.size() == 0);
        REQUIRE(i == m.begin());
        REQUIRE(i == m.end());
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::map<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
        typedef std::pair<int, double> P;
        typedef M::iterator I;
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
        I i = m.erase(next(m.cbegin(), 3));
        REQUIRE(m.size() == 7);
        REQUIRE(i == next(m.begin(), 3));
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

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 6);
        REQUIRE(i == m.begin());
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

        i = m.erase(next(m.cbegin(), 5));
        REQUIRE(m.size() == 5);
        REQUIRE(i == m.end());
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

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin()));
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 6);
        REQUIRE(next(m.begin(), 2)->second == 6.5);
        REQUIRE(next(m.begin(), 3)->first == 7);
        REQUIRE(next(m.begin(), 3)->second == 7.5);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 3);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);
        REQUIRE(next(m.begin(), 2)->first == 7);
        REQUIRE(next(m.begin(), 2)->second == 7.5);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 2.5);
        REQUIRE(next(m.begin())->first == 5);
        REQUIRE(next(m.begin())->second == 5.5);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 1);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(m.begin()->first == 5);
        REQUIRE(m.begin()->second == 5.5);

        i = m.erase(m.cbegin());
        REQUIRE(m.size() == 0);
        REQUIRE(i == m.begin());
        REQUIRE(i == m.end());
    }
#endif
#if TEST_STD_VER >= 14
    {
    //  This is LWG #2059
        typedef TemplateConstructor T;
        typedef contiguous::map<T, int> C;
        typedef C::iterator I;

        C c;
        T a{0};
        I it = c.find(a);
        if (it != c.end())
            c.erase(it);
    }
#endif
}
