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

// size_type max_size() const;

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("map access max size pass")
{
    {
    typedef contiguous::map<int, double> M;
    M m;
    REQUIRE(m.max_size() != 0);
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::map<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
    M m;
    REQUIRE(m.max_size() != 0);
    }
#endif
}
