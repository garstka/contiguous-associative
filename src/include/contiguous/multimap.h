#pragma once

#include <vector>

#include "contiguous_multi_base.h"

/**
    @file multimap.h
    @brief @c std::multimap interface on an ordered vector.
*/

namespace contiguous
{

/*!
    @brief @c std::multimap interface on an ordered vector.

    @param Key key type
    @param T mapped type
    @param Compare strict weak order comparator
    @param Alloc allocator
    @param Container container compatible with @c std::vector

*/
template <class Key,
          class T,
          class Compare = std::less<Key>,
          class Alloc =
              std::allocator<std::pair<internal::qualify_key<Key>, T>>,
          template <class V, class A> class Container = std::vector>
class multimap : public contiguous_multi_base<
                     internal::map_traits<Key, T, Compare, Alloc, Container>>
{
private:
	// the base class, same as above
	using MyBase = contiguous_multi_base<
	    internal::map_traits<Key, T, Compare, Alloc, Container>>;

public:
	//! @name types
	/// @{

	using typename MyBase::key_type;
	using mapped_type = T;
	using typename MyBase::value_type;
	using typename MyBase::allocator_type;

	using typename MyBase::key_compare;
	using typename MyBase::value_compare;
	using typename MyBase::reference;
	using typename MyBase::const_reference;
	using typename MyBase::pointer;
	using typename MyBase::const_pointer;

	using typename MyBase::iterator;
	using typename MyBase::const_iterator;
	using typename MyBase::reverse_iterator;
	using typename MyBase::const_reverse_iterator;

	using typename MyBase::difference_type;
	using typename MyBase::size_type;

	/// @}
	//! @name construct/copy/destroy
	/// @{

	// empty

	//! Constructs an empty multimap.
	multimap() noexcept(noexcept(key_compare()) && noexcept(allocator_type()))
	  : multimap(key_compare(), allocator_type())
	{
	}

	//! Constructs an empty multimap using the comparison object and allocator.
	explicit multimap(const key_compare& comp,
	                  const allocator_type& alloc = allocator_type())
	  : MyBase(comp, alloc)
	{
	}

	//! Constructs an empty multimap using the allocator.
	explicit multimap(const allocator_type& alloc) : MyBase(alloc)
	{
	}

	// range

	//! Constructs an empty multimap using the comparison object and allocator,
	//! and inserts elements from the range [first,last).
	template <class InputIterator>
	multimap(InputIterator first,
	         InputIterator last,
	         const key_compare& comp = key_compare(),
	         const allocator_type& alloc = allocator_type())
	  : MyBase(first, last, comp, alloc)
	{
	}

	//! Constructs using the allocator, and inserts elements from the range
	//! [first,last).
	template <class InputIterator>
	multimap(InputIterator first,
	         InputIterator last,
	         const allocator_type& alloc)
	  : multimap(first, last, key_compare(), alloc)
	{
	}

	// copy

	//! Constructs by copying other.
	multimap(const multimap& other) : MyBase(other)
	{
	}

	//! Constructs by copying other, using a different allocator.
	multimap(const multimap& other, const allocator_type& alloc)
	  : MyBase(other, alloc)
	{
	}

	// move

	//! Constructs by moving other.
	multimap(multimap&& other) noexcept(noexcept(MyBase(std::move(other))))
	  : MyBase(std::move(other))
	{
	}

	//! Constructs by moving other, using a different allocator.
	multimap(multimap&& other, const allocator_type& alloc)
	  : MyBase(std::move(other), alloc)
	{
	}

	// initializer list

	//! Constructs an empty multimap using the comparison object and allocator,
	//! and inserts elements from the initializer list.
	multimap(std::initializer_list<value_type> il,
	         const key_compare& comp = key_compare(),
	         const allocator_type& alloc = allocator_type())
	  : MyBase(il, comp, alloc)
	{
	}

	//! Constructs using the allocator and inserts elements from the
	//! initializer list.
	multimap(std::initializer_list<value_type> il, const allocator_type& alloc)
	  : multimap(il, key_compare(), alloc)
	{
	}

	//! Destructor.
	~multimap()
	{
	}

	// copy

	//! Copy-assigns other.
	multimap& operator=(const multimap& other)
	{
		MyBase::operator=(other);
		return *this;
	}
	// move

	//! Move-assigns other.
	multimap& operator=(multimap&& other) noexcept(
	    noexcept(MyBase::operator=(std::move(other))))
	{
		MyBase::operator=(std::move(other));
		return *this;
	}

	// initializer list

	//! Replaces the elements with the elements from the initializer list.
	multimap& operator=(std::initializer_list<value_type> il)
	{
		MyBase::operator=(il);
		return *this;
	}

	/// @}
	//! @name observers
	/// @{

	//! Returns a copy of the key comparator.
	key_compare key_comp() const
	{
		return comparator.key_comp();
	}

	/// @}

	// friend operators

	template <class Key,
	          class T,
	          class Compare,
	          class Alloc,
	          template <class V, class A> class Container>
	friend bool operator==(const multimap<Key, T, Compare, Alloc, Container>&,
	                       const multimap<Key, T, Compare, Alloc, Container>&);
	template <class Key,
	          class T,
	          class Compare,
	          class Alloc,
	          template <class V, class A> class Container>
	friend bool operator!=(const multimap<Key, T, Compare, Alloc, Container>&,
	                       const multimap<Key, T, Compare, Alloc, Container>&);
	template <class Key,
	          class T,
	          class Compare,
	          class Alloc,
	          template <class V, class A> class Container>
	friend bool operator<(const multimap<Key, T, Compare, Alloc, Container>&,
	                      const multimap<Key, T, Compare, Alloc, Container>&);
	template <class Key,
	          class T,
	          class Compare,
	          class Alloc,
	          template <class V, class A> class Container>
	friend bool operator<=(const multimap<Key, T, Compare, Alloc, Container>&,
	                       const multimap<Key, T, Compare, Alloc, Container>&);
	template <class Key,
	          class T,
	          class Compare,
	          class Alloc,
	          template <class V, class A> class Container>
	friend bool operator>(const multimap<Key, T, Compare, Alloc, Container>&,
	                      const multimap<Key, T, Compare, Alloc, Container>&);
	template <class Key,
	          class T,
	          class Compare,
	          class Alloc,
	          template <class V, class A> class Container>
	friend bool operator>=(const multimap<Key, T, Compare, Alloc, Container>&,
	                       const multimap<Key, T, Compare, Alloc, Container>&);
};

//! equality
template <class Key,
          class T,
          class Compare,
          class Alloc,
          template <class V, class A> class Container>
bool operator==(const multimap<Key, T, Compare, Alloc, Container>& lhs,
                const multimap<Key, T, Compare, Alloc, Container>& rhs)
{
	return lhs.data == rhs.data;
}

//! inequality
template <class Key,
          class T,
          class Compare,
          class Alloc,
          template <class V, class A> class Container>
bool operator!=(const multimap<Key, T, Compare, Alloc, Container>& lhs,
                const multimap<Key, T, Compare, Alloc, Container>& rhs)
{
	return lhs.data != rhs.data;
}

//! less than
template <class Key,
          class T,
          class Compare,
          class Alloc,
          template <class V, class A> class Container>
inline bool operator<(const multimap<Key, T, Compare, Alloc, Container>& lhs,
                      const multimap<Key, T, Compare, Alloc, Container>& rhs)
{
	return lhs.data < rhs.data;
}

//! less or equal to
template <class Key,
          class T,
          class Compare,
          class Alloc,
          template <class V, class A> class Container>
inline bool operator<=(const multimap<Key, T, Compare, Alloc, Container>& lhs,
                       const multimap<Key, T, Compare, Alloc, Container>& rhs)
{
	return lhs.data <= rhs.data;
}

//! greater than
template <class Key,
          class T,
          class Compare,
          class Alloc,
          template <class V, class A> class Container>
inline bool operator>(const multimap<Key, T, Compare, Alloc, Container>& lhs,
                      const multimap<Key, T, Compare, Alloc, Container>& rhs)
{
	return lhs.data > rhs.data;
}

//! greater or equal to
template <class Key,
          class T,
          class Compare,
          class Alloc,
          template <class V, class A> class Container>
inline bool operator>=(const multimap<Key, T, Compare, Alloc, Container>& lhs,
                       const multimap<Key, T, Compare, Alloc, Container>& rhs)
{
	return lhs.data >= rhs.data;
}

//! swap
template <class Key,
          class T,
          class Compare,
          class Alloc,
          template <class V, class A> class Container>
inline void swap(multimap<Key, T, Compare, Alloc, Container>& lhs,
                 multimap<Key, T, Compare, Alloc, Container>&
                     rhs) noexcept(noexcept(lhs.swap(rhs)))
{
	lhs.swap(rhs);
}
}