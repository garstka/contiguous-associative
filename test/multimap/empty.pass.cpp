//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class multimap

// bool empty() const;

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multimap empty pass")
{
    {
    typedef contiguous::multimap<int, double> M;
    M m;
    REQUIRE(m.empty());
    m.insert(M::value_type(1, 1.5));
    REQUIRE(!m.empty());
    m.clear();
    REQUIRE(m.empty());
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::multimap<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
    M m;
    REQUIRE(m.empty());
    m.insert(M::value_type(1, 1.5));
    REQUIRE(!m.empty());
    m.clear();
    REQUIRE(m.empty());
    }
#endif
}
