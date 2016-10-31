//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// set()
//    noexcept(
//        is_nothrow_default_constructible<allocator_type>::value &&
//        is_nothrow_default_constructible<key_compare>::value &&
//        is_nothrow_copy_constructible<key_compare>::value);

// This tests a conforming extension

// UNSUPPORTED: c++98, c++03

#include "defs.h"

#include "contiguous/set.h"
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

TEST_CASE("set cons default noexcept pass")
{
    {
        typedef contiguous::set<MoveOnly> C;
        LIBCPP_STATIC_ASSERT(std::is_nothrow_default_constructible<C>::value, "");
    }
    {
        typedef contiguous::set<MoveOnly, std::less<MoveOnly>, test_allocator<MoveOnly>> C;
        LIBCPP_STATIC_ASSERT(std::is_nothrow_default_constructible<C>::value, "");
    }
    {
        typedef contiguous::set<MoveOnly, std::less<MoveOnly>, other_allocator<MoveOnly>> C;
        static_assert(!std::is_nothrow_default_constructible<C>::value, "");
    }
    {
        typedef contiguous::set<MoveOnly, some_comp<MoveOnly>> C;
        static_assert(!std::is_nothrow_default_constructible<C>::value, "");
    }
}
