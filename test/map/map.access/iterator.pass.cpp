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

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("map access iterator pass")
{
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1),
            V(1, 1.5),
            V(1, 2),
            V(2, 1),
            V(2, 1.5),
            V(2, 2),
            V(3, 1),
            V(3, 1.5),
            V(3, 2),
            V(4, 1),
            V(4, 1.5),
            V(4, 2),
            V(5, 1),
            V(5, 1.5),
            V(5, 2),
            V(6, 1),
            V(6, 1.5),
            V(6, 2),
            V(7, 1),
            V(7, 1.5),
            V(7, 2),
            V(8, 1),
            V(8, 1.5),
            V(8, 2)
        };
        contiguous::map<int, double> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        contiguous::map<int, double>::iterator i;
        i = m.begin();
        contiguous::map<int, double>::const_iterator k = i;
        REQUIRE(i == k);
        for (int j = 1; j <= m.size(); ++j, ++i)
        {
            REQUIRE(i->first == j);
            REQUIRE(i->second == 1);
            i->second = 2.5;
            REQUIRE(i->second == 2.5);
        }
    }
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1),
            V(1, 1.5),
            V(1, 2),
            V(2, 1),
            V(2, 1.5),
            V(2, 2),
            V(3, 1),
            V(3, 1.5),
            V(3, 2),
            V(4, 1),
            V(4, 1.5),
            V(4, 2),
            V(5, 1),
            V(5, 1.5),
            V(5, 2),
            V(6, 1),
            V(6, 1.5),
            V(6, 2),
            V(7, 1),
            V(7, 1.5),
            V(7, 2),
            V(8, 1),
            V(8, 1.5),
            V(8, 2)
        };
        const contiguous::map<int, double> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.cbegin(), m.cend()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        REQUIRE(std::distance(m.crbegin(), m.crend()) == m.size());
        contiguous::map<int, double>::const_iterator i;
        i = m.begin();
        for (int j = 1; j <= m.size(); ++j, ++i)
        {
            REQUIRE(i->first == j);
            REQUIRE(i->second == 1);
        }
    }
#if TEST_STD_VER >= 11
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1),
            V(1, 1.5),
            V(1, 2),
            V(2, 1),
            V(2, 1.5),
            V(2, 2),
            V(3, 1),
            V(3, 1.5),
            V(3, 2),
            V(4, 1),
            V(4, 1.5),
            V(4, 2),
            V(5, 1),
            V(5, 1.5),
            V(5, 2),
            V(6, 1),
            V(6, 1.5),
            V(6, 2),
            V(7, 1),
            V(7, 1.5),
            V(7, 2),
            V(8, 1),
            V(8, 1.5),
            V(8, 2)
        };
        contiguous::map<int, double, std::less<int>, min_allocator<V>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        contiguous::map<int, double, std::less<int>, min_allocator<V>>::iterator i;
        i = m.begin();
        contiguous::map<int, double, std::less<int>, min_allocator<V>>::const_iterator k = i;
        REQUIRE(i == k);
        for (int j = 1; j <= m.size(); ++j, ++i)
        {
            REQUIRE(i->first == j);
            REQUIRE(i->second == 1);
            i->second = 2.5;
            REQUIRE(i->second == 2.5);
        }
    }
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1),
            V(1, 1.5),
            V(1, 2),
            V(2, 1),
            V(2, 1.5),
            V(2, 2),
            V(3, 1),
            V(3, 1.5),
            V(3, 2),
            V(4, 1),
            V(4, 1.5),
            V(4, 2),
            V(5, 1),
            V(5, 1.5),
            V(5, 2),
            V(6, 1),
            V(6, 1.5),
            V(6, 2),
            V(7, 1),
            V(7, 1.5),
            V(7, 2),
            V(8, 1),
            V(8, 1.5),
            V(8, 2)
        };
        const contiguous::map<int, double, std::less<int>, min_allocator<V>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(std::distance(m.begin(), m.end()) == m.size());
        REQUIRE(std::distance(m.cbegin(), m.cend()) == m.size());
        REQUIRE(std::distance(m.rbegin(), m.rend()) == m.size());
        REQUIRE(std::distance(m.crbegin(), m.crend()) == m.size());
        contiguous::map<int, double, std::less<int>, min_allocator<V>>::const_iterator i;
        i = m.begin();
        for (int j = 1; j <= m.size(); ++j, ++i)
        {
            REQUIRE(i->first == j);
            REQUIRE(i->second == 1);
        }
    }
#endif
#if LIBCPP_STD_VER > 11
    { // N3644 testing
        typedef contiguous::map<int, double> C;
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
