
#
# contiguous associative containers - tests
#

set (TEST_FILES_MAP
     "map/allocator_mismatch.fail.cpp"
     "map/compare.pass.cpp"
     "map/incomplete_type.pass.cpp"
     "map/types.pass.cpp")

set (TEST_FILES_MAP_ACCESS
     "map/map.access/at.pass.cpp"
     "map/map.access/empty.pass.cpp"
     "map/map.access/index_key.pass.cpp"
     "map/map.access/index_rv_key.pass.cpp"
     "map/map.access/index_tuple.pass.cpp"
     "map/map.access/iterator.pass.cpp"
     "map/map.access/max_size.pass.cpp"
     "map/map.access/size.pass.cpp")

set (TEST_FILES_MAP_CONS
     "map/map.cons/alloc.pass.cpp"
     "map/map.cons/assign_initializer_list.pass.cpp"
     "map/map.cons/compare.pass.cpp"
     "map/map.cons/compare_alloc.pass.cpp"
     "map/map.cons/compare_copy_constructible.fail.cpp"
     "map/map.cons/copy.pass.cpp"
     "map/map.cons/copy_alloc.pass.cpp"
     "map/map.cons/copy_assign.pass.cpp"
     "map/map.cons/default.pass.cpp"
     "map/map.cons/default_noexcept.pass.cpp"
     "map/map.cons/default_recursive.pass.cpp"
     "map/map.cons/dtor_noexcept.pass.cpp"
     "map/map.cons/initializer_list.pass.cpp"
     "map/map.cons/initializer_list_compare.pass.cpp"
     "map/map.cons/initializer_list_compare_alloc.pass.cpp"
     "map/map.cons/iter_iter.pass.cpp"
     "map/map.cons/iter_iter_comp.pass.cpp"
     "map/map.cons/iter_iter_comp_alloc.pass.cpp"
     "map/map.cons/move.pass.cpp"
     "map/map.cons/move_alloc.pass.cpp"
     "map/map.cons/move_assign.pass.cpp"
     "map/map.cons/move_assign_noexcept.pass.cpp"
     "map/map.cons/move_noexcept.pass.cpp")

set (TEST_FILES_MAP_MODIFIERS
     "map/map.modifiers/clear.pass.cpp"
     "map/map.modifiers/emplace.pass.cpp"
     "map/map.modifiers/emplace_hint.pass.cpp"
     "map/map.modifiers/erase_iter.pass.cpp"
     "map/map.modifiers/erase_iter_iter.pass.cpp"
     "map/map.modifiers/erase_key.pass.cpp"
     "map/map.modifiers/insert_and_emplace_allocator_requirements.pass.cpp"
     "map/map.modifiers/insert_cv.pass.cpp"
     "map/map.modifiers/insert_initializer_list.pass.cpp"
     "map/map.modifiers/insert_iter_cv.pass.cpp"
     "map/map.modifiers/insert_iter_iter.pass.cpp"
     "map/map.modifiers/insert_iter_rv.pass.cpp"
     "map/map.modifiers/insert_or_assign.pass.cpp"
     "map/map.modifiers/insert_rv.pass.cpp"
     "map/map.modifiers/try.emplace.pass.cpp")

set (TEST_FILES_MAP_OPS
     "map/map.ops/count.pass.cpp"
     "map/map.ops/count0.pass.cpp"
     "map/map.ops/count1.fail.cpp"
     "map/map.ops/count2.fail.cpp"
     "map/map.ops/count3.fail.cpp"
     "map/map.ops/equal_range.pass.cpp"
     "map/map.ops/equal_range0.pass.cpp"
     "map/map.ops/equal_range1.fail.cpp"
     "map/map.ops/equal_range2.fail.cpp"
     "map/map.ops/equal_range3.fail.cpp"
     "map/map.ops/find.pass.cpp"
     "map/map.ops/find0.pass.cpp"
     "map/map.ops/find1.fail.cpp"
     "map/map.ops/find2.fail.cpp"
     "map/map.ops/find3.fail.cpp"
     "map/map.ops/lower_bound.pass.cpp"
     "map/map.ops/lower_bound0.pass.cpp"
     "map/map.ops/lower_bound1.fail.cpp"
     "map/map.ops/lower_bound2.fail.cpp"
     "map/map.ops/lower_bound3.fail.cpp"
     "map/map.ops/upper_bound.pass.cpp"
     "map/map.ops/upper_bound0.pass.cpp"
     "map/map.ops/upper_bound1.fail.cpp"
     "map/map.ops/upper_bound2.fail.cpp"
     "map/map.ops/upper_bound3.fail.cpp")

