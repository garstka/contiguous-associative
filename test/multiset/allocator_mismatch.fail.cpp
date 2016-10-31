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

#include "contiguous/multiset.h"

TEST_CASE("multiset allocator mismatch fail")
{
#ifdef ALLOW_ALLOCATOR_MISMATCH
    contiguous::multiset<int, std::less<int>, std::allocator<long> > ms;
#else
#ifdef MULTISET_ALLOCATOR_MISMATCH_FAIL
    contiguous::multiset<int, std::less<int>, std::allocator<long> > ms;
	REQUIRE(false); // the test should have failed at compile time
#endif
#endif
}
