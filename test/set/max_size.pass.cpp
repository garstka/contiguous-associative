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

// size_type max_size() const;

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set max size pass")
{
    {
    typedef contiguous::set<int> M;
    M m;
    REQUIRE(m.max_size() != 0);
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
    M m;
    REQUIRE(m.max_size() != 0);
    }
#endif
}
