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

// http://llvm.org/bugs/show_bug.cgi?id=16542

#include "defs.h"

#include "catch.hpp"

#include "contiguous/map.h"

#ifndef _LIBCPP_HAS_NO_VARIADICS

#include <tuple>

#endif

TEST_CASE("map access index tuple pass")
{
#ifndef _LIBCPP_HAS_NO_VARIADICS
    using namespace contiguous;
    using namespace std;
    map<tuple<int,int>, size_t> m;
    m[make_tuple(2,3)]=7;
#endif
}
