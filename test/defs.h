#pragma once

// Ignore irrelevant fragments of code.
#define IGNORE_LIBCXX_SPECIFIC

// Ignore the requirement that allocator.construct() and allocator.destruct()
// should
// only be called with value_type instead of the internal type from alloc
// rebind.
// This also ignores most of libc++ expect-check allocator functionality.
#define IGNORE_REQUIREMENT_23_2_1_3

// Define this, if allocator mismatch should not be treated as a fail.
// The containers use allocator rebind, so this would just be
// a formality. libstdc++ and the Standard Library shipping with
// Visual Studio don't seem to care about this, libc++ does.
#define ALLOW_ALLOCATOR_MISMATCH

// Vector won't work with classes like MoveOnly, Moveable
// (no copy constructor, non-const move constructor),
// if the moved-from object is const.
#define MODIFY_MOVEONLY_TO_WORK_WITH_VECTOR

// DefaultOnly won't work with std::vector-based containers.
#define IGNORE_DEFAULT_ONLY

// Multiset range/initializer list insert requires value_type to be
// MoveAssignable (std::stable_sort requirement).
#define MULTISET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE

// Multiset range/initializer list insert requires value_type to be
// MoveAssignable (std::unique requirement).
#define SET_INSERT_RANGE_REQUIRES_MOVE_ASSIGNABLE

// Most emplace/insert operations on set/multiset will fail with test objects
// that are not CopyAssignable / MoveAssignable.
#define VECTOR_REQUIRES_ASSIGNABLE

// Some static definitions needed to be moved from a header to the corresponding
// cpp file to avoid linker errors.
#define MOVED_TO_CPP_FILE

// count_new.hpp relies on a global object, which doesn't work very well
// with multiple cpp files
#define DISABLE_NEW_COUNT

// libc++ asserts that a container must be empty after std::move,
// but for the underlying vector that isn't the case (valid, but unspecified
// state).
#define ALLOWED_NON_EMPTY_AFTER_MOVE

// Vector is an unstable container - ignore all assertions that test that.
#define CONTAINERS_ARE_UNSTABLE

// swap() with different allocators that don't compare equal and
// std::allocator_traits<allocator_type>::propagate_on_container_swap::value ==
// false is undefined behaviour (the test seems to be libc++ specific).
#define IGNORE_ILLEGAL_SWAP

// Ignore some allocator debug info that a test prints to stdout.
#define IGNORE_DEBUG_OUT

// Test C++14 features?
#if 0
#define CPLUSPLUS 201103L
#define TEST_STD_VER 11
#define _LIBCPP_STD_VER 11
#else
#define CPLUSPLUS 201402L
#define TEST_STD_VER 14
#define _LIBCPP_STD_VER 14
#endif