//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class multiset

// multiset& operator=(initializer_list<value_type> il);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("multiset cons assign initializer list pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef contiguous::multiset<int> C;
    typedef C::value_type V;
    C m = {10, 8};
    m = {1, 2, 3, 4, 5, 6};
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
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
#if TEST_STD_VER >= 11
    {
    typedef contiguous::multiset<int, std::less<int>, min_allocator<int>> C;
    typedef C::value_type V;
    C m = {10, 8};
    m = {1, 2, 3, 4, 5, 6};
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
}
