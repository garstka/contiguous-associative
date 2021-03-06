//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef __PRIVATE_CONSTRUCTOR__H
#define __PRIVATE_CONSTRUCTOR__H

#include <iostream>
#include "defs.h"

struct PrivateConstructor {

    PrivateConstructor static make ( int v ) { return PrivateConstructor(v); }
    int get () const { return val; }
private:
    PrivateConstructor ( int v ) : val(v) {}
    int val;
    };

#ifdef MOVED_TO_CPP_FILE
bool operator < (const PrivateConstructor &lhs, const PrivateConstructor &rhs);

bool operator < (const PrivateConstructor &lhs, int rhs);
bool operator < (int lhs, const PrivateConstructor &rhs);

std::ostream & operator << (std::ostream &os, const PrivateConstructor &foo);
#else
bool operator < ( const PrivateConstructor &lhs, const PrivateConstructor &rhs ) { return lhs.get() < rhs.get(); }

bool operator < ( const PrivateConstructor &lhs, int rhs ) { return lhs.get() < rhs; }
bool operator < ( int lhs, const PrivateConstructor &rhs ) { return lhs < rhs.get(); }

std::ostream & operator << ( std::ostream &os, const PrivateConstructor &foo ) { return os << foo.get (); }
#endif
#endif
