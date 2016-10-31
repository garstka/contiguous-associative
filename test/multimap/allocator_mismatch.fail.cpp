//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>
//   The container's value type must be the same as the allocator's value type

#include "defs.h"
#include "fail_defs.h"

#include "catch.hpp"

#include "contiguous/multimap.h"

TEST_CASE("multimap allocator mismatch fail")
{
#ifdef ALLOW_ALLOCATOR_MISMATCH
    contiguous::multimap<int, int, std::less<int>, std::allocator<long> > m;
#else
#ifdef MULTIMAP_ALLOCATOR_MISMATCH_FAIL
    contiguous::multimap<int, int, std::less<int>, std::allocator<long> > m;
	REQUIRE(false); // the test should have failed at compile time
#endif
#endif
}