set (TEST_FILES_MAP_SPECIAL
     "map/map.special/member_swap.pass.cpp"
     "map/map.special/non_member_swap.pass.cpp"
     "map/map.special/swap_noexcept.pass.cpp")


set (TEST_FILES_MULTIMAP
     "multimap/allocator_mismatch.fail.cpp"
     "multimap/empty.pass.cpp"
     "multimap/incomplete_type.pass.cpp"
     "multimap/iterator.pass.cpp"
     "multimap/max_size.pass.cpp"
     "multimap/scary.pass.cpp"
     "multimap/size.pass.cpp"
     "multimap/types.pass.cpp")

set (TEST_FILES_MULTIMAP_CONS
     "multimap/multimap.cons/alloc.pass.cpp"
     "multimap/multimap.cons/assign_initializer_list.pass.cpp"
     "multimap/multimap.cons/compare.pass.cpp"
     "multimap/multimap.cons/compare_alloc.pass.cpp"
     "multimap/multimap.cons/compare_copy_constructible.fail.cpp"
     "multimap/multimap.cons/copy.pass.cpp"
     "multimap/multimap.cons/copy_alloc.pass.cpp"
     "multimap/multimap.cons/copy_assign.pass.cpp"
     "multimap/multimap.cons/default.pass.cpp"
     "multimap/multimap.cons/default_noexcept.pass.cpp"
     "multimap/multimap.cons/default_recursive.pass.cpp"
     "multimap/multimap.cons/dtor_noexcept.pass.cpp"
     "multimap/multimap.cons/initializer_list.pass.cpp"
     "multimap/multimap.cons/initializer_list_compare.pass.cpp"
     "multimap/multimap.cons/initializer_list_compare_alloc.pass.cpp"
     "multimap/multimap.cons/iter_iter.pass.cpp"
     "multimap/multimap.cons/iter_iter_comp.pass.cpp"
     "multimap/multimap.cons/iter_iter_comp_alloc.pass.cpp"
     "multimap/multimap.cons/move.pass.cpp"
     "multimap/multimap.cons/move_alloc.pass.cpp"
     "multimap/multimap.cons/move_assign.pass.cpp"
     "multimap/multimap.cons/move_assign_noexcept.pass.cpp"
     "multimap/multimap.cons/move_noexcept.pass.cpp")

set (TEST_FILES_MULTIMAP_MODIFIERS
     "multimap/multimap.modifiers/clear.pass.cpp"
     "multimap/multimap.modifiers/emplace.pass.cpp"
     "multimap/multimap.modifiers/emplace_hint.pass.cpp"
     "multimap/multimap.modifiers/erase_iter.pass.cpp"
     "multimap/multimap.modifiers/erase_iter_iter.pass.cpp"
     "multimap/multimap.modifiers/erase_key.pass.cpp"
     "multimap/multimap.modifiers/insert_allocator_requirements.pass.cpp"
     "multimap/multimap.modifiers/insert_cv.pass.cpp"
     "multimap/multimap.modifiers/insert_initializer_list.pass.cpp"
     "multimap/multimap.modifiers/insert_iter_cv.pass.cpp"
     "multimap/multimap.modifiers/insert_iter_iter.pass.cpp"
     "multimap/multimap.modifiers/insert_iter_rv.pass.cpp"
     "multimap/multimap.modifiers/insert_rv.pass.cpp")

