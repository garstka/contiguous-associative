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

// class map

// pair<iterator, bool> insert( value_type&& v);  // C++17 and later
// template <class P>
//   pair<iterator, bool> insert(P&& p);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "min_allocator.h"
#include "test_macros.h"

template <class Container, class Pair>
void do_insert_rv_test()
{
    typedef Container M;
    typedef Pair P;
    typedef std::pair<typename M::iterator, bool> R;
    M m;
    R r = m.insert(P(2, 2));
    REQUIRE(r.second);
    REQUIRE(r.first == m.begin());
    REQUIRE(m.size() == 1);
    REQUIRE(r.first->first == 2);
    REQUIRE(r.first->second == 2);

    r = m.insert(P(1, 1));
    REQUIRE(r.second);
    REQUIRE(r.first == m.begin());
    REQUIRE(m.size() == 2);
    REQUIRE(r.first->first == 1);
    REQUIRE(r.first->second == 1);

    r = m.insert(P(3, 3));
    REQUIRE(r.second);
    REQUIRE(r.first == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r.first->first == 3);
    REQUIRE(r.first->second == 3);

    r = m.insert(P(3, 3));
    REQUIRE(!r.second);
    REQUIRE(r.first == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r.first->first == 3);
    REQUIRE(r.first->second == 3);
}

TEST_CASE("map modifiers insert rv pass")
{
    do_insert_rv_test<contiguous::map<int, MoveOnly>, std::pair<int, MoveOnly>>();
    do_insert_rv_test<contiguous::map<int, MoveOnly>, std::pair<const int, MoveOnly>>();

    {
        typedef contiguous::map<int, MoveOnly, std::less<int>, min_allocator<std::pair<const int, MoveOnly>>> M;
        typedef std::pair<int, MoveOnly> P;
        typedef std::pair<const int, MoveOnly> CP;
        do_insert_rv_test<M, P>();
        do_insert_rv_test<M, CP>();
    }
    {
        typedef contiguous::map<int, MoveOnly> M;
        typedef std::pair<M::iterator, bool> R;
        M m;
        R r = m.insert({2, MoveOnly(2)});
        REQUIRE(r.second);
        REQUIRE(r.first == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(r.first->first == 2);
        REQUIRE(r.first->second == 2);

        r = m.insert({1, MoveOnly(1)});
        REQUIRE(r.second);
        REQUIRE(r.first == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(r.first->first == 1);
        REQUIRE(r.first->second == 1);

        r = m.insert({3, MoveOnly(3)});
        REQUIRE(r.second);
        REQUIRE(r.first == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(r.first->first == 3);
        REQUIRE(r.first->second == 3);

        r = m.insert({3, MoveOnly(3)});
        REQUIRE(!r.second);
        REQUIRE(r.first == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(r.first->first == 3);
        REQUIRE(r.first->second == 3);
    }
}
