
#
# contiguous associative containers - demo
#

set (EXAMPLE_FILES
     "example.cpp")
      
set (MAIN_H_FILES
     "include/contiguous/map.h"
     "include/contiguous/multimap.h"
     "include/contiguous/multiset.h"
     "include/contiguous/set.h")

set (INTERNAL_H_FILES
     "include/contiguous/internal/contiguous_base.h"
     "include/contiguous/internal/contiguous_internal.h"
     "include/contiguous/internal/contiguous_multi_base.h"
     "include/contiguous/internal/contiguous_settings.h"
     "include/contiguous/internal/contiguous_single_base.h"
     "include/contiguous/internal/adl_swap.h"
     "include/contiguous/internal/container_traits.h"
     "include/contiguous/internal/is_transparent.h"
     "include/contiguous/internal/iterators.h"
     "include/contiguous/internal/wrapped_pair.h"
     "include/contiguous/internal/wrapped_pair_compare.h")

source_group("Source Files\\" FILES ${EXAMPLE_FILES})
source_group("Header Files\\" FILES ${MAIN_H_FILES})
source_group("Header Files\\internal\\" FILES ${INTERNAL_H_FILES})

include_directories (./include)

add_executable (example ${EXAMPLE_FILES} ${MAIN_H_FILES} ${INTERNAL_H_FILES})

#
# install
#

install (TARGETS example RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
