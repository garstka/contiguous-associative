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

// multimap(const key_compare& comp, const allocator_type& a);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("multimap cons compare alloc pass")
{
    {
    typedef test_compare<std::less<int> > C;
    typedef test_allocator<std::pair<const int, double> > A;
    contiguous::multimap<int, double, C, A> m(C(4), A(5));
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(4));
    REQUIRE(m.get_allocator() == A(5));
    }
#if TEST_STD_VER >= 11
    {
    typedef test_compare<std::less<int> > C;
    typedef min_allocator<std::pair<const int, double> > A;
    contiguous::multimap<int, double, C, A> m(C(4), A());
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(4));
    REQUIRE(m.get_allocator() == A());
    }
    {
    typedef test_compare<std::less<int> > C;
    typedef explicit_allocator<std::pair<const int, double> > A;
    contiguous::multimap<int, double, C, A> m(C(4), A{});
    REQUIRE(m.empty());
    REQUIRE(m.begin() == m.end());
    REQUIRE(m.key_comp() == C(4));
    REQUIRE(m.get_allocator() == A{});
    }
#endif
}
