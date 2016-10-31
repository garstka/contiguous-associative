#include "defs.h"

#include "count_new.hpp"

#ifdef MOVED_TO_CPP_FILE
#ifdef DISABLE_NEW_COUNT
  const bool MemCounter::disable_checking = true;
#else
  const bool MemCounter::disable_checking = false;
#endif
  
MemCounter globalMemCounter((MemCounter::MemCounterCtorArg_()));

#ifndef DISABLE_NEW_COUNT
void* operator new(std::size_t s) throw(std::bad_alloc)
{
    globalMemCounter.newCalled(s);
    void* ret = std::malloc(s);
    if (ret == nullptr)
        detail::throw_bad_alloc_helper();
    return ret;
}

void  operator delete(void* p) throw()
{
    globalMemCounter.deleteCalled(p);
    std::free(p);
}


void* operator new[](std::size_t s) throw(std::bad_alloc)
{
    globalMemCounter.newArrayCalled(s);
    return operator new(s);
}


void operator delete[](void* p) throw()
{
    globalMemCounter.deleteArrayCalled(p);
    operator delete(p);
}

#endif // DISABLE_NEW_COUNT
#endif
