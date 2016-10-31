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

// multimap(initializer_list<value_type> il, const key_compare& comp = key_compare());

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"
#include "test_compare.h"
#include "min_allocator.h"

TEST_CASE("multimap cons initializer list compare pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef test_compare<std::less<int> > Cmp;
    typedef contiguous::multimap<int, double, Cmp> C;
    typedef C::value_type V;
    C m(
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
           },
           Cmp(4)
        );
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
    REQUIRE(m.key_comp() == Cmp(4));
    }
#if TEST_STD_VER >= 11
    {
    typedef test_compare<std::less<int> > Cmp;
    typedef contiguous::multimap<int, double, Cmp, min_allocator<std::pair<const int, double>>> C;
    typedef C::value_type V;
    C m(
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
           },
           Cmp(4)
        );
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
    REQUIRE(m.key_comp() == Cmp(4));
    }
#endif
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
}
