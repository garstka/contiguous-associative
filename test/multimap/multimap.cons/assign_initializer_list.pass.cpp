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

// multimap& operator=(initializer_list<value_type> il);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multimap cons assign initializer list pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef contiguous::multimap<int, double> C;
    typedef C::value_type V;
    C m = {{20, 1}};
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
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1, 1));
    REQUIRE(*++i == V(1, 1.5));
    REQUIRE(*++i == V(1, 2));
    REQUIRE(*++i == V(2, 1));
    REQUIRE(*++i == V(2, 1.5));
    REQUIRE(*++i == V(2, 2));
    REQUIRE(*++i == V(3, 1));
    REQUIRE(*++i == V(3, 1.5));
    REQUIRE(*++i == V(3, 2));
    }
#if TEST_STD_VER >= 11
    {
    typedef contiguous::multimap<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> C;
    typedef C::value_type V;
    C m = {{20, 1}};
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
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1, 1));
    REQUIRE(*++i == V(1, 1.5));
    REQUIRE(*++i == V(1, 2));
    REQUIRE(*++i == V(2, 1));
    REQUIRE(*++i == V(2, 1.5));
    REQUIRE(*++i == V(2, 2));
    REQUIRE(*++i == V(3, 1));
    REQUIRE(*++i == V(3, 1.5));
    REQUIRE(*++i == V(3, 2));
    }
#endif
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
}
