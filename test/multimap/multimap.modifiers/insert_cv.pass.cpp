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

// iterator insert(const value_type& v);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "test_macros.h"
#include "min_allocator.h"

template <class Container>
void do_insert_test() {
    typedef Container M;
    typedef typename M::iterator R;
    typedef typename M::value_type VT;
    M m;
    const VT v1(2, 2.5);
    R r = m.insert(v1);
    REQUIRE(r == m.begin());
    REQUIRE(m.size() == 1);
    REQUIRE(r->first == 2);
    REQUIRE(r->second == 2.5);

    const VT v2(1, 1.5);
    r = m.insert(v2);
    REQUIRE(r == m.begin());
    REQUIRE(m.size() == 2);
    REQUIRE(r->first == 1);
    REQUIRE(r->second == 1.5);

    const VT v3(3, 3.5);
    r = m.insert(v3);
    REQUIRE(r == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r->first == 3);
    REQUIRE(r->second == 3.5);

    const VT v4(3, 3.5);
    r = m.insert(v4);
    REQUIRE(r == prev(m.end()));
    REQUIRE(m.size() == 4);
    REQUIRE(r->first == 3);
    REQUIRE(r->second == 3.5);
}

TEST_CASE("multimap modifiers insert cv pass")
{
    {
        typedef contiguous::multimap<int, double> Container;
        do_insert_test<Container>();
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::multimap<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> Container;
        do_insert_test<Container>();
    }
#endif
}
