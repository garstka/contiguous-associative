//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class set

// iterator erase(const_iterator first, const_iterator last);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set erase iter iter pass")
{
    {
        typedef contiguous::set<int> M;
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
        I i = m.erase(next(m.cbegin(), 5), next(m.cbegin(), 5));
        REQUIRE(m.size() == 8);
        REQUIRE(i == next(m.begin(), 5));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 4);
        REQUIRE(*next(m.begin(), 4) == 5);
        REQUIRE(*next(m.begin(), 5) == 6);
        REQUIRE(*next(m.begin(), 6) == 7);
        REQUIRE(*next(m.begin(), 7) == 8);

        i = m.erase(next(m.cbegin(), 3), next(m.cbegin(), 4));
        REQUIRE(m.size() == 7);
        REQUIRE(i == next(m.begin(), 3));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 6);
        REQUIRE(*next(m.begin(), 5) == 7);
        REQUIRE(*next(m.begin(), 6) == 8);

        i = m.erase(next(m.cbegin(), 2), next(m.cbegin(), 5));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 7);
        REQUIRE(*next(m.begin(), 3) == 8);

        i = m.erase(next(m.cbegin(), 0), next(m.cbegin(), 2));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(*next(m.begin(), 0) == 7);
        REQUIRE(*next(m.begin(), 1) == 8);

        i = m.erase(m.cbegin(), m.cend());
        REQUIRE(m.size() == 0);
        REQUIRE(i == m.end());
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
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
        I i = m.erase(next(m.cbegin(), 5), next(m.cbegin(), 5));
        REQUIRE(m.size() == 8);
        REQUIRE(i == next(m.begin(), 5));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 4);
        REQUIRE(*next(m.begin(), 4) == 5);
        REQUIRE(*next(m.begin(), 5) == 6);
        REQUIRE(*next(m.begin(), 6) == 7);
        REQUIRE(*next(m.begin(), 7) == 8);

        i = m.erase(next(m.cbegin(), 3), next(m.cbegin(), 4));
        REQUIRE(m.size() == 7);
        REQUIRE(i == next(m.begin(), 3));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 6);
        REQUIRE(*next(m.begin(), 5) == 7);
        REQUIRE(*next(m.begin(), 6) == 8);

        i = m.erase(next(m.cbegin(), 2), next(m.cbegin(), 5));
        REQUIRE(m.size() == 4);
        REQUIRE(i == next(m.begin(), 2));
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 7);
        REQUIRE(*next(m.begin(), 3) == 8);

        i = m.erase(next(m.cbegin(), 0), next(m.cbegin(), 2));
        REQUIRE(m.size() == 2);
        REQUIRE(i == next(m.begin(), 0));
        REQUIRE(*next(m.begin(), 0) == 7);
        REQUIRE(*next(m.begin(), 1) == 8);

        i = m.erase(m.cbegin(), m.cend());
        REQUIRE(m.size() == 0);
        REQUIRE(i == m.end());
    }
#endif
}
