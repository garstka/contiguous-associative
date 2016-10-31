#include "defs.h"

#include "private_constructor.hpp"

#ifdef MOVED_TO_CPP_FILE
bool operator < ( const PrivateConstructor &lhs, const PrivateConstructor &rhs ) { return lhs.get() < rhs.get(); }

bool operator < ( const PrivateConstructor &lhs, int rhs ) { return lhs.get() < rhs; }
bool operator < ( int lhs, const PrivateConstructor &rhs ) { return lhs < rhs.get(); }

std::ostream & operator << ( std::ostream &os, const PrivateConstructor &foo ) { return os << foo.get (); }
#endif