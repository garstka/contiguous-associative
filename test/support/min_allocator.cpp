#include "defs.h"

#include "min_allocator.h"

#ifdef MOVED_TO_CPP_FILE
size_t malloc_allocator_base<void>::alloc_count = 0;
size_t malloc_allocator_base<void>::dealloc_count = 0;
bool malloc_allocator_base<void>::disable_default_constructor = false;
#endif