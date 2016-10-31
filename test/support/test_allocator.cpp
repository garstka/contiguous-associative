#include "defs.h"

#include "test_allocator.h"

#ifdef MOVED_TO_CPP_FILE
int test_alloc_base<void>::count = 0;
int test_alloc_base<void>::time_to_throw = 0;
int test_alloc_base<void>::alloc_count = 0;
int test_alloc_base<void>::throw_after = INT_MAX;
#endif