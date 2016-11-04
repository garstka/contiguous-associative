#pragma once

// Ignore irrelevant fragments of code.
#define IGNORE_LIBCXX_SPECIFIC

// Ignore the requirement that allocator.construct() and allocator.destruct()
// should only be called with value_type instead of the internal type from alloc
// rebind.
// This definition also ignores most of libc++ expect-check allocator functionality.
#define IGNORE_REQUIREMENT_23_2_1_3

// Define this, if allocator mismatch should not be treated as a fail.
// Map and multimap use allocator rebind, so this would just be
// a formality.
// Set and multiset will fail, if the vector implementation
// doesn't allow it.
// libstdc++ and the Standard Library shipping with
// Visual Studio don't seem to care about this, libc++ does.
#define ALLOW_ALLOCATOR_MISMATCH

// Define this to make MoveOnly work with std::vector.
// Vector won't work with classes like MoveOnly, Moveable
// (no copy constructor, non-const move constructor),
// if the moved-from object is const.
#define MODIFY_MOVEONLY_TO_WORK_WITH_VECTOR

// Ignore fragments of code related to DefaultOnly.
// DefaultOnly won't work with std::vector-based containers.
#define IGNORE_DEFAULT_ONLY

// Ignore fragments of code that test set insert range on non move-assignable objects.
// Multiset range/initializer list insert requires value_type to be
// MoveAssignable (std::stable_sort requirement).
#define MULTISET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE

// Ignore fragments of code that test multiset insert range on non move-assignable objects.
// Set range/initializer list insert requires value_type to be
// MoveAssignable (std::unique requirement).
#define SET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE

// Ignore fragments of code that test multiset insert/emplace on non move-assignable objects.
// Most emplace/insert operations on set/multiset will fail with test objects
// that are not CopyAssignable / MoveAssignable.
#define VECTOR_REQUIRES_ASSIGNABLE

// Move some static definitions to cpp files to avoid linker errors.
#define MOVED_TO_CPP_FILE

// Ignore MemCounter functionality.
// count_new.hpp relies on a global object, which doesn't work very well
// with multiple cpp files.
#define DISABLE_NEW_COUNT

// Don't treat non-empty container after move as a fail.
// libc++ asserts that a container must be empty after std::move,
// but for the underlying vector that isn't the case (valid, but unspecified
// state).
#define ALLOWED_NON_EMPTY_AFTER_MOVE

// Ignore all assertions testing, if the container is stable.
// Vector is an unstable container.
#define CONTAINERS_ARE_UNSTABLE

// swap() with different allocators that don't compare equal and
// std::allocator_traits<allocator_type>::propagate_on_container_swap::value ==
// false is undefined behaviour (the test seems to be libc++ specific).
#define IGNORE_ILLEGAL_SWAP

// Ignore some allocator debug info that a test prints to stdout.
#define IGNORE_DEBUG_OUT

// Don't test noexcept specifiers to be exactly the same as std::[container] - noexcept depends on the vector
#define MAP_SWAP_NOEXCEPT_SPECS_DIFFERENT_TO_STD
#define MULIMAP_SWAP_NOEXCEPT_SPECS_DIFFERENT_TO_STD
#define MULTISET_SWAP_NOEXCEPT_SPECS_DIFFERENT_TO_STD
#define SET_SWAP_NOEXCEPT_SPECS_DIFFERENT_TO_STD

// Make min_pointer work with gcc std::vector (add implicit conversion to T*)
#define MIN_PTR_GCC_FIX

// Ignore tests checking the ability to instantiate map/multimap with an incomplete type.
// Map/multimap uses a wrapper that needs to know if a type is copy-constructible at
// instantiation time.
#define MAP_REQUIRE_COMPLETE_TYPE
#define MULTIMAP_REQUIRE_COMPLETE_TYPE

// Comment out MoveOnly private constructor.
// GCC seems to have problems access checking and claims that
// std::is_copy_constructible<MoveOnly> == true
// due to the private constructor.
#define MOVE_ONLY_GCC_FIX

// Test C++14 features?
#if 0
#define CPLUSPLUS 201103L
#define TEST_STD_VER 11
#define LIBCPP_STD_VER 11
#else
#define CPLUSPLUS 201402L
#define TEST_STD_VER 14
#define LIBCPP_STD_VER 14
#endif