set (TEST_FILES_MULTIMAP_OPS
     "multimap/multimap.ops/count.pass.cpp"
     "multimap/multimap.ops/count0.pass.cpp"
     "multimap/multimap.ops/count1.fail.cpp"
     "multimap/multimap.ops/count2.fail.cpp"
     "multimap/multimap.ops/count3.fail.cpp"
     "multimap/multimap.ops/equal_range.pass.cpp"
     "multimap/multimap.ops/equal_range0.pass.cpp"
     "multimap/multimap.ops/equal_range1.fail.cpp"
     "multimap/multimap.ops/equal_range2.fail.cpp"
     "multimap/multimap.ops/equal_range3.fail.cpp"
     "multimap/multimap.ops/find.pass.cpp"
     "multimap/multimap.ops/find0.pass.cpp"
     "multimap/multimap.ops/find1.fail.cpp"
     "multimap/multimap.ops/find2.fail.cpp"
     "multimap/multimap.ops/find3.fail.cpp"
     "multimap/multimap.ops/lower_bound.pass.cpp"
     "multimap/multimap.ops/lower_bound0.pass.cpp"
     "multimap/multimap.ops/lower_bound1.fail.cpp"
     "multimap/multimap.ops/lower_bound2.fail.cpp"
     "multimap/multimap.ops/lower_bound3.fail.cpp"
     "multimap/multimap.ops/upper_bound.pass.cpp"
     "multimap/multimap.ops/upper_bound0.pass.cpp"
     "multimap/multimap.ops/upper_bound1.fail.cpp"
     "multimap/multimap.ops/upper_bound2.fail.cpp"
     "multimap/multimap.ops/upper_bound3.fail.cpp")

set (TEST_FILES_MULTIMAP_SPECIAL
     "multimap/multimap.special/member_swap.pass.cpp"
     "multimap/multimap.special/non_member_swap.pass.cpp"
     "multimap/multimap.special/swap_noexcept.pass.cpp")

set (TEST_FILES_MULTISET
     "multiset/allocator_mismatch.fail.cpp"
     "multiset/clear.pass.cpp"
     "multiset/count.pass.cpp"
     "multiset/emplace.pass.cpp"
     "multiset/emplace_hint.pass.cpp"
     "multiset/empty.pass.cpp"
     "multiset/equal_range.pass.cpp"
     "multiset/erase_iter.pass.cpp"
     "multiset/erase_iter_iter.pass.cpp"
     "multiset/erase_key.pass.cpp"
     "multiset/find.pass.cpp"
     "multiset/incomplete_type.pass.cpp"
     "multiset/insert_allocator_requirements.pass.cpp"
     "multiset/insert_cv.pass.cpp"
     "multiset/insert_initializer_list.pass.cpp"
     "multiset/insert_iter_cv.pass.cpp"
     "multiset/insert_iter_iter.pass.cpp"
     "multiset/insert_iter_rv.pass.cpp"
     "multiset/insert_rv.pass.cpp"
     "multiset/iterator.pass.cpp"
     "multiset/lower_bound.pass.cpp"
     "multiset/max_size.pass.cpp"
     "multiset/scary.pass.cpp"
     "multiset/size.pass.cpp"
     "multiset/types.pass.cpp"
     "multiset/upper_bound.pass.cpp")

set (TEST_FILES_MULTISET_CONS
     "multiset/multiset.cons/alloc.pass.cpp"
     "multiset/multiset.cons/assign_initializer_list.pass.cpp"
     "multiset/multiset.cons/compare.pass.cpp"
     "multiset/multiset.cons/compare_alloc.pass.cpp"
     "multiset/multiset.cons/compare_copy_constructible.fail.cpp"
     "multiset/multiset.cons/copy.pass.cpp"
     "multiset/multiset.cons/copy_alloc.pass.cpp"
     "multiset/multiset.cons/copy_assign.pass.cpp"
     "multiset/multiset.cons/default.pass.cpp"
     "multiset/multiset.cons/default_noexcept.pass.cpp"
     "multiset/multiset.cons/dtor_noexcept.pass.cpp"
     "multiset/multiset.cons/initializer_list.pass.cpp"
     "multiset/multiset.cons/initializer_list_compare.pass.cpp"
     "multiset/multiset.cons/initializer_list_compare_alloc.pass.cpp"
     "multiset/multiset.cons/iter_iter.pass.cpp"
     "multiset/multiset.cons/iter_iter_alloc.pass.cpp"
     "multiset/multiset.cons/iter_iter_comp.pass.cpp"
     "multiset/multiset.cons/move.pass.cpp"
     "multiset/multiset.cons/move_alloc.pass.cpp"
     "multiset/multiset.cons/move_assign.pass.cpp"
     "multiset/multiset.cons/move_assign_noexcept.pass.cpp"
     "multiset/multiset.cons/move_noexcept.pass.cpp")

