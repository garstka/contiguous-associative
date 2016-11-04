#include "defs.h"

#include "min_allocator.h"

#ifdef MOVED_TO_CPP_FILE
template<>
size_t malloc_allocator_base<void>::alloc_count = 0;
template<>
size_t malloc_allocator_base<void>::dealloc_count = 0;
template<>
bool malloc_allocator_base<void>::disable_default_constructor = false;
#endif
