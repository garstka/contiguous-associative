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

// explicit set(const value_compare& comp);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "test_compare.h"

TEST_CASE("set cons compare pass")
{
    typedef test_compare<std::less<int> > C;
    contiguous::set<int, C> m(C(3));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(3));
}
