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

// insert(...)

// UNSUPPORTED: c++98, c++03

#include "defs.h"

#include "catch.hpp"
#include "contiguous/multimap.h"

#include "container_test_types.h"
#include "map_allocator_requirement_test_templates.h"


TEST_CASE("multimap modifiers insert allocator requirements pass")
{
  testMultimapInsert<TCT::multimap<> >();
  testMultimapInsertHint<TCT::multimap<> >();
}
