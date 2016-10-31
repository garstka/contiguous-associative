
#
# contiguous associative containers - demo
#

set (EXAMPLE_FILES
     "example.cpp")
      
set (MAIN_H_FILES
     "include/contiguous/contiguous_base.h"
     "include/contiguous/contiguous_internal.h"
     "include/contiguous/contiguous_multi_base.h"
     "include/contiguous/contiguous_settings.h"
     "include/contiguous/contiguous_single_base.h"
     "include/contiguous/map.h"
     "include/contiguous/multimap.h"
     "include/contiguous/multiset.h"
     "include/contiguous/set.h")

source_group("Source Files\\" FILES ${EXAMPLE_FILES})
source_group("Header Files\\" FILES ${MAIN_H_FILES})

include_directories (./include)

add_executable (example ${EXAMPLE_FILES} ${MAIN_H_FILES})

#
# install
#

install (TARGETS example RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
