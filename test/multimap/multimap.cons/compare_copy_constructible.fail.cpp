//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// Check that contiguous::multimap fails to instantiate if the comparison predicate is 
// not copy-constructible. This is LWG issue 2436

#include "defs.h"
#include "fail_defs.h"
#include "catch.hpp"

#include "contiguous/multimap.h"

template <class T>
struct Comp {
	bool operator () (const T& lhs, const T& rhs) const { return lhs < rhs; }

	Comp () {}
private:
	Comp (const Comp &); // declared but not defined
	};


TEST_CASE("multimap cons compare copy constructible fail") {
#ifdef MULTIMAP_COMPARE_COPY_CONSTRUCTIBLE_FAIL
	contiguous::multimap<int, int, Comp<int> > m;
	REQUIRE(false); // this should have failed at compile time
#endif
}
