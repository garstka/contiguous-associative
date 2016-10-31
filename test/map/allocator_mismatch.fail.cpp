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

#include <memory>
#include <functional>
#include "contiguous/map.h"

TEST_CASE("map allocator mismatch fail")
{
#ifdef ALLOW_ALLOCATOR_MISMATCH
    contiguous::map<int, int, std::less<int>, std::allocator<long> > m;
#else
#ifdef MAP_ALLOCATOR_MISMATCH_FAIL
    contiguous::map<int, int, std::less<int>, std::allocator<long> > m;
	REQUIRE(false); // the test should have failed at compile time
#endif
#endif
}
