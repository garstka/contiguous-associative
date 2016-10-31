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

// template <class P>
//     iterator insert(const_iterator position, P&& p);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "min_allocator.h"
#include "test_macros.h"

template <class Container, class Pair>
void do_insert_iter_rv_test()
{
    typedef Container M;
    typedef Pair P;
    typedef typename M::iterator R;
    M m;
    R r = m.insert(m.end(), P(2, 2));
    REQUIRE(r == m.begin());
    REQUIRE(m.size() == 1);
    REQUIRE(r->first == 2);
    REQUIRE(r->second == 2);

    r = m.insert(m.end(), P(1, 1));
    REQUIRE(r == m.begin());
    REQUIRE(m.size() == 2);
    REQUIRE(r->first == 1);
    REQUIRE(r->second == 1);

    r = m.insert(m.end(), P(3, 3));
    REQUIRE(r == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r->first == 3);
    REQUIRE(r->second == 3);

    r = m.insert(m.end(), P(3, 4));
    REQUIRE(r == prev(m.end()));
    REQUIRE(m.size() == 3);
    REQUIRE(r->first == 3);
    REQUIRE(r->second == 3);
}
TEST_CASE("map modifiers insert iter rv pass")
{
    do_insert_iter_rv_test<contiguous::map<int, MoveOnly>, std::pair<int, MoveOnly>>();
    do_insert_iter_rv_test<contiguous::map<int, MoveOnly>, std::pair<const int, MoveOnly>>();

    {
        typedef contiguous::map<int, MoveOnly, std::less<int>, min_allocator<std::pair<const int, MoveOnly>>> M;
        typedef std::pair<int, MoveOnly> P;
        typedef std::pair<const int, MoveOnly> CP;
        do_insert_iter_rv_test<M, P>();
        do_insert_iter_rv_test<M, CP>();
    }
    {
        typedef contiguous::map<int, MoveOnly> M;
        typedef M::iterator R;
        M m;
        R r = m.insert(m.end(), {2, MoveOnly(2)});
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(r->first == 2);
        REQUIRE(r->second == 2);

        r = m.insert(m.end(), {1, MoveOnly(1)});
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(r->first == 1);
        REQUIRE(r->second == 1);

        r = m.insert(m.end(), {3, MoveOnly(3)});
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(r->first == 3);
        REQUIRE(r->second == 3);

        r = m.insert(m.end(), {3, MoveOnly(3)});
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(r->first == 3);
        REQUIRE(r->second == 3);
    }

}
