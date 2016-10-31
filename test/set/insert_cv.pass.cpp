//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class set

// pair<iterator, bool> insert(const value_type& v);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set insert cv pass")
{
    {
        typedef contiguous::set<int> M;
        typedef std::pair<M::iterator, bool> R;
        M m;
        R r = m.insert(M::value_type(2));
        REQUIRE(r.second);
        REQUIRE(r.first == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r.first == 2);

        r = m.insert(M::value_type(1));
        REQUIRE(r.second);
        REQUIRE(r.first == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(*r.first == 1);

        r = m.insert(M::value_type(3));
        REQUIRE(r.second);
        REQUIRE(r.first == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r.first == 3);

        r = m.insert(M::value_type(3));
        REQUIRE(!r.second);
        REQUIRE(r.first == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r.first == 3);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
        typedef std::pair<M::iterator, bool> R;
        M m;
        R r = m.insert(M::value_type(2));
        REQUIRE(r.second);
        REQUIRE(r.first == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r.first == 2);

        r = m.insert(M::value_type(1));
        REQUIRE(r.second);
        REQUIRE(r.first == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(*r.first == 1);

        r = m.insert(M::value_type(3));
        REQUIRE(r.second);
        REQUIRE(r.first == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r.first == 3);

        r = m.insert(M::value_type(3));
        REQUIRE(!r.second);
        REQUIRE(r.first == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r.first == 3);
    }
#endif
}
