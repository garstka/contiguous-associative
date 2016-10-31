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

// map();

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("map cons default pass")
{
    {
    contiguous::map<int, double> m;
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    }
#if TEST_STD_VER >= 11
    {
    contiguous::map<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> m;
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    }
    {
    typedef explicit_allocator<std::pair<const int, double>> A;
        {
        contiguous::map<int, double, std::less<int>, A> m;
        REQUIRE(m.empty());
        REQUIRE(m.begin() == m.end());
        }
        {
        A a;
        contiguous::map<int, double, std::less<int>, A> m(a);
        REQUIRE(m.empty());
        REQUIRE(m.begin() == m.end());
        }
    }
    {
    contiguous::map<int, double> m = {};
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    }
#endif
}
