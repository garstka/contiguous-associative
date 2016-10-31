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

// multiset(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"
#include "test_compare.h"
#include "test_allocator.h"

TEST_CASE("multiset cons initializer list compare alloc pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    typedef test_compare<std::less<int> > Cmp;
    typedef test_allocator<int> A;
    typedef contiguous::multiset<int, Cmp, A> C;
    typedef C::value_type V;
    C m({1, 2, 3, 4, 5, 6}, Cmp(10), A(4));
    REQUIRE(m.size() == 6);
    REQUIRE(distance(m.begin(), m.end()) == 6);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1));
    REQUIRE(*++i == V(2));
    REQUIRE(*++i == V(3));
    REQUIRE(*++i == V(4));
    REQUIRE(*++i == V(5));
    REQUIRE(*++i == V(6));
    REQUIRE(m.key_comp() == Cmp(10));
    REQUIRE(m.get_allocator() == A(4));
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
}
