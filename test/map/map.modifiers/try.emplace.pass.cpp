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

// template <class... Args>
//  pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);          // C++17
// template <class... Args>
//  pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);               // C++17
// template <class... Args>
//  iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args); // C++17
// template <class... Args>
//  iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);      // C++17

#include "defs.h"

#include "contiguous/map.h"
#include "catch.hpp"
#include <tuple>

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


TEST_CASE("map modifiers try emplace pass")
{
    { // pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);
        typedef contiguous::map<int, Moveable> M;
        typedef std::pair<M::iterator, bool> R;
        M m;
        R r;
        for (int i = 0; i < 20; i += 2)
            m.emplace (i, Moveable(i, (double) i));
        REQUIRE(m.size() == 10);

        Moveable mv1(3, 3.0);
        for (int i=0; i < 20; i += 2)
        {
            r = m.try_emplace(i, std::move(mv1));
            REQUIRE(m.size() == 10);
            REQUIRE(!r.second);              // was not inserted
            REQUIRE(!mv1.moved());           // was not moved from
            REQUIRE(r.first->first == i);    // key
        }

        r = m.try_emplace(-1, std::move(mv1));
        REQUIRE(m.size() == 11);
        REQUIRE(r.second);                   // was inserted
        REQUIRE(mv1.moved());                // was moved from
        REQUIRE(r.first->first == -1);       // key
        REQUIRE(r.first->second.get() == 3); // value

        Moveable mv2(5, 3.0);
        r = m.try_emplace(5, std::move(mv2));
        REQUIRE(m.size() == 12);
        REQUIRE(r.second);                   // was inserted
        REQUIRE(mv2.moved());                // was moved from
        REQUIRE(r.first->first == 5);        // key
        REQUIRE(r.first->second.get() == 5); // value

        Moveable mv3(-1, 3.0);
        r = m.try_emplace(117, std::move(mv2));
        REQUIRE(m.size() == 13);
        REQUIRE(r.second);                    // was inserted
        REQUIRE(mv2.moved());                 // was moved from
        REQUIRE(r.first->first == 117);       // key
        REQUIRE(r.first->second.get() == -1); // value
    }

    {  // pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);
        typedef contiguous::map<Moveable, Moveable> M;
        typedef std::pair<M::iterator, bool> R;
        M m;
        R r;
        for ( int i = 0; i < 20; i += 2 )
            m.emplace ( Moveable(i, (double) i), Moveable(i+1, (double) i+1));
        REQUIRE(m.size() == 10);

        Moveable mvkey1(2, 2.0);
        Moveable mv1(4, 4.0);
        r = m.try_emplace(std::move(mvkey1), std::move(mv1));
        REQUIRE(m.size() == 10);
        REQUIRE(!r.second);                 // was not inserted
        REQUIRE(!mv1.moved());              // was not moved from
        REQUIRE(!mvkey1.moved());           // was not moved from
        REQUIRE(r.first->first == mvkey1);  // key

        Moveable mvkey2(3, 3.0);
        r = m.try_emplace(std::move(mvkey2), std::move(mv1));
        REQUIRE(m.size() == 11);
        REQUIRE(r.second);                   // was inserted
        REQUIRE(mv1.moved());                // was moved from
        REQUIRE(mvkey2.moved());             // was moved from
        REQUIRE(r.first->first.get()  == 3); // key
        REQUIRE(r.first->second.get() == 4); // value
    }

    {  // iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args);
        typedef contiguous::map<int, Moveable> M;
        M m;
        M::iterator r;
        for ( int i = 0; i < 20; i += 2 )
            m.try_emplace ( i, Moveable(i, (double) i));
        REQUIRE(m.size() == 10);
        M::const_iterator it = m.find(2);

        Moveable mv1(3, 3.0);
        for (int i=0; i < 20; i += 2)
        {
            r = m.try_emplace(it, i, std::move(mv1));
            REQUIRE(m.size() == 10);
            REQUIRE(!mv1.moved());         // was not moved from
            REQUIRE(r->first == i);        // key
            REQUIRE(r->second.get() == i); // value
        }

        r = m.try_emplace(it, 3, std::move(mv1));
        REQUIRE(m.size() == 11);
        REQUIRE(mv1.moved());          // was moved from
        REQUIRE(r->first == 3);        // key
        REQUIRE(r->second.get() == 3); // value
    }

    {  // iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);
        typedef contiguous::map<Moveable, Moveable> M;
        M m;
        M::iterator r;
        for ( int i = 0; i < 20; i += 2 )
            m.emplace ( Moveable(i, (double) i), Moveable(i+1, (double) i+1));
        REQUIRE(m.size() == 10);
        M::const_iterator it = std::next(m.cbegin());

        Moveable mvkey1(2, 2.0);
        Moveable mv1(4, 4.0);
        r = m.try_emplace(it, std::move(mvkey1), std::move(mv1));
        REQUIRE(m.size() == 10);
        REQUIRE(!mv1.moved());        // was not moved from
        REQUIRE(!mvkey1.moved());     // was not moved from
        REQUIRE(r->first == mvkey1);  // key

        Moveable mvkey2(3, 3.0);
        r = m.try_emplace(it, std::move(mvkey2), std::move(mv1));
        REQUIRE(m.size() == 11);
        REQUIRE(mv1.moved());          // was moved from
        REQUIRE(mvkey2.moved());       // was moved from
        REQUIRE(r->first.get()  == 3); // key
        REQUIRE(r->second.get() == 4); // value
    }
}
