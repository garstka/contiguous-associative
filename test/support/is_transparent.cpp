#include "defs.h"

#include "is_transparent.h"

#ifdef MOVED_TO_CPP_FILE
bool operator <(int          rhs,   const C2Int& lhs) { return rhs       < lhs.get(); }
bool operator <(const C2Int& rhs,   const C2Int& lhs) { return rhs.get() < lhs.get(); }
bool operator <(const C2Int& rhs,            int lhs) { return rhs.get() < lhs; }
#endif