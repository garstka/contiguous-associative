//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class set

// insert(...)
// emplace(...)
// emplace_hint(...)

// UNSUPPORTED: c++98, c++03

#include "defs.h"

#include "catch.hpp"

#include "contiguous/set.h"
#include "container_test_types.h"
#include "set_allocator_requirement_test_templates.h"

TEST_CASE("set insert and emplace allocator requirements pass")
{
  testSetInsert<TCT::set<> >();
  testSetEmplace<TCT::set<> >();
  testSetEmplaceHint<TCT::set<> >();
}