set (TEST_FILES_MULTISET_SPECIAL
     "multiset/multiset.special/member_swap.pass.cpp"
     "multiset/multiset.special/non_member_swap.pass.cpp"
     "multiset/multiset.special/swap_noexcept.pass.cpp")

set (TEST_FILES_SET
     "set/allocator_mismatch.fail.cpp"
     "set/clear.pass.cpp"
     "set/count.pass.cpp"
     "set/emplace.pass.cpp"
     "set/emplace_hint.pass.cpp"
     "set/empty.pass.cpp"
     "set/equal_range.pass.cpp"
     "set/erase_iter.pass.cpp"
     "set/erase_iter_iter.pass.cpp"
     "set/erase_key.pass.cpp"
     "set/find.pass.cpp"
     "set/incomplete_type.pass.cpp"
     "set/insert_and_emplace_allocator_requirements.pass.cpp"
     "set/insert_cv.pass.cpp"
     "set/insert_initializer_list.pass.cpp"
     "set/insert_iter_cv.pass.cpp"
     "set/insert_iter_iter.pass.cpp"
     "set/insert_iter_rv.pass.cpp"
     "set/insert_rv.pass.cpp"
     "set/iterator.pass.cpp"
     "set/lower_bound.pass.cpp"
     "set/max_size.pass.cpp"
     "set/size.pass.cpp"
     "set/types.pass.cpp"
     "set/upper_bound.pass.cpp")

set (TEST_FILES_SET_CONS
     "set/set.cons/alloc.pass.cpp"
     "set/set.cons/assign_initializer_list.pass.cpp"
     "set/set.cons/compare.pass.cpp"
     "set/set.cons/compare_alloc.pass.cpp"
     "set/set.cons/compare_copy_constructible.fail.cpp"
     "set/set.cons/copy.pass.cpp"
     "set/set.cons/copy_alloc.pass.cpp"
     "set/set.cons/copy_assign.pass.cpp"
     "set/set.cons/default.pass.cpp"
     "set/set.cons/default_noexcept.pass.cpp"
     "set/set.cons/dtor_noexcept.pass.cpp"
     "set/set.cons/initializer_list.pass.cpp"
     "set/set.cons/initializer_list_compare.pass.cpp"
     "set/set.cons/initializer_list_compare_alloc.pass.cpp"
     "set/set.cons/iter_iter.pass.cpp"
     "set/set.cons/iter_iter_alloc.pass.cpp"
     "set/set.cons/iter_iter_comp.pass.cpp"
     "set/set.cons/move.pass.cpp"
     "set/set.cons/move_alloc.pass.cpp"
     "set/set.cons/move_assign.pass.cpp"
     "set/set.cons/move_assign_noexcept.pass.cpp"
     "set/set.cons/move_noexcept.pass.cpp")

set (TEST_FILES_SET_SPECIAL
     "set/set.special/member_swap.pass.cpp"
     "set/set.special/non_member_swap.pass.cpp"
     "set/set.special/swap_noexcept.pass.cpp")

set (TEST_SUPPORT_H_FILES
     "support/container_test_types.h"
     "support/count_new.hpp"
     "support/min_allocator.h"
     "support/MoveOnly.h"
     "support/DefaultOnly.h"
     "support/private_constructor.hpp"
     "support/test_macros.h"
     "support/test_allocator.h"
     "support/Counter.h"
     "support/test_iterators.h"
     "support/is_transparent.h")

set (TEST_SUPPORT_FILES
     "support/test_allocator.cpp"
     "support/min_allocator.cpp"
     "support/count_new.cpp"
     "support/Counter.cpp"
     "support/DefaultOnly.cpp"
     "support/private_constructor.cpp"
     "support/is_transparent.cpp")

set (TEST_SUPPORT_CONTAINERS_FILES
     "containers/Emplaceable.h"
     "containers/map_allocator_requirement_test_templates.h"
     "containers/set_allocator_requirement_test_templates.h"
     "containers/test_compare.h")

set (OTHER_FILES
     "defs.h"
     "fail_defs.h")

set (MAIN_FILES
     "Test.cpp")

source_group("Source Files\\" FILES ${MAIN_FILES})

