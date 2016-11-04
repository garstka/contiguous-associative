// -*- C++ -*-
//===---------------------------- test_macros.h ---------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef SUPPORT_TEST_MACROS_HPP
#define SUPPORT_TEST_MACROS_HPP

#include <ciso646> // Get STL specific macros like _LIBCPP_VERSION

#include "defs.h"

#define TEST_CONCAT1(X, Y) X##Y
#define TEST_CONCAT(X, Y) TEST_CONCAT1(X, Y)

#define TEST_HAS_FEATURE(X) 0

#define TEST_HAS_INCLUDE(X) 0

#define TEST_HAS_EXTENSION(X) 0

#define TEST_HAS_BUILTIN(X) 0

#define TEST_HAS_BUILTIN_IDENTIFIER(X) 0

/* Make a nice name for the standard version */
#ifndef TEST_STD_VER
#if  __cplusplus <= 199711L
# define TEST_STD_VER 3
#elif __cplusplus <= 201103L
# define TEST_STD_VER 11
#elif __cplusplus <= 201402L
# define TEST_STD_VER 14
#else
# define TEST_STD_VER 16    // current year; greater than current standard
#endif
#endif

/* Features that were introduced in C++14 */
#if TEST_STD_VER >= 14
#define TEST_HAS_EXTENDED_CONSTEXPR
#define TEST_HAS_VARIABLE_TEMPLATES
#endif

/* Features that were introduced after C++14 */
#if TEST_STD_VER > 14
#endif

#if TEST_STD_VER >= 11
#define TEST_CONSTEXPR constexpr
#define TEST_NOEXCEPT noexcept
#define TEST_NOEXCEPT_COND(...) noexcept(__VA_ARGS__)
# if TEST_STD_VER >= 14
#   define TEST_CONSTEXPR_CXX14 constexpr
# else
#   define TEST_CONSTEXPR_CXX14
# endif
#define TEST_ALIGNOF(...) alignof(__VA_ARGS__)
#define TEST_ALIGNAS(...) alignas(__VA_ARGS__)
#else
#define TEST_CONSTEXPR
#define TEST_CONSTEXPR_CXX14
#define TEST_NOEXCEPT throw()
#define TEST_NOEXCEPT_COND(...)
#define TEST_ALIGNOF(...) __alignof(__VA_ARGS__)
#define TEST_ALIGNAS(...) __attribute__((__aligned__(__VA_ARGS__)))
#endif

#define TEST_ALIGNAS_TYPE(...) TEST_ALIGNAS(TEST_ALIGNOF(__VA_ARGS__))

#if !TEST_HAS_FEATURE(cxx_rtti) && !defined(__cpp_rtti) \
    && !defined(__GXX_RTTI)
#define TEST_HAS_NO_RTTI
#endif

#if !TEST_HAS_FEATURE(cxx_exceptions) && !defined(__cpp_exceptions) \
     && !defined(__EXCEPTIONS)
#define TEST_HAS_NO_EXCEPTIONS
#endif

#if TEST_HAS_FEATURE(address_sanitizer) || TEST_HAS_FEATURE(memory_sanitizer) || \
    TEST_HAS_FEATURE(thread_sanitizer)
#define TEST_HAS_SANITIZERS
#endif

#if defined(_LIBCPP_NORETURN)
#define TEST_NORETURN _LIBCPP_NORETURN
#else
#define TEST_NORETURN [[noreturn]]
#endif

/* Macros for testing libc++ specific behavior and extensions */
#define LIBCPP_ASSERT(...) ((void)0)
#define LIBCPP_STATIC_ASSERT(...) ((void)0)
#define LIBCPP_ONLY(...) ((void)0)

#define ASSERT_NOEXCEPT(...) \
    static_assert(noexcept(__VA_ARGS__), "Operation must be noexcept")

#define ASSERT_NOT_NOEXCEPT(...) \
    static_assert(!noexcept(__VA_ARGS__), "Operation must NOT be noexcept")

namespace test_macros_detail {
template <class T, class U>
struct is_same { enum { value = 0};} ;
template <class T>
struct is_same<T, T> { enum {value = 1}; };
} // namespace test_macros_detail

#define ASSERT_SAME_TYPE(...) \
    static_assert(test_macros_detail::is_same<__VA_ARGS__>::value, \
                 "Types differ uexpectedly")

#ifndef TEST_HAS_NO_EXCEPTIONS
#define TEST_THROW(...) throw __VA_ARGS__
#else
#if defined(__GNUC__)
#define TEST_THROW(...) __builtin_abort()
#else
#include <stdlib.h>
#define TEST_THROW(...) ::abort()
#endif
#endif

#endif // SUPPORT_TEST_MACROS_HPP
