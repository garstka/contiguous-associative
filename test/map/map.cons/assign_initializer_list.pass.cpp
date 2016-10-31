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

// map& operator=(initializer_list<value_type> il);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("map cons assign initializer list pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef std::pair<const int, double> V;
    contiguous::map<int, double> m =
                            {
                                {20, 1},
                            };
    m =
                            {
                                {1, 1},
                                {1, 1.5},
                                {1, 2},
                                {2, 1},
                                {2, 1.5},
                                {2, 2},
                                {3, 1},
                                {3, 1.5},
                                {3, 2}
                            };
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));
    }
#if TEST_STD_VER >= 11
    {
    typedef std::pair<const int, double> V;
    contiguous::map<int, double, std::less<int>, min_allocator<V>> m =
                            {
                                {20, 1},
                            };
    m =
                            {
                                {1, 1},
                                {1, 1.5},
                                {1, 2},
                                {2, 1},
                                {2, 1.5},
                                {2, 2},
                                {3, 1},
                                {3, 1.5},
                                {3, 2}
                            };
    REQUIRE(m.size() == 3);
    REQUIRE(distance(m.begin(), m.end()) == 3);
    REQUIRE(*m.begin() == V(1, 1));
    REQUIRE(*next(m.begin()) == V(2, 1));
    REQUIRE(*next(m.begin(), 2) == V(3, 1));
    }
#endif
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
}
