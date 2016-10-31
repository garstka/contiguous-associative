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

// pair<iterator, bool> insert(value_type&& v);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "min_allocator.h"

TEST_CASE("set insert rv pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef contiguous::set<MoveOnly> M;
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
        typedef contiguous::set<MoveOnly, std::less<MoveOnly>, min_allocator<MoveOnly>> M;
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
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
