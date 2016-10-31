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

// multimap(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);

#include "defs.h"

#include "contiguous/multimap.h"
#include "catch.hpp"
#include "test_compare.h"
#include "test_allocator.h"
#include "min_allocator.h"

TEST_CASE("multimap cons initializer list compare alloc pass")
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef test_compare<std::less<int> > Cmp;
    typedef test_allocator<std::pair<const int, double> > A;
    typedef contiguous::multimap<int, double, Cmp, A> C;
    typedef C::value_type V;
    C m(
           {
               {1, 1},
               {1, 1.5},
               {1, 2},
               {2, 1},
               {2, 1.5},
               {2, 2},
               {3, 1},
               {3, 1.5},
               {3, 2}
           },
           Cmp(4), A(5)
        );
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1, 1));
    REQUIRE(*++i == V(1, 1.5));
    REQUIRE(*++i == V(1, 2));
    REQUIRE(*++i == V(2, 1));
    REQUIRE(*++i == V(2, 1.5));
    REQUIRE(*++i == V(2, 2));
    REQUIRE(*++i == V(3, 1));
    REQUIRE(*++i == V(3, 1.5));
    REQUIRE(*++i == V(3, 2));
    REQUIRE(m.key_comp() == Cmp(4));
    REQUIRE(m.get_allocator() == A(5));
    }
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
#if TEST_STD_VER >= 11
    {
    typedef test_compare<std::less<int> > Cmp;
    typedef min_allocator<std::pair<const int, double> > A;
    typedef contiguous::multimap<int, double, Cmp, A> C;
    typedef C::value_type V;
    C m(
           {
               {1, 1},
               {1, 1.5},
               {1, 2},
               {2, 1},
               {2, 1.5},
               {2, 2},
               {3, 1},
               {3, 1.5},
               {3, 2}
           },
           Cmp(4), A()
        );
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1, 1));
    REQUIRE(*++i == V(1, 1.5));
    REQUIRE(*++i == V(1, 2));
    REQUIRE(*++i == V(2, 1));
    REQUIRE(*++i == V(2, 1.5));
    REQUIRE(*++i == V(2, 2));
    REQUIRE(*++i == V(3, 1));
    REQUIRE(*++i == V(3, 1.5));
    REQUIRE(*++i == V(3, 2));
    REQUIRE(m.key_comp() == Cmp(4));
    REQUIRE(m.get_allocator() == A());
    }
#if TEST_STD_VER > 11
    {
    typedef test_compare<std::less<int> > C;
    typedef std::pair<const int, double> V;
    typedef min_allocator<V> A;
    typedef contiguous::multimap<int, double, C, A> M;
    A a;
    M m ({ {1, 1},
           {1, 1.5},
           {1, 2},
           {2, 1},
           {2, 1.5},
           {2, 2},
           {3, 1},
           {3, 1.5},
           {3, 2}
          }, a);

    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    M::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1, 1));
    REQUIRE(*++i == V(1, 1.5));
    REQUIRE(*++i == V(1, 2));
    REQUIRE(*++i == V(2, 1));
    REQUIRE(*++i == V(2, 1.5));
    REQUIRE(*++i == V(2, 2));
    REQUIRE(*++i == V(3, 1));
    REQUIRE(*++i == V(3, 1.5));
    REQUIRE(*++i == V(3, 2));
    REQUIRE(m.get_allocator() == a);
    }
#endif
    {
    typedef test_compare<std::less<int> > Cmp;
    typedef explicit_allocator<std::pair<const int, double> > A;
    typedef contiguous::multimap<int, double, Cmp, A> C;
    typedef C::value_type V;
    C m(
           {
               {1, 1},
               {1, 1.5},
               {1, 2},
               {2, 1},
               {2, 1.5},
               {2, 2},
               {3, 1},
               {3, 1.5},
               {3, 2}
           },
           Cmp(4), A{}
        );
    REQUIRE(m.size() == 9);
    REQUIRE(distance(m.begin(), m.end()) == 9);
    C::const_iterator i = m.cbegin();
    REQUIRE(*i == V(1, 1));
    REQUIRE(*++i == V(1, 1.5));
    REQUIRE(*++i == V(1, 2));
    REQUIRE(*++i == V(2, 1));
    REQUIRE(*++i == V(2, 1.5));
    REQUIRE(*++i == V(2, 2));
    REQUIRE(*++i == V(3, 1));
    REQUIRE(*++i == V(3, 1.5));
    REQUIRE(*++i == V(3, 2));
    REQUIRE(m.key_comp() == Cmp(4));
    REQUIRE(m.get_allocator() == A{});
    }
#endif
}
