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

// insert(...);
// emplace(...);
// emplace_hint(...);

// UNSUPPORTED: c++98, c++03

#include "defs.h"

#include "catch.hpp"

#include "contiguous/map.h"

#include "container_test_types.h"
#include "map_allocator_requirement_test_templates.h"

TEST_CASE("map modifiers insert and emplace allocator requirements pass")
{
  testMapInsert<TCT::map<> >();
  testMapInsertHint<TCT::map<> >();
  testMapEmplace<TCT::map<> >();
  testMapEmplaceHint<TCT::map<> >();
}
