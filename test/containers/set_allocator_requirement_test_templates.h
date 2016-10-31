//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef SET_ALLOCATOR_REQUIREMENT_TEST_TEMPLATES_H
#define SET_ALLOCATOR_REQUIREMENT_TEST_TEMPLATES_H

// <set>
// <unordered_set>

// class set
// class unordered_set

// insert(...);
// emplace(...);
// emplace_hint(...);


#include <cassert>

#include "test_macros.h"
#include "count_new.hpp"
#include "container_test_types.h"
#ifndef IGNORE_LIBCXX_SPECIFIC
#include "assert_checkpoint.h"
#endif


template <class Container>
void testSetInsert()
{
  typedef typename Container::value_type ValueTp;
  typedef Container C;
  typedef std::pair<typename C::iterator, bool> R;
  ConstructController* cc = getConstructController();
  cc->reset();
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(const value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    const ValueTp v(42);
    cc->expect<const ValueTp&>();
    assert(c.insert(v).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      const ValueTp v2(42);
      assert(c.insert(v2).second == false);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<const ValueTp&>();
    assert(c.insert(v).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      ValueTp v2(42);
      assert(c.insert(v2).second == false);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(value_type&&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<ValueTp&&>();
    assert(c.insert(std::move(v)).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      ValueTp v2(42);
      assert(c.insert(std::move(v2)).second == false);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(const value_type&&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    const ValueTp v(42);
    cc->expect<const ValueTp&>();
    assert(c.insert(std::move(v)).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      const ValueTp v2(42);
      assert(c.insert(std::move(v2)).second == false);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(std::initializer_list<ValueTp>)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    std::initializer_list<ValueTp> il = { ValueTp(1), ValueTp(2) };
    cc->expect<ValueTp const&>(2);
    c.insert(il);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      c.insert(il);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(Iter, Iter) for *Iter = value_type const&");
#endif
#ifndef SET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE
    Container c;
    const ValueTp ValueList[] = { ValueTp(1), ValueTp(2), ValueTp(3) };
    cc->expect<ValueTp const&>(3);
    c.insert(std::begin(ValueList), std::end(ValueList));
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      c.insert(std::begin(ValueList), std::end(ValueList));
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(Iter, Iter) for *Iter = value_type&&");
#endif
#ifndef SET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE
    Container c;
    ValueTp ValueList[] = { ValueTp(1), ValueTp(2) , ValueTp(3) };
    cc->expect<ValueTp&&>(3);
    c.insert(std::move_iterator<ValueTp*>(std::begin(ValueList)),
             std::move_iterator<ValueTp*>(std::end(ValueList)));
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      ValueTp ValueList2[] = { ValueTp(1), ValueTp(2) , ValueTp(3) };
      c.insert(std::move_iterator<ValueTp*>(std::begin(ValueList2)),
               std::move_iterator<ValueTp*>(std::end(ValueList2)));
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(Iter, Iter) for *Iter = value_type&");
#endif
#ifndef SET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE
    Container c;
    ValueTp ValueList[] = { ValueTp(1), ValueTp(2) , ValueTp(3) };
    cc->expect<ValueTp const&>(3);
    c.insert(std::begin(ValueList), std::end(ValueList));
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      c.insert(std::begin(ValueList), std::end(ValueList));
    }
#endif
  }
}


template <class Container>
void testSetEmplace()
{
  typedef typename Container::value_type ValueTp;
  typedef Container C;
  typedef std::pair<typename C::iterator, bool> R;
  ConstructController* cc = getConstructController();
  cc->reset();
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace(const value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    const ValueTp v(42);
    cc->expect<const ValueTp&>();
    assert(c.emplace(v).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      const ValueTp v2(42);
      assert(c.emplace(v2).second == false);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace(value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<ValueTp&>();
    assert(c.emplace(v).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      ValueTp v2(42);
      assert(c.emplace(v2).second == false);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace(value_type&&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<ValueTp&&>();
    assert(c.emplace(std::move(v)).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      ValueTp v2(42);
      assert(c.emplace(std::move(v2)).second == false);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace(const value_type&&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    const ValueTp v(42);
    cc->expect<const ValueTp&&>();
    assert(c.emplace(std::move(v)).second);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      const ValueTp v2(42);
      assert(c.emplace(std::move(v2)).second == false);
    }
#endif
  }
}


template <class Container>
void testSetEmplaceHint()
{
  typedef typename Container::value_type ValueTp;

  typedef Container C;
  typedef typename C::iterator It;
  ConstructController* cc = getConstructController();
  cc->reset();
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace_hint(p, const value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    const ValueTp v(42);
    cc->expect<const ValueTp&>();
    It ret = c.emplace_hint(c.end(), v);
    assert(ret != c.end());
    assert(c.size() == 1);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      const ValueTp v2(42);
      It ret2 = c.emplace_hint(c.begin(), v2);
#ifndef CONTAINERS_ARE_UNSTABLE
      assert(&(*ret2) == &(*ret));
#endif
      assert(c.size() == 1);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace_hint(p, value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<ValueTp&>();
    It ret = c.emplace_hint(c.end(), v);
    assert(ret != c.end());
    assert(c.size() == 1);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      ValueTp v2(42);
      It ret2 = c.emplace_hint(c.begin(), v2);
#ifndef CONTAINERS_ARE_UNSTABLE
      assert(&(*ret2) == &(*ret));
#endif
      assert(c.size() == 1);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace_hint(p, value_type&&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<ValueTp&&>();
    It ret = c.emplace_hint(c.end(), std::move(v));
    assert(ret != c.end());
    assert(c.size() == 1);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      ValueTp v2(42);
      It ret2 = c.emplace_hint(c.begin(), std::move(v2));
#ifndef CONTAINERS_ARE_UNSTABLE
      assert(&(*ret2) == &(*ret));
#endif
      assert(c.size() == 1);
    }
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::emplace_hint(p, const value_type&&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    const ValueTp v(42);
    cc->expect<const ValueTp&&>();
    It ret = c.emplace_hint(c.end(), std::move(v));
    assert(ret != c.end());
    assert(c.size() == 1);
    assert(!cc->unchecked());
    {
      DisableAllocationGuard g;
      const ValueTp v2(42);
      It ret2 = c.emplace_hint(c.begin(), std::move(v2));
#ifndef CONTAINERS_ARE_UNSTABLE
      assert(&(*ret2) == &(*ret));
#endif
      assert(c.size() == 1);
    }
#endif
  }
}


template <class Container>
void testMultisetInsert()
{
  typedef typename Container::value_type ValueTp;
  typedef Container C;
  ConstructController* cc = getConstructController();
  cc->reset();
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(const value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    const ValueTp v(42);
    cc->expect<const ValueTp&>();
    c.insert(v);
    assert(!cc->unchecked());
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(value_type&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<const ValueTp&>();
    c.insert(v);
    assert(!cc->unchecked());
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(value_type&&)");
#endif
#ifndef VECTOR_REQUIRES_ASSIGNABLE
    Container c;
    ValueTp v(42);
    cc->expect<ValueTp&&>();
    c.insert(std::move(v));
    assert(!cc->unchecked());
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(std::initializer_list<ValueTp>)");
#endif
#ifndef MULTISET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE
    Container c;
    std::initializer_list<ValueTp> il = { ValueTp(1), ValueTp(2) };
    cc->expect<ValueTp const&>(2);
	
    c.insert(il);
    assert(!cc->unchecked());
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(Iter, Iter) for *Iter = value_type const&");
#endif
#ifndef MULTISET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE
    Container c;
    const ValueTp ValueList[] = { ValueTp(1), ValueTp(2), ValueTp(3) };
    cc->expect<ValueTp const&>(3);
    c.insert(std::begin(ValueList), std::end(ValueList));
    assert(!cc->unchecked());
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(Iter, Iter) for *Iter = value_type&&");
#endif
#ifndef MULTISET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE
    Container c;
    ValueTp ValueList[] = { ValueTp(1), ValueTp(2) , ValueTp(3) };
    cc->expect<ValueTp&&>(3);
    c.insert(std::move_iterator<ValueTp*>(std::begin(ValueList)),
             std::move_iterator<ValueTp*>(std::end(ValueList)));
    assert(!cc->unchecked());
#endif
  }
  {
#ifndef IGNORE_LIBCXX_SPECIFIC
    CHECKPOINT("Testing C::insert(Iter, Iter) for *Iter = value_type&");
#endif
#ifndef MULTISET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE
    Container c;
    ValueTp ValueList[] = { ValueTp(1), ValueTp(2) , ValueTp(3) };
    cc->expect<ValueTp&>(3);
    c.insert(std::begin(ValueList), std::end(ValueList));
    assert(!cc->unchecked());
#endif
  }
}

#endif
