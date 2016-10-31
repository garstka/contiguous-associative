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

// template <class... Args>
//   iterator emplace_hint(const_iterator position, Args&&... args);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "Emplaceable.h"
#include "DefaultOnly.h"
#include "min_allocator.h"

TEST_CASE("set emplace hint pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
#ifndef IGNORE_DEFAULT_ONLY
    {
        typedef contiguous::set<DefaultOnly> M;
        typedef M::iterator R;
        M m;
        REQUIRE(DefaultOnly::count == 0);
        R r = m.emplace_hint(m.cend());
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*m.begin() == DefaultOnly());
        REQUIRE(DefaultOnly::count == 1);

        r = m.emplace_hint(m.cbegin());
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*m.begin() == DefaultOnly());
        REQUIRE(DefaultOnly::count == 1);
    }
    REQUIRE(DefaultOnly::count == 0);
#endif
    {
        typedef contiguous::set<Emplaceable> M;
        typedef M::iterator R;
        M m;
        R r = m.emplace_hint(m.cend());
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*m.begin() == Emplaceable());
        r = m.emplace_hint(m.cend(), 2, 3.5);
        REQUIRE(r == next(m.begin()));
        REQUIRE(m.size() == 2);
        REQUIRE(*r == Emplaceable(2, 3.5));
        r = m.emplace_hint(m.cbegin(), 2, 3.5);
        REQUIRE(r == next(m.begin()));
        REQUIRE(m.size() == 2);
        REQUIRE(*r == Emplaceable(2, 3.5));
    }
    {
        typedef contiguous::set<int> M;
        typedef M::iterator R;
        M m;
        R r = m.emplace_hint(m.cend(), M::value_type(2));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r == 2);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
        typedef M::iterator R;
        M m;
        R r = m.emplace_hint(m.cend(), M::value_type(2));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(*r == 2);
    }
#endif
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
