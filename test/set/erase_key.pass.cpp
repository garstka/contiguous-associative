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

// size_type erase(const key_type& k);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set erase key pass")
{
    {
        typedef contiguous::set<int> M;
        typedef int V;
        typedef M::size_type I;
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
        I i = m.erase(9);
        REQUIRE(m.size() == 8);
        REQUIRE(i == 0);
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 4);
        REQUIRE(*next(m.begin(), 4) == 5);
        REQUIRE(*next(m.begin(), 5) == 6);
        REQUIRE(*next(m.begin(), 6) == 7);
        REQUIRE(*next(m.begin(), 7) == 8);

        i = m.erase(4);
        REQUIRE(m.size() == 7);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 6);
        REQUIRE(*next(m.begin(), 5) == 7);
        REQUIRE(*next(m.begin(), 6) == 8);

        i = m.erase(1);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);
        REQUIRE(*next(m.begin(), 5) == 8);

        i = m.erase(8);
        REQUIRE(m.size() == 5);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);

        i = m.erase(3);
        REQUIRE(m.size() == 4);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 6);
        REQUIRE(*next(m.begin(), 3) == 7);

        i = m.erase(6);
        REQUIRE(m.size() == 3);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 7);

        i = m.erase(7);
        REQUIRE(m.size() == 2);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);

        i = m.erase(2);
        REQUIRE(m.size() == 1);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 5);

        i = m.erase(5);
        REQUIRE(m.size() == 0);
        REQUIRE(i == 1);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
        typedef int V;
        typedef M::size_type I;
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
        I i = m.erase(9);
        REQUIRE(m.size() == 8);
        REQUIRE(i == 0);
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 4);
        REQUIRE(*next(m.begin(), 4) == 5);
        REQUIRE(*next(m.begin(), 5) == 6);
        REQUIRE(*next(m.begin(), 6) == 7);
        REQUIRE(*next(m.begin(), 7) == 8);

        i = m.erase(4);
        REQUIRE(m.size() == 7);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 1);
        REQUIRE(*next(m.begin(), 1) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
        REQUIRE(*next(m.begin(), 3) == 5);
        REQUIRE(*next(m.begin(), 4) == 6);
        REQUIRE(*next(m.begin(), 5) == 7);
        REQUIRE(*next(m.begin(), 6) == 8);

        i = m.erase(1);
        REQUIRE(m.size() == 6);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);
        REQUIRE(*next(m.begin(), 5) == 8);

        i = m.erase(8);
        REQUIRE(m.size() == 5);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 3);
        REQUIRE(*next(m.begin(), 2) == 5);
        REQUIRE(*next(m.begin(), 3) == 6);
        REQUIRE(*next(m.begin(), 4) == 7);

        i = m.erase(3);
        REQUIRE(m.size() == 4);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 6);
        REQUIRE(*next(m.begin(), 3) == 7);

        i = m.erase(6);
        REQUIRE(m.size() == 3);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);
        REQUIRE(*next(m.begin(), 2) == 7);

        i = m.erase(7);
        REQUIRE(m.size() == 2);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 2);
        REQUIRE(*next(m.begin(), 1) == 5);

        i = m.erase(2);
        REQUIRE(m.size() == 1);
        REQUIRE(i == 1);
        REQUIRE(*next(m.begin(), 0) == 5);

        i = m.erase(5);
        REQUIRE(m.size() == 0);
        REQUIRE(i == 1);
    }
#endif
}
