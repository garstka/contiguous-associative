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

// set(initializer_list<value_type> il, const key_compare& comp = key_compare());

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set cons initializer list pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef contiguous::set<int> C;
    typedef C::value_type V;
    C m = {1, 2, 3, 4, 5, 6};
    REQUIRE(m.size() == 6);
    REQUIRE(distance(m.begin(), m.end()) == 6);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1));
    REQUIRE(*++i == V(2));
    REQUIRE(*++i == V(3));
    REQUIRE(*++i == V(4));
    REQUIRE(*++i == V(5));
    REQUIRE(*++i == V(6));
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::set<int, std::less<int>, min_allocator<int>> C;
    typedef C::value_type V;
    C m = {1, 2, 3, 4, 5, 6};
    REQUIRE(m.size() == 6);
    REQUIRE(distance(m.begin(), m.end()) == 6);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1));
    REQUIRE(*++i == V(2));
    REQUIRE(*++i == V(3));
    REQUIRE(*++i == V(4));
    REQUIRE(*++i == V(5));
    REQUIRE(*++i == V(6));
    }
#endif
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
}
