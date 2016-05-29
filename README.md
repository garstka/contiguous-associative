
# contiguous-associative

C++14 [multi]{set,map} interface on a sorted vector.

## Differences to std::[multi]{set,map}
- The template parameter Container is the underlying container, which must be
 compatible with std::vector.
- Iterators are random-access, and iterator invalidation rules are inherited
 from the underlying container.
- The container swap is noexcept if Container::swap is noexcept with the
 provided allocator, and ADL swap for Compare objects is noexcept.
- Insertion/erasure of a single element is log2(n) + average n/2 (worst case n).
- Insertion of a range of k elements sorts input (klogk) and performs a merge
 (linear in n+k).
- The container has additional requirements, stemming from the fact that
 a vector is a contiguous container.
 
## Relation to boost::flat_[multi]{map,set} and Loki::AssocVector
 Boost and Loki implement similar containers. Here are the major differences:
 - contiguous::[multi]{map,set} containers support the operations introduced in C++14.
 - By default, the value_type for [multi]map is std::pair\<const Key,T\> for
  compatibility with std::[multi]map, as opposed to Boost's and Loki's
  std::pair\<Key,T\>. This behavior can be easily altered by flipping a flag in
  contiguous_settings.h.
 
## Requirements
 The requirements depend on the operations performed, but:

 - the requirements for a [multi]set stay practically the same as
  for a Container\<Key\>.
 - [multi]map needs to store a std::pair\<const Key,T\> (by default).
  The const-qualified key makes the pair non-assignable. To mitigate this,
  a wrapper is used that requires the following to be true:

```  
std::is_move_constructible<const Key>::value &&  
std::is_move_constructible<T>::value
```

 The first expression means that Key must have a copy constructor or
 a Key(const Key&&). Same goes for T, however if it's not const-qualified,
 it can also have a regular move constructor.

 If the boost-like value_type is used (std::pair\<Key,T\>), the requirements are
 less strict:

```  
std::is_move_constructible<Key>::value &&  
std::is_move_constructible<T>::value
```

## Additional notes
 - The iterator wrappers for [multi]map are SCARY if the Container iterators
 are SCARY (they depend on the Container iterators, [multi]map::pointer
 and [multi]map::value_type).
 - The implementation is based on the working draft n4296 of the C++ Standard.
 - The containers were tested using modified libc++ unit tests.

## License and feedback

The code was written as a programming exercise by me (Matt Garstka) and
is provided under the MIT/Expat license. If you have any feedback, please let me know
via email.