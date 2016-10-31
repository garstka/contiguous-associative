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

// iterator insert(const_iterator position, const value_type& v);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set insert iter cv pass")
{
    {
        typedef contiguous::set<int> M;
        typedef M::iterator R;
        M m;
        R r = m.insert(m.cend(), M::value_type(2));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r == 2);

        r = m.insert(m.cend(), M::value_type(1));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(*r == 1);

        r = m.insert(m.cend(), M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r == 3);

        r = m.insert(m.cend(), M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r == 3);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
        typedef M::iterator R;
        M m;
        R r = m.insert(m.cend(), M::value_type(2));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r == 2);

        r = m.insert(m.cend(), M::value_type(1));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(*r == 1);

        r = m.insert(m.cend(), M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r == 3);

        r = m.insert(m.cend(), M::value_type(3));
        REQUIRE(r == prev(m.end()));
        REQUIRE(m.size() == 3);
        REQUIRE(*r == 3);
    }
#endif
}
