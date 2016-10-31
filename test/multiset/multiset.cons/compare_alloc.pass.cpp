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

// multiset(const value_compare& comp, const allocator_type& a);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"

TEST_CASE("multiset cons compare alloc pass")
{
    typedef test_compare<std::less<int> > C;
    typedef test_allocator<int> A;
    contiguous::multiset<int, C, A> m(C(4), A(5));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(4));
    REQUIRE(m.get_allocator() == A(5));
}
