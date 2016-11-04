//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class multimap

// multimap();

#include "defs.h"

#ifndef MULTIMAP_REQUIRE_COMPLETE_TYPE
#include "catch.hpp"

#include "contiguous/multimap.h"

struct X
{
    contiguous::multimap<int, X> m;
    contiguous::multimap<int, X>::iterator i;
    contiguous::multimap<int, X>::const_iterator ci;
    contiguous::multimap<int, X>::reverse_iterator ri;
    contiguous::multimap<int, X>::const_reverse_iterator cri;
};

TEST_CASE("multimap cons default recursive pass")
{
}
#endif