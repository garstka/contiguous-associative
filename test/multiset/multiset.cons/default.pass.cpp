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

// multiset();

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multiset cons default pass")
{
    {
    contiguous::multiset<int> m;
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    }
#if TEST_STD_VER >= 11
    {
    contiguous::multiset<int, std::less<int>, min_allocator<int>> m;
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    }
    {
    typedef explicit_allocator<int> A;
        {
        contiguous::multiset<int, std::less<int>, A> m;
        REQUIRE(m.empty());
        REQUIRE(m.begin() == m.end());
        }
        {
        A a;
        contiguous::multiset<int, std::less<int>, A> m(a);
        REQUIRE(m.empty());
        REQUIRE(m.begin() == m.end());
        }
    }
    {
    contiguous::multiset<int> m = {};
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    }
#endif
}
