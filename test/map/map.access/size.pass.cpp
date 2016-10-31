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

// size_type size() const;

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("map access size pass")
{
    {
    typedef contiguous::map<int, double> M;
    M m;
    REQUIRE(m.size() == 0);
    m.insert(M::value_type(2, 1.5));
    REQUIRE(m.size() == 1);
    m.insert(M::value_type(1, 1.5));
    REQUIRE(m.size() == 2);
    m.insert(M::value_type(3, 1.5));
    REQUIRE(m.size() == 3);
    m.erase(m.begin());
    REQUIRE(m.size() == 2);
    m.erase(m.begin());
    REQUIRE(m.size() == 1);
    m.erase(m.begin());
    REQUIRE(m.size() == 0);
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::map<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
    M m;
    REQUIRE(m.size() == 0);
    m.insert(M::value_type(2, 1.5));
    REQUIRE(m.size() == 1);
    m.insert(M::value_type(1, 1.5));
    REQUIRE(m.size() == 2);
    m.insert(M::value_type(3, 1.5));
    REQUIRE(m.size() == 3);
    m.erase(m.begin());
    REQUIRE(m.size() == 2);
    m.erase(m.begin());
    REQUIRE(m.size() == 1);
    m.erase(m.begin());
    REQUIRE(m.size() == 0);
    }
#endif
}
