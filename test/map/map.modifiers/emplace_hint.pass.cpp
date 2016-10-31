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

// template <class... Args>
//   iterator emplace_hint(const_iterator position, Args&&... args);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "Emplaceable.h"
#include "DefaultOnly.h"
#include "min_allocator.h"

TEST_CASE("map modifiers emplace hint pass")
{
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
	#ifndef IGNORE_DEFAULT_ONLY
    {
        typedef contiguous::map<int, DefaultOnly> M;
        typedef M::iterator R;
        M m;
        REQUIRE(DefaultOnly::count == 0);
        R r = m.emplace_hint(m.end());
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(m.begin()->first == 0);
        REQUIRE(m.begin()->second == DefaultOnly());
        REQUIRE(DefaultOnly::count == 1);
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                       std::forward_as_tuple(1),
                                       std::forward_as_tuple());
        REQUIRE(r == next(m.begin()));
        REQUIRE(m.size() == 2);
        REQUIRE(next(m.begin())->first == 1);
        REQUIRE(next(m.begin())->second == DefaultOnly());
        REQUIRE(DefaultOnly::count == 2);
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                       std::forward_as_tuple(1),
                                       std::forward_as_tuple());
        REQUIRE(r == next(m.begin()));
        REQUIRE(m.size() == 2);
        REQUIRE(next(m.begin())->first == 1);
        REQUIRE(next(m.begin())->second == DefaultOnly());
        REQUIRE(DefaultOnly::count == 2);
    }
    REQUIRE(DefaultOnly::count == 0);
#endif
    {
        typedef contiguous::map<int, Emplaceable> M;
        typedef M::iterator R;
        M m;
        R r = m.emplace_hint(m.end(), std::piecewise_construct,
                                       std::forward_as_tuple(2),
                                       std::forward_as_tuple());
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == Emplaceable());
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                    std::forward_as_tuple(1),
                                    std::forward_as_tuple(2, 3.5));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == Emplaceable(2, 3.5));
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                    std::forward_as_tuple(1),
                                    std::forward_as_tuple(2, 3.5));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == Emplaceable(2, 3.5));
    }
    {
        typedef contiguous::map<int, double> M;
        typedef M::iterator R;
        M m;
        R r = m.emplace_hint(m.end(), M::value_type(2, 3.5));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 3.5);
    }
#if TEST_STD_VER >= 11
#ifndef IGNORE_DEFAULT_ONLY
    {
        typedef contiguous::map<int, DefaultOnly, std::less<int>, min_allocator<std::pair<const int, DefaultOnly>>> M;
        typedef M::iterator R;
        M m;
        REQUIRE(DefaultOnly::count == 0);
        R r = m.emplace_hint(m.end());
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(m.begin()->first == 0);
        REQUIRE(m.begin()->second == DefaultOnly());
        REQUIRE(DefaultOnly::count == 1);
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                       std::forward_as_tuple(1),
                                       std::forward_as_tuple());
        REQUIRE(r == next(m.begin()));
        REQUIRE(m.size() == 2);
        REQUIRE(next(m.begin())->first == 1);
        REQUIRE(next(m.begin())->second == DefaultOnly());
        REQUIRE(DefaultOnly::count == 2);
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                       std::forward_as_tuple(1),
                                       std::forward_as_tuple());
        REQUIRE(r == next(m.begin()));
        REQUIRE(m.size() == 2);
        REQUIRE(next(m.begin())->first == 1);
        REQUIRE(next(m.begin())->second == DefaultOnly());
        REQUIRE(DefaultOnly::count == 2);
    }
    REQUIRE(DefaultOnly::count == 0);
#endif
    {
        typedef contiguous::map<int, Emplaceable, std::less<int>, min_allocator<std::pair<const int, Emplaceable>>> M;
        typedef M::iterator R;
        M m;
        R r = m.emplace_hint(m.end(), std::piecewise_construct,
                                       std::forward_as_tuple(2),
                                       std::forward_as_tuple());
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == Emplaceable());
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                    std::forward_as_tuple(1),
                                    std::forward_as_tuple(2, 3.5));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == Emplaceable(2, 3.5));
        r = m.emplace_hint(m.end(), std::piecewise_construct,
                                    std::forward_as_tuple(1),
                                    std::forward_as_tuple(2, 3.5));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 2);
        REQUIRE(m.begin()->first == 1);
        REQUIRE(m.begin()->second == Emplaceable(2, 3.5));
    }
    {
        typedef contiguous::map<int, double, std::less<int>, min_allocator<std::pair<const int, double>>> M;
        typedef M::iterator R;
        M m;
        R r = m.emplace_hint(m.end(), M::value_type(2, 3.5));
        REQUIRE(r == m.begin());
        REQUIRE(m.size() == 1);
        REQUIRE(m.begin()->first == 2);
        REQUIRE(m.begin()->second == 3.5);
    }
#endif
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
