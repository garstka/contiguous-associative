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

// explicit map(const allocator_type& a);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("map cons alloc pass")
{
    {
    typedef std::less<int> C;
    typedef test_allocator<std::pair<const int, double> > A;
    contiguous::map<int, double, C, A> m(A(5));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.get_allocator() == A(5));
    }
#if TEST_STD_VER >= 11
    {
    typedef std::less<int> C;
    typedef min_allocator<std::pair<const int, double> > A;
    contiguous::map<int, double, C, A> m(A{});
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.get_allocator() == A());
    }
    {
    typedef std::less<int> C;
    typedef explicit_allocator<std::pair<const int, double> > A;
    contiguous::map<int, double, C, A> m(A{});
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.get_allocator() == A());
    }
#endif
}
