//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class multiset

// iterator erase(const_iterator position);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "min_allocator.h"

namespace erase_iter_multiset
{
struct TemplateConstructor
{
    template<typename T>
    TemplateConstructor (const T&) {}
};

bool operator<(const TemplateConstructor&, const TemplateConstructor&) { return false; }
}
TEST_CASE("multiset erase iter pass")
{
	using namespace erase_iter_multiset;
    {
        typedef contiguous::multiset<int> M;
        typedef int V;
        typedef M::iterator I;
        V ar[] =
        {
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 8);
        I i = m.erase(next(m.cbegin(), 3));
        REQUIRE(m.size() == 7);
        REQUIRE(i == next(m.begin(), 3));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 6);
        REQUIRE(*next(m.begin(), 5) == 7);
        REQUIRE(*next(m.begin(), 6) == 8);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 6);
        REQUIRE(i == m.begin());
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);
        REQUIRE(*next(m.begin(), 5) == 8);

        i = m.erase(next(m.cbegin(), 5));
        REQUIRE(m.size() == 5);
        REQUIRE(i == m.end());
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin()));
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 6);
        REQUIRE(*next(m.begin(), 3) == 7);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 3);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 7);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 1);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(*next(m.begin(), 0) == 5);

        i = m.erase(m.cbegin());
        REQUIRE(m.size() == 0);
        REQUIRE(i == m.begin());
        REQUIRE(i == m.end());
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::multiset<int, std::less<int>, min_allocator<int>> M;
        typedef int V;
        typedef M::iterator I;
        V ar[] =
        {
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 8);
        I i = m.erase(next(m.cbegin(), 3));
        REQUIRE(m.size() == 7);
        REQUIRE(i == next(m.begin(), 3));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 6);
        REQUIRE(*next(m.begin(), 5) == 7);
        REQUIRE(*next(m.begin(), 6) == 8);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 6);
        REQUIRE(i == m.begin());
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);
        REQUIRE(*next(m.begin(), 5) == 8);

        i = m.erase(next(m.cbegin(), 5));
        REQUIRE(m.size() == 5);
        REQUIRE(i == m.end());
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);

        i = m.erase(next(m.cbegin(), 1));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin()));
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 6);
        REQUIRE(*next(m.begin(), 3) == 7);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 3);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 7);

        i = m.erase(next(m.cbegin(), 2));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);

        i = m.erase(next(m.cbegin(), 0));
        REQUIRE(m.size() == 1);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(*next(m.begin(), 0) == 5);

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
        typedef contiguous::multiset<T> C;
        typedef C::iterator I;

        C c;
        T a{0};
        I it = c.find(a);
        if (it != c.end())
            c.erase(it);
    }
#endif
}
