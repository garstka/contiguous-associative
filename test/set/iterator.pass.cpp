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

//       iterator begin();
// const_iterator begin() const;
//       iterator end();
// const_iterator end()   const;
//
//       reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;
//       reverse_iterator rend();
// const_reverse_iterator rend()   const;
//
// const_iterator         cbegin()  const;
// const_iterator         cend()    const;
// const_reverse_iterator crbegin() const;
// const_reverse_iterator crend()   const;

#include "defs.h"

#include "contiguous/set.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("set iterator pass")
{
    {
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
            3,
            4,
            4,
            4,
            5,
            5,
            5,
            6,
            6,
            6,
            7,
            7,
            7,
            8,
            8,
            8
        };
        contiguous::set<int> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        contiguous::set<int>::iterator i;
        i = m.begin();
        contiguous::set<int>::const_iterator k = i;
        REQUIRE(i == k);
        for (int j = 1; j <= m.size(); ++j, ++i)
            REQUIRE(*i == j);
    }
    {
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
            3,
            4,
            4,
            4,
            5,
            5,
            5,
            6,
            6,
            6,
            7,
            7,
            7,
            8,
            8,
            8
        };
        const contiguous::set<int> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.cbegin(), m.cend()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        REQUIRE(std::distance(m.crbegin(), m.crend()) == m.size());
        contiguous::set<int>::const_iterator i;
        i = m.begin();
        for (int j = 1; j <= m.size(); ++j, ++i)
            REQUIRE(*i == j);
    }
#if TEST_STD_VER >= 11
    {
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
            3,
            4,
            4,
            4,
            5,
            5,
            5,
            6,
            6,
            6,
            7,
            7,
            7,
            8,
            8,
            8
        };
        contiguous::set<int, std::less<int>, min_allocator<int>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        contiguous::set<int, std::less<int>, min_allocator<int>>::iterator i;
        i = m.begin();
        contiguous::set<int, std::less<int>, min_allocator<int>>::const_iterator k = i;
        REQUIRE(i == k);
        for (int j = 1; j <= m.size(); ++j, ++i)
            REQUIRE(*i == j);
    }
    {
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
            3,
            4,
            4,
            4,
            5,
            5,
            5,
            6,
            6,
            6,
            7,
            7,
            7,
            8,
            8,
            8
        };
        const contiguous::set<int, std::less<int>, min_allocator<int>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.cbegin(), m.cend()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        REQUIRE(std::distance(m.crbegin(), m.crend()) == m.size());
        contiguous::set<int, std::less<int>, min_allocator<int>>::const_iterator i;
        i = m.begin();
        for (int j = 1; j <= m.size(); ++j, ++i)
            REQUIRE(*i == j);
    }
#endif
#if LIBCPP_STD_VER > 11
    { // N3644 testing
        typedef contiguous::set<int> C;
        C::iterator ii1{}, ii2{};
        C::iterator ii4 = ii1;
        C::const_iterator cii{};
        REQUIRE ( ii1 == ii2 );
        REQUIRE ( ii1 == ii4 );

        REQUIRE (!(ii1 != ii2 ));

        REQUIRE ( (ii1 == cii ));
        REQUIRE ( (cii == ii1 ));
        REQUIRE (!(ii1 != cii ));
        REQUIRE (!(cii != ii1 ));
    }
#endif
}
