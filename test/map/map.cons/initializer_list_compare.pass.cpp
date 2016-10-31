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

// map(initializer_list<value_type> il, const key_compare& comp);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"
#include "test_compare.h"
#include "min_allocator.h"

TEST_CASE("map cons initializer list compare pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef std::pair<const int, double> V;
    typedef test_compare<std::less<int> > C;
    contiguous::map<int, double, C> m({
                                {1, 1},
                                {1, 1.5},
                                {1, 2},
                                {2, 1},
                                {2, 1.5},
                                {2, 2},
                                {3, 1},
                                {3, 1.5},
                                {3, 2}
                               }, C(3));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));
    REQUIRE(m.key_comp() == C(3));
    }
#if TEST_STD_VER >= 11
    {
    typedef std::pair<const int, double> V;
    typedef test_compare<std::less<int> > C;
    contiguous::map<int, double, C, min_allocator<std::pair<const int, double>>> m({
                                {1, 1},
                                {1, 1.5},
                                {1, 2},
                                {2, 1},
                                {2, 1.5},
                                {2, 2},
                                {3, 1},
                                {3, 1.5},
                                {3, 2}
                               }, C(3));
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));
    REQUIRE(m.key_comp() == C(3));
    }
#endif
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
}
