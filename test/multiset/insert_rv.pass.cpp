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

// iterator insert(value_type&& v);

#include "defs.h"

#include "contiguous/multiset.h"
#include "catch.hpp"

#include "MoveOnly.h"
#include "min_allocator.h"

TEST_CASE("multiset insert rv pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    {
        typedef contiguous::multiset<MoveOnly> M;
        typedef M::iterator R;
        M m;
        R r = m.insert(M::value_type(2));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r == 2);

        r = m.insert(M::value_type(1));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(*r == 1);

        r = m.insert(M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r == 3);

        r = m.insert(M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 4);
        REQUIRE(*r == 3);
    }
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
#if TEST_STD_VER >= 11
    {
        typedef contiguous::multiset<MoveOnly, std::less<MoveOnly>, min_allocator<MoveOnly>> M;
        typedef M::iterator R;
        M m;
        R r = m.insert(M::value_type(2));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r == 2);

        r = m.insert(M::value_type(1));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(*r == 1);

        r = m.insert(M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r == 3);

        r = m.insert(M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 4);
        REQUIRE(*r == 3);
    }
#endif
}
