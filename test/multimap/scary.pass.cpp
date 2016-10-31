//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class map class multimap

// Extension:  SCARY/N2913 iterator compatibility between map and multimap

#include "defs.h"

#include "catch.hpp"
#include "contiguous/multimap.h"
#include "contiguous/map.h"

TEST_CASE("multimap scary pass")
{
    typedef contiguous::map<int, int> M1;
    typedef contiguous::multimap<int, int> M2;
    M2::iterator i;
    M1::iterator j = i;
    ((void)j);
}
