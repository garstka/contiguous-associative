//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03

// <map>

// class multimap

// template <class P>
//   iterator insert(P&& p);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "min_allocator.h"
#include "test_macros.h"

template <class Container>
void do_insert_rv_test()
{
    typedef contiguous::multimap<int, MoveOnly> M;
    typedef typename M::iterator R;
    typedef typename M::value_type VT;
    M m;
    R r = m.insert(VT(2, 2));
    REQUIRE(r == m.begin());
    REQUIRE(m.size() == 1);
    REQUIRE(r->first == 2);
    REQUIRE(r->second == 2);

    r = m.insert(VT(1, 1));
    REQUIRE(r == m.begin());
    REQUIRE(m.size() == 2);
    REQUIRE(r->first == 1);
    REQUIRE(r->second == 1);

    r = m.insert(VT(3, 3));
    REQUIRE(r == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r->first == 3);
    REQUIRE(r->second == 3);

    r = m.insert(VT(3, 3));
    REQUIRE(r == prev(m.end()));
    REQUIRE(m.size() == 4);
    REQUIRE(r->first == 3);
    REQUIRE(r->second == 3);
}

TEST_CASE("multimap modifiers insert rv pass")
{
    do_insert_rv_test<contiguous::multimap<int, MoveOnly>>();
    {
        typedef contiguous::multimap<int, MoveOnly, std::less<int>, min_allocator<std::pair<const int, MoveOnly>>> M;
        do_insert_rv_test<M>();
    }
    {
        typedef contiguous::multimap<int, MoveOnly> M;
        typedef M::iterator R;
        M m;
        R r = m.insert({2, MoveOnly(2)});
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(r->first == 2);
        REQUIRE(r->second == 2);

        r = m.insert({1, MoveOnly(1)});
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(r->first == 1);
        REQUIRE(r->second == 1);

        r = m.insert({3, MoveOnly(3)});
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(r->first == 3);
        REQUIRE(r->second == 3);

        r = m.insert({3, MoveOnly(3)});
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 4);
        REQUIRE(r->first == 3);
        REQUIRE(r->second == 3);
    }
}
