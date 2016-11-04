//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// XFAIL: c++98, c++03, c++11

// <map>

// class map

//       iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;
//
//   The member function templates find, count, lower_bound, upper_bound, and
// equal_range shall not participate in overload resolution unless the
// qualified-id Compare::is_transparent is valid and denotes a type


#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "is_transparent.h"

TEST_CASE("map ops upper bound0 pass")
{
#if LIBCPP_STD_VER > 11
    typedef contiguous::map<int, double, transparent_less> M;

    M().upper_bound(C2Int{5});
#endif
}
