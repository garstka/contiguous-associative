//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class map

//       iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;
//
//   The member function templates find, count, lower_bound, upper_bound, and
// equal_range shall not participate in overload resolution unless the
// qualified-id Compare::is_transparent is valid and denotes a type

#include "defs.h"
#include "fail_defs.h"


#include "contiguous/map.h"
#include "catch.hpp"

#include "is_transparent.h"

TEST_CASE("map ops count1 fail")
{
#if LIBCPP_STD_VER > 11
#ifdef MAP_COUNT1_FAIL
    {
    typedef contiguous::map<int, double, transparent_less_no_type> M;

    M().count(C2Int{5});
    }
	REQUIRE(false); // this should have failed at compile time
#endif
#endif
}