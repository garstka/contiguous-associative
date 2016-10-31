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

// template <class InputIterator>
//   void insert(InputIterator first, InputIterator last);

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "test_iterators.h"
#include "min_allocator.h"

TEST_CASE("set insert iter iter pass")
{
    {
        typedef contiguous::set<int> M;
        typedef int V;
        V ar[] =
        {
            1,
            1,
            1,
            2,
            2,
            2,
            3,
            3,
            3
        };
        M m;
        m.insert(input_iterator<const V*>(ar),
                 input_iterator<const V*>(ar + sizeof(ar)/sizeof(ar[0])));
        REQUIRE(m.size() == 3);
        REQUIRE(*m.begin() == 1);
        REQUIRE(*next(m.begin()) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
    }
#if TEST_STD_VER >= 11
    {
        typedef contiguous::set<int, std::less<int>, min_allocator<int>> M;
        typedef int V;
        V ar[] =
        {
            1,
            1,
            1,
            2,
            2,
            2,
            3,
            3,
            3
        };
        M m;
        m.insert(input_iterator<const V*>(ar),
                 input_iterator<const V*>(ar + sizeof(ar)/sizeof(ar[0])));
        REQUIRE(m.size() == 3);
        REQUIRE(*m.begin() == 1);
        REQUIRE(*next(m.begin()) == 2);
        REQUIRE(*next(m.begin(), 2) == 3);
    }
#endif
}
