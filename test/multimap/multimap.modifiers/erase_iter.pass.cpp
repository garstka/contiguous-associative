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

// iterator erase(const_iterator position);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "min_allocator.h"

namespace erase_iter_multimap
{
struct TemplateConstructor
{
    template<typename T>
    TemplateConstructor (const T&) {}
};

bool operator<(const TemplateConstructor&, const TemplateConstructor&) { return false; }
}

TEST_CASE("multimap modifiers erase iter pass")
{
	using namespace erase_iter_multimap;
    {
        typedef contiguous::multimap<int, double> M;
        typedef std::pair<int, double> P;
        typedef M::iterator I;
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
        I i = m.erase(next(m.cbegin(), 3));
        REQUIRE(m.size() == 8);
        REQUIRE(i == next(m.begin(), 3));
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == 1);
        REQUIRE(next(m.begin())->first == 1);
        REQUIRE(next(m.begin())->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 2);
        REQUIRE(next(m.begin(), 3)->second == 1.5);
        REQUIRE(next(m.begin(), 4)->first == 2);
        REQUIRE(next(m.begin(), 4)->second == 2);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 1);
        REQUIRE(next(m.begin(), 6)->first == 3);
        REQUIRE(next(m.begin(), 6)->second == 1.5);
        REQUIRE(next(m.begin(), 7)->first == 3);
        REQUIRE(next(m.begin(), 7)->second == 2);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 7);
        REQUIRE(i == m.begin());
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 2);
        REQUIRE(next(m.begin(), 2)->first == 2);
        REQUIRE(next(m.begin(), 2)->second == 1.5);
        REQUIRE(next(m.begin(), 3)->first == 2);
        REQUIRE(next(m.begin(), 3)->second == 2);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 1.5);
        REQUIRE(next(m.begin(), 6)->first == 3);
        REQUIRE(next(m.begin(), 6)->second == 2);

        i = m.erase(next(m.cbegin(), 5));
        REQUIRE(m.size() == 6);
        REQUIRE(i == prev(m.end()));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 2);
        REQUIRE(next(m.begin(), 2)->first == 2);
        REQUIRE(next(m.begin(), 2)->second == 1.5);
        REQUIRE(next(m.begin(), 3)->first == 2);
        REQUIRE(next(m.begin(), 3)->second == 2);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 2);

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 5);
        REQUIRE(i == next(m.begin()));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 2);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 2);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 1);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 2);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 2);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 1);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 2);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 3);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 2);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 2);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(next(m.begin(), 0)->first == 2);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 3);
        REQUIRE(next(m.begin(), 1)->second == 2);

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 1);
        REQUIRE(i == m.end());
        REQUIRE(next(m.begin(), 0)->first == 2);
        REQUIRE(next(m.begin(), 0)->second == 1.5);

        i = m.erase(m.cbegin());
        REQUIRE(m.size() == 0);
        REQUIRE(i == m.begin());
        REQUIRE(i == m.end());
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::multimap<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
        typedef std::pair<int, double> P;
        typedef M::iterator I;
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
        I i = m.erase(next(m.cbegin(), 3));
        REQUIRE(m.size() == 8);
        REQUIRE(i == next(m.begin(), 3));
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == 1);
        REQUIRE(next(m.begin())->first == 1);
        REQUIRE(next(m.begin())->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 1);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 2);
        REQUIRE(next(m.begin(), 3)->second == 1.5);
        REQUIRE(next(m.begin(), 4)->first == 2);
        REQUIRE(next(m.begin(), 4)->second == 2);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 1);
        REQUIRE(next(m.begin(), 6)->first == 3);
        REQUIRE(next(m.begin(), 6)->second == 1.5);
        REQUIRE(next(m.begin(), 7)->first == 3);
        REQUIRE(next(m.begin(), 7)->second == 2);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 7);
        REQUIRE(i == m.begin());
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 2);
        REQUIRE(next(m.begin(), 2)->first == 2);
        REQUIRE(next(m.begin(), 2)->second == 1.5);
        REQUIRE(next(m.begin(), 3)->first == 2);
        REQUIRE(next(m.begin(), 3)->second == 2);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 1.5);
        REQUIRE(next(m.begin(), 6)->first == 3);
        REQUIRE(next(m.begin(), 6)->second == 2);

        i = m.erase(next(m.cbegin(), 5));
        REQUIRE(m.size() == 6);
        REQUIRE(i == prev(m.end()));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 1);
        REQUIRE(next(m.begin(), 1)->second == 2);
        REQUIRE(next(m.begin(), 2)->first == 2);
        REQUIRE(next(m.begin(), 2)->second == 1.5);
        REQUIRE(next(m.begin(), 3)->first == 2);
        REQUIRE(next(m.begin(), 3)->second == 2);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 1);
        REQUIRE(next(m.begin(), 5)->first == 3);
        REQUIRE(next(m.begin(), 5)->second == 2);

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 5);
        REQUIRE(i == next(m.begin()));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 2);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 2);
        REQUIRE(next(m.begin(), 2)->second == 2);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 1);
        REQUIRE(next(m.begin(), 4)->first == 3);
        REQUIRE(next(m.begin(), 4)->second == 2);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 2);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 1);
        REQUIRE(next(m.begin(), 3)->first == 3);
        REQUIRE(next(m.begin(), 3)->second == 2);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 3);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(next(m.begin(), 0)->first == 1);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 2);
        REQUIRE(next(m.begin(), 1)->second == 1.5);
        REQUIRE(next(m.begin(), 2)->first == 3);
        REQUIRE(next(m.begin(), 2)->second == 2);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(next(m.begin(), 0)->first == 2);
        REQUIRE(next(m.begin(), 0)->second == 1.5);
        REQUIRE(next(m.begin(), 1)->first == 3);
        REQUIRE(next(m.begin(), 1)->second == 2);

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 1);
        REQUIRE(i == m.end());
        REQUIRE(next(m.begin(), 0)->first == 2);
        REQUIRE(next(m.begin(), 0)->second == 1.5);

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
        typedef contiguous::multimap<T, int> C;
        typedef C::iterator I;

        C c;
        T a{0};
        I it = c.find(a);
        if (it != c.end())
            c.erase(it);
    }
#endif
}