source_group("Source Files\\map\\" FILES ${TEST_FILES_MAP})
source_group("Source Files\\map\\access\\" FILES ${TEST_FILES_MAP_ACCESS})
source_group("Source Files\\map\\cons\\" FILES ${TEST_FILES_MAP_CONS})
source_group("Source Files\\map\\modifiers\\" FILES ${TEST_FILES_MAP_MODIFIERS})
source_group("Source Files\\map\\ops\\" FILES ${TEST_FILES_MAP_OPS})
source_group("Source Files\\map\\special\\" FILES ${TEST_FILES_MAP_SPECIAL})

source_group("Source Files\\multimap\\" FILES ${TEST_FILES_MULTIMAP})
source_group("Source Files\\multimap\\access\\" FILES ${TEST_FILES_MULTIMAP_ACCESS})
source_group("Source Files\\multimap\\cons\\" FILES ${TEST_FILES_MULTIMAP_CONS})
source_group("Source Files\\multimap\\modifiers\\" FILES ${TEST_FILES_MULTIMAP_MODIFIERS})
source_group("Source Files\\multimap\\ops\\" FILES ${TEST_FILES_MULTIMAP_OPS})
source_group("Source Files\\multimap\\special\\" FILES ${TEST_FILES_MULTIMAP_SPECIAL})

source_group("Source Files\\multiset\\" FILES ${TEST_FILES_MULTISET})
source_group("Source Files\\multiset\\access\\" FILES ${TEST_FILES_MULTISET_ACCESS})
source_group("Source Files\\multiset\\cons\\" FILES ${TEST_FILES_MULTISET_CONS})
source_group("Source Files\\multiset\\modifiers\\" FILES ${TEST_FILES_MULTISET_MODIFIERS})
source_group("Source Files\\multiset\\ops\\" FILES ${TEST_FILES_MULTISET_OPS})
source_group("Source Files\\multiset\\special\\" FILES ${TEST_FILES_MULTISET_SPECIAL})

source_group("Source Files\\set\\" FILES ${TEST_FILES_SET})
source_group("Source Files\\set\\access\\" FILES ${TEST_FILES_SET_ACCESS})
source_group("Source Files\\set\\cons\\" FILES ${TEST_FILES_SET_CONS})
source_group("Source Files\\set\\modifiers\\" FILES ${TEST_FILES_SET_MODIFIERS})
source_group("Source Files\\set\\ops\\" FILES ${TEST_FILES_SET_OPS})
source_group("Source Files\\set\\special\\" FILES ${TEST_FILES_SET_SPECIAL})

source_group("Source Files\\support\\" FILES ${TEST_SUPPORT_FILES})

source_group("Header Files\\support\\" FILES ${TEST_SUPPORT_H_FILES})
source_group("Header Files\\containers\\" FILES ${TEST_SUPPORT_CONTAINERS_FILES})
source_group("Header Files\\" FILES ${OTHER_FILES})

include_directories (${PROJECT_SOURCE_DIR}/src/include)
include_directories (./catch)
include_directories (./support)
include_directories (./containers)
include_directories (.)

add_executable (Test ${MAIN_FILES} ${TEST_SUPPORT_FILES} ${TEST_SUPPORT_H_FILES} ${TEST_SUPPORT_CONTAINERS_FILES} ${OTHER_FILES}
     ${TEST_FILES_MAP} ${TEST_FILES_MAP_ACCESS} ${TEST_FILES_MAP_CONS} ${TEST_FILES_MAP_MODIFIERS} ${TEST_FILES_MAP_OPS} ${TEST_FILES_MAP_SPECIAL}
     ${TEST_FILES_MULTIMAP} ${TEST_FILES_MULTIMAP_ACCESS} ${TEST_FILES_MULTIMAP_CONS} ${TEST_FILES_MULTIMAP_MODIFIERS} ${TEST_FILES_MULTIMAP_OPS} ${TEST_FILES_MULTIMAP_SPECIAL}
     ${TEST_FILES_MULTISET} ${TEST_FILES_MULTISET_ACCESS} ${TEST_FILES_MULTISET_CONS} ${TEST_FILES_MULTISET_MODIFIERS} ${TEST_FILES_MULTISET_OPS} ${TEST_FILES_MULTISET_SPECIAL}
     ${TEST_FILES_SET} ${TEST_FILES_SET_ACCESS} ${TEST_FILES_SET_CONS} ${TEST_FILES_SET_MODIFIERS} ${TEST_FILES_SET_OPS} ${TEST_FILES_SET_SPECIAL})

#
# install
#

install (TARGETS Test RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
