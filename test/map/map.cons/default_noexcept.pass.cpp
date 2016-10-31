//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// map()
//    noexcept(
//        is_nothrow_default_constructible<allocator_type>::value &&
//        is_nothrow_default_constructible<key_compare>::value &&
//        is_nothrow_copy_constructible<key_compare>::value);

// This tests a conforming extension

// UNSUPPORTED: c++98, c++03

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"

#include "test_macros.h"
#include "MoveOnly.h"
#include "test_allocator.h"

template <class T>
struct some_comp
{
    typedef T value_type;
    some_comp();
    bool operator()(const T&, const T&) const { return false; }
};

TEST_CASE("map cons default noexcept pass")
{
    typedef std::pair<const MoveOnly, MoveOnly> V;
    {
        typedef contiguous::map<MoveOnly, MoveOnly> C;
        LIBCPP_STATIC_ASSERT(std::is_nothrow_default_constructible<C>::value, "");
    }
    {
        typedef contiguous::map<MoveOnly, MoveOnly, std::less<MoveOnly>, test_allocator<V>> C;
        LIBCPP_STATIC_ASSERT(std::is_nothrow_default_constructible<C>::value, "");
    }
    {
        typedef contiguous::map<MoveOnly, MoveOnly, std::less<MoveOnly>, other_allocator<V>> C;
        static_assert(!std::is_nothrow_default_constructible<C>::value, "");
    }
    {
        typedef contiguous::map<MoveOnly, MoveOnly, some_comp<MoveOnly>> C;
        static_assert(!std::is_nothrow_default_constructible<C>::value, "");
    }
}
