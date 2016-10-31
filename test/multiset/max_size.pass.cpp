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

// size_type max_size() const;

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multiset max size pass")
{
    {
    typedef contiguous::multiset<int> M;
    M m;
    REQUIRE(m.max_size() != 0);
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::multiset<int, std::less<int>, min_allocator<int>> M;
    M m;
    REQUIRE(m.max_size() != 0);
    }
#endif
}
