//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class multiset

// insert(...)

// UNSUPPORTED: c++98, c++03

#include "defs.h"
#include "catch.hpp"

#include "contiguous/multiset.h"

#include "container_test_types.h"
#include "set_allocator_requirement_test_templates.h"

TEST_CASE("multiset insert allocator requirements pass")
{
  testMultisetInsert<TCT::multiset<> >();
}
