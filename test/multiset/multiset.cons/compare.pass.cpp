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

// explicit multiset(const value_compare& comp);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "test_compare.h"

TEST_CASE("multiset cons compare pass")
{
    typedef test_compare<std::less<int> > C;
    contiguous::multiset<int, C> m(C(3));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(3));
}
