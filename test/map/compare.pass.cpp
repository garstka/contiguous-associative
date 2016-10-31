//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// template <class Key, class T, class Compare = less<Key>,
//           class Allocator = allocator<pair<const Key, T>>>
// class map

// http://llvm.org/bugs/show_bug.cgi?id=16538
// http://llvm.org/bugs/show_bug.cgi?id=16549

#include "defs.h"

#include "contiguous/map.h"
#include <utility>
#include "catch.hpp"

struct Key {
  template <typename T> Key(const T&) {}
  bool operator< (const Key&) const { return false; }
};

TEST_CASE("map compare pass")
{
    typedef contiguous::map<Key, int> MapT;
    typedef MapT::iterator Iter;
    typedef std::pair<Iter, bool> IterBool;
    {
        MapT m_empty;
        MapT m_contains;
        m_contains[Key(0)] = 42;

        Iter it = m_empty.find(Key(0));
        REQUIRE(it == m_empty.end());
        it = m_contains.find(Key(0));
        REQUIRE(it != m_contains.end());
    }
    {
        MapT map;
        IterBool result = map.insert(std::make_pair(Key(0), 42));
        REQUIRE(result.second);
        REQUIRE(result.first->second == 42);
        IterBool result2 = map.insert(std::make_pair(Key(0), 43));
        REQUIRE(!result2.second);
        REQUIRE(map[Key(0)] == 42);
    }
}
