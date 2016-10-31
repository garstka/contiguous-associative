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

// set(const allocator_type& a);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "test_allocator.h"

TEST_CASE("set cons alloc pass")
{
    typedef std::less<int> C;
    typedef test_allocator<int> A;
    contiguous::set<int, C, A> m(A(5));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.get_allocator() == A(5));
}
