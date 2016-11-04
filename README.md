
# contiguous-associative

C++14 [multi]{map,set} interface on a sorted vector.

## Main differences to std::[multi]{map,set}
- Additional parameter - the underlying container compatible with std::vector.
- Random-access iterators, invalidation rules inherited from vector.
- Insert/erase of a single element is log2(n) + average n/2 (worst case n).
- Insert range of k elements sorts input (klogk) and performs a merge (n+k).
- Different noexcept specifications (inherited from vector).
- Additional requirements
   - [multi]map: const Key and T must be move-constructible.
   - [multi]set: most ops need Key to be move-assignable (same as vector).

## Relation to boost::flat_[multi]{map,set} and Loki::AssocVector
 Boost and Loki implement similar containers. The major differences are:
 - contiguous::map supports operations introduced in C++14 (insert_or_assign, try_emplace).
 - contiguous::[multi]map keeps the immutable key in the value_type: `std::pair<const Key,T>`.
 Boost and Loki use `std::pair<Key,T>`.
 
## Basic map/multimap requirement

```
std::is_move_constructible<const Key>::value &&  
std::is_move_constructible<T>::value
```

 The first expression means that Key must have a copy constructor or
 a `Key(const Key&&)`. Same goes for T, however if it's not const-qualified,
 a regular move constructor will work best.

## Unit tests
 - Containers were tested using customized libc++ unit tests on Windows (Visual Studio 14)
 and Linux (GCC 6.2.0).
 - You can build and run the tests using CMake. The framework is Catch, so running the
  Test executable provides the best results, but ctest (make test) also works.
 - `defs.h` contains macros commenting out irrelevant or incompatible parts of code from
 the original tests, each with a short justification.
 - `fail_defs.h` lists macros that enable tests with deliberate compile-time errors.
 
## Additional implementation notes
 - The implementation is based on the working draft n4296 of the C++ Standard.
 - Using a wrapper means that general container requirement 23.2.1.3 is violated.
 (`Allocator::construct` and `Allocator::destruct` must be used only with value_type).
 There's no easy way around this, as far as I'm aware, as it's the underlying
  container that handles those calls, and its value_type is the wrapper.
 - Iterators for [multi]map are SCARY if Container iterators
 are SCARY (i.e. they depend only on Container iterators, pointer and value_type).

## License and feedback

The code was written as a programming exercise by me (Matt Garstka) and
is provided under the MIT license. If you have any feedback, please let me know
via email.

libc++ unit tests are provided under the MIT license (see test/LICENSE.txt).