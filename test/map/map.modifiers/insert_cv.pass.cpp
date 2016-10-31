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

// pair<iterator, bool> insert(const value_type& v);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "test_macros.h"
#include "min_allocator.h"

template <class Container>
void do_insert_cv_test()
{
    typedef Container M;
    typedef std::pair<typename M::iterator, bool> R;
    typedef typename M::value_type VT;
    M m;

    const VT v1(2, 2.5);
    R r = m.insert(v1);
    REQUIRE(r.second);
    REQUIRE(r.first == m.begin());
    REQUIRE(m.size() == 1);
    REQUIRE(r.first->first == 2);
    REQUIRE(r.first->second == 2.5);

    const VT v2(1, 1.5);
    r = m.insert(v2);
    REQUIRE(r.second);
    REQUIRE(r.first == m.begin());
    REQUIRE(m.size() == 2);
    REQUIRE(r.first->first == 1);
    REQUIRE(r.first->second == 1.5);

    const VT v3(3, 3.5);
    r = m.insert(v3);
    REQUIRE(r.second);
    REQUIRE(r.first == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r.first->first == 3);
    REQUIRE(r.first->second == 3.5);

    const VT v4(3, 4.5);
    r = m.insert(v4);
    REQUIRE(!r.second);
    REQUIRE(r.first == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r.first->first == 3);
    REQUIRE(r.first->second == 3.5);
}

TEST_CASE("map modifiers insert cv pass")
{
    do_insert_cv_test<contiguous::map<int, double> >();
#if TEST_STD_VER >= 11
    {
        typedef contiguous::map<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
        do_insert_cv_test<M>();
    }
#endif
}
