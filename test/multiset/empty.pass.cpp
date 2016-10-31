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

// bool empty() const;

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multiset empty pass")
{
    {
    typedef contiguous::multiset<int> M;
    M m;
    REQUIRE(m.empty());
    m.insert(M::value_type(1));
    REQUIRE(!m.empty());
    m.clear();
    REQUIRE(m.empty());
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::multiset<int, std::less<int>, min_allocator<int>> M;
    M m;
    REQUIRE(m.empty());
    m.insert(M::value_type(1));
    REQUIRE(!m.empty());
    m.clear();
    REQUIRE(m.empty());
    }
#endif
}
