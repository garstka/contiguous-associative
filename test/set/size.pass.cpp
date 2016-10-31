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

// size_type size() const;

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set size pass")
{
    {
    typedef contiguous::set<int> M;
    M m;
    REQUIRE(m.size() == 0);
    m.insert(M::value_type(2));
    REQUIRE(m.size() == 1);
    m.insert(M::value_type(1));
    REQUIRE(m.size() == 2);
    m.insert(M::value_type(3));
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
    typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
    M m;
    REQUIRE(m.size() == 0);
    m.insert(M::value_type(2));
    REQUIRE(m.size() == 1);
    m.insert(M::value_type(1));
    REQUIRE(m.size() == 2);
    m.insert(M::value_type(3));
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
