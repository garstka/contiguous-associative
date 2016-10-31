//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>
//   The container's value type must be the same as the allocator's value type

#include "defs.h"
#include "fail_defs.h"

#include "catch.hpp"

#include "contiguous/set.h"

TEST_CASE("set allocator mismatch fail")
{
#ifdef ALLOW_ALLOCATOR_MISMATCH
    contiguous::set<int, std::less<int>, std::allocator<long> > s;
#else
#ifdef SET_ALLOCATOR_MISMATCH_FAIL
    contiguous::set<int, std::less<int>, std::allocator<long> > s;
	REQUIRE(false); // this should have failed at compile time
#endif
#endif
}
