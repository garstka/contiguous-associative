//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class multimap

//       iterator lower_bound(const key_type& k);
// const_iterator lower_bound(const key_type& k) const;
//
//   The member function templates find, count, lower_bound, upper_bound, and
// equal_range shall not participate in overload resolution unless the
// qualified-id Compare::is_transparent is valid and denotes a type

#include "defs.h"
#include "fail_defs.h"


#include "contiguous/multimap.h"
#include "catch.hpp"

#include "is_transparent.h"

TEST_CASE("multimap lower bound3 fail")
{
#if LIBCPP_STD_VER > 11
#ifdef MULTIMAP_LBOUND_FAIL3
    {
    typedef contiguous::multimap<int, double, transparent_less_not_a_type> M;

    M().lower_bound(C2Int{5});
    }
	REQUIRE(false); // this should have failed at compile time
#endif
#endif

}