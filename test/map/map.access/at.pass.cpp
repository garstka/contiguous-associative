//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// XFAIL: libcpp-no-exceptions
// <map>

// class map

//       mapped_type& at(const key_type& k);
// const mapped_type& at(const key_type& k) const;

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "min_allocator.h"

TEST_CASE("map access at pass")
{
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1.5),
            V(2, 2.5),
            V(3, 3.5),
            V(4, 4.5),
            V(5, 5.5),
            V(7, 7.5),
            V(8, 8.5),
        };
        contiguous::map<int, double> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 7);
        REQUIRE(m.at(1) == 1.5);
        m.at(1) = -1.5;
        REQUIRE(m.at(1) == -1.5);
        REQUIRE(m.at(2) == 2.5);
        REQUIRE(m.at(3) == 3.5);
        REQUIRE(m.at(4) == 4.5);
        REQUIRE(m.at(5) == 5.5);
        try
        {
            m.at(6);
            REQUIRE(false);
        }
        catch (std::out_of_range&)
        {
        }
        REQUIRE(m.at(7) == 7.5);
        REQUIRE(m.at(8) == 8.5);
        REQUIRE(m.size() == 7);
    }
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1.5),
            V(2, 2.5),
            V(3, 3.5),
            V(4, 4.5),
            V(5, 5.5),
            V(7, 7.5),
            V(8, 8.5),
        };
        const contiguous::map<int, double> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 7);
        REQUIRE(m.at(1) == 1.5);
        REQUIRE(m.at(2) == 2.5);
        REQUIRE(m.at(3) == 3.5);
        REQUIRE(m.at(4) == 4.5);
        REQUIRE(m.at(5) == 5.5);
        try
        {
            m.at(6);
            REQUIRE(false);
        }
        catch (std::out_of_range&)
        {
        }
        REQUIRE(m.at(7) == 7.5);
        REQUIRE(m.at(8) == 8.5);
        REQUIRE(m.size() == 7);
    }
#if TEST_STD_VER >= 11
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1.5),
            V(2, 2.5),
            V(3, 3.5),
            V(4, 4.5),
            V(5, 5.5),
            V(7, 7.5),
            V(8, 8.5),
        };
        contiguous::map<int, double, std::less<int>, min_allocator<V>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 7);
        REQUIRE(m.at(1) == 1.5);
        m.at(1) = -1.5;
        REQUIRE(m.at(1) == -1.5);
        REQUIRE(m.at(2) == 2.5);
        REQUIRE(m.at(3) == 3.5);
        REQUIRE(m.at(4) == 4.5);
        REQUIRE(m.at(5) == 5.5);
        try
        {
            m.at(6);
            REQUIRE(false);
        }
        catch (std::out_of_range&)
        {
        }
        REQUIRE(m.at(7) == 7.5);
        REQUIRE(m.at(8) == 8.5);
        REQUIRE(m.size() == 7);
    }
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1.5),
            V(2, 2.5),
            V(3, 3.5),
            V(4, 4.5),
            V(5, 5.5),
            V(7, 7.5),
            V(8, 8.5),
        };
        const contiguous::map<int, double, std::less<int>, min_allocator<V>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        REQUIRE(m.size() == 7);
        REQUIRE(m.at(1) == 1.5);
        REQUIRE(m.at(2) == 2.5);
        REQUIRE(m.at(3) == 3.5);
        REQUIRE(m.at(4) == 4.5);
        REQUIRE(m.at(5) == 5.5);
        try
        {
            m.at(6);
            REQUIRE(false);
        }
        catch (std::out_of_range&)
        {
        }
        REQUIRE(m.at(7) == 7.5);
        REQUIRE(m.at(8) == 8.5);
        REQUIRE(m.size() == 7);
    }
#endif
}
