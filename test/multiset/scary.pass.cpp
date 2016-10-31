//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class set class multiset

// Extension:  SCARY/N2913 iterator compatibility between set and multiset

#include "defs.h"

#include "catch.hpp"
#include "contiguous/multiset.h"
#include "contiguous/set.h"

TEST_CASE("multiset scary pass")
{
    typedef contiguous::set<int> M1;
    typedef contiguous::multiset<int> M2;
    M2::iterator i;
    M1::iterator j = i;
    ((void)j);
}
