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

// bool empty() const;

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set empty pass")
{
    {
    typedef contiguous::set<int> M;
    M m;
    REQUIRE(m.empty());
    m.insert(M::value_type(1));
    REQUIRE(!m.empty());
    m.clear();
    REQUIRE(m.empty());
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
    M m;
    REQUIRE(m.empty());
    m.insert(M::value_type(1));
    REQUIRE(!m.empty());
    m.clear();
    REQUIRE(m.empty());
    }
#endif
}
