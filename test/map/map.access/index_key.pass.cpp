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

// mapped_type& operator[](const key_type& k);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "test_macros.h"
#include "count_new.hpp"
#include "min_allocator.h"
#include "private_constructor.hpp"
#if TEST_STD_VER >= 11
#include "container_test_types.h"
#endif

TEST_CASE("map access index key pass")
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
    REQUIRE(m[1] == 1.5);
    REQUIRE(m.size() == 7);
    m[1] = -1.5;
    REQUIRE(m[1] == -1.5);
    REQUIRE(m.size() == 7);
    REQUIRE(m[6] == 0);
    REQUIRE(m.size() == 8);
    m[6] = 6.5;
    REQUIRE(m[6] == 6.5);
    REQUIRE(m.size() == 8);
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
    REQUIRE(m[1] == 1.5);
    REQUIRE(m.size() == 7);
    const int i = 1;
    m[i] = -1.5;
    REQUIRE(m[1] == -1.5);
    REQUIRE(m.size() == 7);
    REQUIRE(m[6] == 0);
    REQUIRE(m.size() == 8);
    m[6] = 6.5;
    REQUIRE(m[6] == 6.5);
    REQUIRE(m.size() == 8);
    }
    {
        // Use "container_test_types.h" to check what arguments get passed
        // to the allocator for operator[]
        using Container = TCT::map<>;
        using Key = Container::key_type;
        using MappedType = Container::mapped_type;
        using ValueTp = Container::value_type;
        ConstructController* cc = getConstructController();
        cc->reset();
        {
            Container c;
            const Key k(1);
            cc->expect<std::piecewise_construct_t const&, std::tuple<Key const&>&&, std::tuple<>&&>();
            MappedType& mref = c[k];
            REQUIRE(!cc->unchecked());
            {
                DisableAllocationGuard g;
                MappedType& mref2 = c[k];
                REQUIRE(&mref == &mref2);
            }
        }
        {
            Container c;
            Key k(1);
            cc->expect<std::piecewise_construct_t const&, std::tuple<Key const&>&&, std::tuple<>&&>();
            MappedType& mref = c[k];
            REQUIRE(!cc->unchecked());
            {
                DisableAllocationGuard g;
                MappedType& mref2 = c[k];
                REQUIRE(&mref == &mref2);
            }
        }
    }
#endif
#if TEST_STD_VER > 11
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
    contiguous::map<int, double, std::less<>> m(ar, ar+sizeof(ar)/sizeof(ar[0]));

    REQUIRE(m.size() == 7);
    REQUIRE(m[1] == 1.5);
    REQUIRE(m.size() == 7);
    m[1] = -1.5;
    REQUIRE(m[1] == -1.5);
    REQUIRE(m.size() == 7);
    REQUIRE(m[6] == 0);
    REQUIRE(m.size() == 8);
    m[6] = 6.5;
    REQUIRE(m[6] == 6.5);
    REQUIRE(m.size() == 8);
    }
#endif
}
