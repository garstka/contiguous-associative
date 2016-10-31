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

// explicit multimap(const key_compare& comp);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "test_compare.h"
#include "min_allocator.h"

TEST_CASE("multimap cons compare pass")
{
    {
    typedef test_compare<std::less<int> > C;
    contiguous::multimap<int, double, C> m(C(3));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(3));
    }
#if TEST_STD_VER >= 11
    {
    typedef test_compare<std::less<int> > C;
    contiguous::multimap<int, double, C, min_allocator<std::pair<const int, double>>> m(C(3));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(3));
    }
#endif
}
