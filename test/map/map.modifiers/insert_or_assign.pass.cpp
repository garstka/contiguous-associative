//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: c++98, c++03, c++11, c++14

// <map>

// class map

// template <class M>
//  pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);            // C++17
// template <class M>
//  pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);                 // C++17
// template <class M>
//  iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);   // C++17
// template <class M>
//  iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);        // C++17

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"
#include <tuple>

#include <iostream>

class Moveable
{
    Moveable(const Moveable&);
    Moveable& operator=(const Moveable&);

    int int_;
    double double_;
public:
    Moveable() : int_(0), double_(0) {}
    Moveable(int i, double d) : int_(i), double_(d) {}

#ifdef MODIFY_MOVEONLY_TO_WORK_WITH_VECTOR
	// modified to allow move from const, vector won't support non-move-constructible (const Movable)
	Moveable(const Moveable&& x)
		: int_(x.int_), double_(x.double_)
	{
		//x.int_ = -1; x.double_ = -1;
	}
#endif

    Moveable(Moveable&& x)
        : int_(x.int_), double_(x.double_)
            {x.int_ = -1; x.double_ = -1;}
    Moveable& operator=(Moveable&& x)
        {int_ = x.int_; x.int_ = -1;
         double_ = x.double_; x.double_ = -1;
         return *this;
        }

    bool operator==(const Moveable& x) const
        {return int_ == x.int_ && double_ == x.double_;}
    bool operator<(const Moveable& x) const
        {return int_ < x.int_ || (int_ == x.int_ && double_ < x.double_);}

    int get() const {return int_;}
    bool moved() const {return int_ == -1;}
};


TEST_CASE("map modifiers insert or assign pass")
{
    { // pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);
        typedef contiguous::map<int, Moveable> M;
        typedef std::pair<M::iterator, bool> R;
        M m;
        R r;
        for ( int i = 0; i < 20; i += 2 )
            m.emplace ( i, Moveable(i, (double) i));
        REQUIRE(m.size() == 10);

        for (int i=0; i < 20; i += 2)
        {
            Moveable mv(i+1, i+1);
            r = m.insert_or_assign(i, std::move(mv));
            REQUIRE(m.size() == 10);
            REQUIRE(!r.second);                    // was not inserted
            REQUIRE(mv.moved());                   // was moved from
            REQUIRE(r.first->first == i);          // key
            REQUIRE(r.first->second.get() == i+1); // value
        }

        Moveable mv1(5, 5.0);
        r = m.insert_or_assign(-1, std::move(mv1));
        REQUIRE(m.size() == 11);
        REQUIRE(r.second);                    // was inserted
        REQUIRE(mv1.moved());                 // was moved from
        REQUIRE(r.first->first        == -1); // key
        REQUIRE(r.first->second.get() == 5);  // value

        Moveable mv2(9, 9.0);
        r = m.insert_or_assign(3, std::move(mv2));
        REQUIRE(m.size() == 12);
        REQUIRE(r.second);                   // was inserted
        REQUIRE(mv2.moved());                // was moved from
        REQUIRE(r.first->first        == 3); // key
        REQUIRE(r.first->second.get() == 9); // value

        Moveable mv3(-1, 5.0);
        r = m.insert_or_assign(117, std::move(mv3));
        REQUIRE(m.size() == 13);
        REQUIRE(r.second);                     // was inserted
        REQUIRE(mv3.moved());                  // was moved from
        REQUIRE(r.first->first        == 117); // key
        REQUIRE(r.first->second.get() == -1);  // value
    }
    { // pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);
        typedef contiguous::map<Moveable, Moveable> M;
        typedef std::pair<M::iterator, bool> R;
        M m;
        R r;
        for ( int i = 0; i < 20; i += 2 )
            m.emplace ( Moveable(i, (double) i), Moveable(i+1, (double) i+1));
        REQUIRE(m.size() == 10);

        Moveable mvkey1(2, 2.0);
        Moveable mv1(4, 4.0);
        r = m.insert_or_assign(std::move(mvkey1), std::move(mv1));
        REQUIRE(m.size() == 10);
        REQUIRE(!r.second);                  // was not inserted
        REQUIRE(!mvkey1.moved());            // was not moved from
        REQUIRE(mv1.moved());                // was moved from
        REQUIRE(r.first->first == mvkey1);   // key
        REQUIRE(r.first->second.get() == 4); // value

        Moveable mvkey2(3, 3.0);
        Moveable mv2(5, 5.0);
        r = m.try_emplace(std::move(mvkey2), std::move(mv2));
        REQUIRE(m.size() == 11);
        REQUIRE(r.second);                   // was inserted
        REQUIRE(mv2.moved());                // was moved from
        REQUIRE(mvkey2.moved());             // was moved from
        REQUIRE(r.first->first.get()  == 3); // key
        REQUIRE(r.first->second.get() == 5); // value
    }
    { // iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);
        typedef contiguous::map<int, Moveable> M;
        M m;
        M::iterator r;
        for ( int i = 0; i < 20; i += 2 )
            m.emplace ( i, Moveable(i, (double) i));
        REQUIRE(m.size() == 10);
        M::const_iterator it = m.find(2);

        Moveable mv1(3, 3.0);
        r = m.insert_or_assign(it, 2, std::move(mv1));
        REQUIRE(m.size() == 10);
        REQUIRE(mv1.moved());           // was moved from
        REQUIRE(r->first        == 2);  // key
        REQUIRE(r->second.get() == 3);  // value

        Moveable mv2(5, 5.0);
        r = m.insert_or_assign(it, 3, std::move(mv2));
        REQUIRE(m.size() == 11);
        REQUIRE(mv2.moved());           // was moved from
        REQUIRE(r->first        == 3);  // key
        REQUIRE(r->second.get() == 5);  // value
    }
    { // iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);
        typedef contiguous::map<Moveable, Moveable> M;
        M m;
        M::iterator r;
        for ( int i = 0; i < 20; i += 2 )
            m.emplace ( Moveable(i, (double) i), Moveable(i+1, (double) i+1));
        REQUIRE(m.size() == 10);
        M::const_iterator it = std::next(m.cbegin());

        Moveable mvkey1(2, 2.0);
        Moveable mv1(4, 4.0);
        r = m.insert_or_assign(it, std::move(mvkey1), std::move(mv1));
        REQUIRE(m.size() == 10);
        REQUIRE(mv1.moved());          // was moved from
        REQUIRE(!mvkey1.moved());      // was not moved from
        REQUIRE(r->first == mvkey1);   // key
        REQUIRE(r->second.get() == 4); // value

        Moveable mvkey2(3, 3.0);
        Moveable mv2(5, 5.0);
        r = m.insert_or_assign(it, std::move(mvkey2), std::move(mv2));
        REQUIRE(m.size() == 11);
        REQUIRE(mv2.moved());           // was moved from
        REQUIRE(mvkey2.moved());        // was moved from
        REQUIRE(r->first.get()  == 3);  // key
        REQUIRE(r->second.get() == 5);  // value
    }
}
