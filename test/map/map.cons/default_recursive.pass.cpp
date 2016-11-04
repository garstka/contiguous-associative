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

// map();

#include "defs.h"

#ifndef MAP_REQUIRE_COMPLETE_TYPE
#include "catch.hpp"
#include "contiguous/map.h"

struct X
{
    contiguous::map<int, X> m;
    contiguous::map<int, X>::iterator i;
    contiguous::map<int, X>::const_iterator ci;
    contiguous::map<int, X>::reverse_iterator ri;
    contiguous::map<int, X>::const_reverse_iterator cri;
};

TEST_CASE("map cons default recursive pass")
{
}
#endif