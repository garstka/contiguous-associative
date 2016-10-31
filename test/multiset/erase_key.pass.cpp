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

// size_type erase(const key_type& k);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multiset erase key pass")
{
    {
        typedef contiguous::multiset<int> M;
        typedef int V;
        typedef M::size_type I;
        V ar[] =
        {
            3,
            3,
            3,
            5,
            5,
            5,
            7,
            7,
            7
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 9);
        I i = m.erase(6);
        REQUIRE(m.size() == 9);
        REQUIRE(i == 0);
        REQUIRE(*next(m.begin(), 0) == 3);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 5);
        REQUIRE(*next(m.begin(), 5) == 5);
        REQUIRE(*next(m.begin(), 6) == 7);
        REQUIRE(*next(m.begin(), 7) == 7);
        REQUIRE(*next(m.begin(), 8) == 7);

        i = m.erase(5);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 3);
        REQUIRE(*next(m.begin(), 0) == 3);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 7);
        REQUIRE(*next(m.begin(), 4) == 7);
        REQUIRE(*next(m.begin(), 5) == 7);

        i = m.erase(3);
        REQUIRE(m.size() == 3);
        REQUIRE(i == 3);
        REQUIRE(*next(m.begin(), 0) == 7);
        REQUIRE(*next(m.begin(), 1) == 7);
        REQUIRE(*next(m.begin(), 2) == 7);

        i = m.erase(7);
        REQUIRE(m.size() == 0);
        REQUIRE(i == 3);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::multiset<int, std::less<int>, min_allocator<int>> M;
        typedef int V;
        typedef M::size_type I;
        V ar[] =
        {
            3,
            3,
            3,
            5,
            5,
            5,
            7,
            7,
            7
        };
        M m(ar, ar + sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 9);
        I i = m.erase(6);
        REQUIRE(m.size() == 9);
        REQUIRE(i == 0);
        REQUIRE(*next(m.begin(), 0) == 3);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 5);
        REQUIRE(*next(m.begin(), 5) == 5);
        REQUIRE(*next(m.begin(), 6) == 7);
        REQUIRE(*next(m.begin(), 7) == 7);
        REQUIRE(*next(m.begin(), 8) == 7);

        i = m.erase(5);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 3);
        REQUIRE(*next(m.begin(), 0) == 3);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 7);
        REQUIRE(*next(m.begin(), 4) == 7);
        REQUIRE(*next(m.begin(), 5) == 7);

        i = m.erase(3);
        REQUIRE(m.size() == 3);
        REQUIRE(i == 3);
        REQUIRE(*next(m.begin(), 0) == 7);
        REQUIRE(*next(m.begin(), 1) == 7);
        REQUIRE(*next(m.begin(), 2) == 7);

        i = m.erase(7);
        REQUIRE(m.size() == 0);
        REQUIRE(i == 3);
    }
#endif
}
