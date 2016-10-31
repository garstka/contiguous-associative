//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03

// <map>

// class map

// mapped_type& operator[](key_type&& k);

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "test_macros.h"
#include "count_new.hpp"
#include "MoveOnly.h"
#include "min_allocator.h"
#include "container_test_types.h"

TEST_CASE("map access index rv key pass")
{
    {
    contiguous::map<MoveOnly, double> m;
    REQUIRE(m.size() == 0);
    REQUIRE(m[1] == 0.0);
    REQUIRE(m.size() == 1);
    m[1] = -1.5;
    REQUIRE(m[1] == -1.5);
    REQUIRE(m.size() == 1);
    REQUIRE(m[6] == 0);
    REQUIRE(m.size() == 2);
    m[6] = 6.5;
    REQUIRE(m[6] == 6.5);
    REQUIRE(m.size() == 2);
    }
    {
    typedef std::pair<const MoveOnly, double> V;
    contiguous::map<MoveOnly, double, std::less<MoveOnly>, min_allocator<V>> m;
    REQUIRE(m.size() == 0);
    REQUIRE(m[1] == 0.0);
    REQUIRE(m.size() == 1);
    m[1] = -1.5;
    REQUIRE(m[1] == -1.5);
    REQUIRE(m.size() == 1);
    REQUIRE(m[6] == 0);
    REQUIRE(m.size() == 2);
    m[6] = 6.5;
    REQUIRE(m[6] == 6.5);
    REQUIRE(m.size() == 2);
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
            Key k(1);
            cc->expect<std::piecewise_construct_t const&, std::tuple<Key &&>&&, std::tuple<>&&>();
            MappedType& mref = c[std::move(k)];
            REQUIRE(!cc->unchecked());
            {
                Key k2(1);
                DisableAllocationGuard g;
                MappedType& mref2 = c[std::move(k2)];
                REQUIRE(&mref == &mref2);
            }
        }
    }
}
