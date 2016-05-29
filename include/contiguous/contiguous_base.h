#pragma once

#include "contiguous_internal.h"

namespace contiguous
{

/**
    @file contiguous_base.h
    @brief Base class for associative containers based on a vector.
*/

template <class Traits>
class contiguous_base
{
protected:
	using container_type = typename Traits::Container;
	using impl_container_type = typename Traits::ImplContainer;
	using impl_value_type = typename Traits::ImplContainer::value_type;

public:
	//! @name types
	/// @{

	using key_type = typename Traits::Key;
	using value_type = typename container_type::value_type;
	using allocator_type = typename container_type::allocator_type;

	using key_compare = typename Traits::Compare;
	using reference = typename container_type::reference;
	using const_reference = typename container_type::const_reference;
	using pointer = typename container_type::pointer;
	using const_pointer = typename container_type::const_pointer;

	using iterator = typename Traits::Iterator;
	using const_iterator = typename Traits::ConstIterator;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	using difference_type = typename container_type::difference_type;
	using size_type = typename container_type::size_type;

	// value comparator

	using value_compare = typename Traits::ValueCompare;

	/// @}
	//! @name construct/copy/destroy
	/// @{

	// empty

	//! Constructs an empty container.
	contiguous_base() noexcept(noexcept(key_compare()) &&
	                           noexcept(allocator_type()))
	  : contiguous_base(key_compare(), allocator_type())
	{
	}

	//! Constructs an empty container using the comparison object and allocator.
	explicit contiguous_base(const key_compare& comp,
	                         const allocator_type& alloc = allocator_type())
	  : comparator(comp), data(alloc)
	{
	}

	//! Constructs an empty container using the allocator.
	explicit contiguous_base(const allocator_type& alloc)
	  : data(alloc), comparator(key_compare())
	{
	}

	// copy

	//! Constructs by copying other.
	contiguous_base(const contiguous_base& other)
	  : data(other.data), comparator(other.comparator)
	{
	}

	//! Constructs by copying other, using a different allocator.
	contiguous_base(const contiguous_base& other, const allocator_type& alloc)
	  : data(other.data, alloc), comparator(other.comparator)
	{
	}

	// move

	//! Constructs by moving other.
	contiguous_base(contiguous_base&& other) noexcept(
	    noexcept(impl_container_type(std::move(other.data))) &&
	    noexcept(value_compare(std::move(other.comparator))))
	  : data(std::move(other.data)), comparator(std::move(other.comparator))
	{
	}

	//! Constructs by moving other, using a different allocator.
	contiguous_base(contiguous_base&& other, const allocator_type& alloc)
	  : data(std::move(other.data), alloc),
	    comparator(std::move(other.comparator))
	{
	}

	//! Destructor.
	~contiguous_base()
	{
	}

	// copy

	//! Copy-assigns other.
	contiguous_base& operator=(const contiguous_base& other)
	{
		data = other.data;
		comparator = other.comparator;
		return *this;
	}
	// move

	//! Move-assigns other.
	contiguous_base& operator=(contiguous_base&& other) noexcept(
	    noexcept(data = std::move(other.data)) &&
	    noexcept(comparator = other.comparator))
	{
		data = std::move(other.data);
		comparator = std::move(other.comparator);
		return *this;
	}

	//! Returns the allocator for @c value_type.
	allocator_type get_allocator() const noexcept
	{
		return std::allocator_traits<
		    typename impl_container_type::allocator_type>::
		    rebind_alloc<value_type>(data.get_allocator());
	}

	/// @}
	//! @name iterators
	/// @{

	// random access

	//! Returns an iterator to the beginning.
	iterator begin() noexcept
	{
		return data.begin();
	}

	//! Returns a const iterator to the beginning.
	const_iterator begin() const noexcept
	{
		return data.cbegin();
	}

	//! Returns an iterator to the end.
	iterator end() noexcept
	{
		return data.end();
	}

	//! Returns a const iterator to the end.
	const_iterator end() const noexcept
	{
		return data.cend();
	}

	// reverse

	//! Returns a reverse iterator to the beginning.
	reverse_iterator rbegin() noexcept
	{
		return data.rbegin();
	}

	//! Returns a const reverse iterator to the beginning.
	const_reverse_iterator rbegin() const noexcept
	{
		return data.crbegin();
	}

	//! Returns a reverse iterator to the end.
	reverse_iterator rend() noexcept
	{
		return data.rend();
	}

	//! Returns a const reverse iterator to the end.
	const_reverse_iterator rend() const noexcept
	{
		return data.crend();
	}
	// const

	//! Returns a const iterator to the beginning.
	const_iterator cbegin() const noexcept
	{
		return data.cbegin();
	}

	//! Returns a const iterator to the end.
	const_iterator cend() const noexcept
	{
		return data.cend();
	}

	//! Returns a const reverse iterator to the beginning.
	const_reverse_iterator crbegin() const noexcept
	{
		return data.crbegin();
	}

	//! Returns a const reverse iterator to the end.
	const_reverse_iterator crend() const noexcept
	{
		return data.crend();
	}

	/// @}
	//! @name capacity
	/// @{

	//! Returns true if the container is empty.
	bool empty() const noexcept
	{
		return data.empty();
	}

	//! Returns the number of elements in the container.
	size_type size() const noexcept
	{
		return data.size();
	}

	//! Returns the maximum possible number of elements in the container.
	size_type max_size() const noexcept
	{
		return data.max_size();
	}

	/// @}
	//! @name modifiers
	/// @{


	//! Erases the element at @c position.
	//! Returns the iterator following the removed element.
	iterator erase(const_iterator position)
	{
		return data.erase(position);
	}


	//! Erases the elements in the range [first,last).
	//! Returns the iterator following the last removed element.
	iterator erase(const_iterator first, const_iterator last)
	{
		return data.erase(first, last);
	}

	//! Exchanges the contents of the container with those of other.
	void swap(contiguous_base& other) noexcept(
	    noexcept(data.swap(other.data)) &&
	    noexcept(internal::adl::swap_with_adl(comparator, other.comparator)))
	{
		using std::swap;
		data.swap(other.data);
		swap(comparator, other.comparator);
	}

	//! Removes all elements from the container.
	void clear() noexcept
	{
		data.clear();
	}

	/// @}
	//! @name observers
	/// @{

	//! Returns a copy of the value comparator.
	value_compare value_comp() const
	{
		return comparator;
	}

	/// @}
	//! @name lookup
	/// @{

	// lower_bound

	//! Returns an iterator to the first element that is not less than key.
	iterator lower_bound(const key_type& key)
	{
		return std::lower_bound(begin(), end(), key, comparator);
	}

	//! Const overload of lower_bound(key).
	const_iterator lower_bound(const key_type& key) const
	{
		return std::lower_bound(cbegin(), cend(), key, comparator);
	}

	//! Returns an iterator to the first element that compares not less than x.
	//! Only participates in overload resolution,
	//! if key_compare::is_transparent is valid and denotes a type.
	template <class K, class = key_compare::is_transparent>
	iterator lower_bound(const K& x)
	{
		return std::lower_bound(begin(), end(), x, comparator);
	}

	//! Const overload of lower_bound(x).
	//! Only participates in overload resolution,
	//! if key_compare::is_transparent is valid and denotes a type.
	template <class K, class = key_compare::is_transparent>
	const_iterator lower_bound(const K& x) const
	{
		return std::lower_bound(cbegin(), cend(), x, comparator);
	}

	// upper_bound

	//! Returns an iterator to the first element that is greater than key.
	iterator upper_bound(const key_type& key)
	{
		return std::upper_bound(begin(), end(), key, comparator);
	}

	//! Const overload of upper_bound(key).
	const_iterator upper_bound(const key_type& key) const
	{
		return std::upper_bound(cbegin(), cend(), key, comparator);
	}

	//! Returns an iterator to the first element that compares greater than x.
	//! if key_compare::is_transparent is valid and denotes a type.
	template <class K, class = key_compare::is_transparent>
	iterator upper_bound(const K& x)
	{
		return std::upper_bound(begin(), end(), x, comparator);
	}

	//! Const overload of upper_bound(x).
	//! if key_compare::is_transparent is valid and denotes a type.
	template <class K, class = key_compare::is_transparent>
	const_iterator upper_bound(const K& x) const
	{
		return std::upper_bound(cbegin(), cend(), x, comparator);
	}

	/// @}

protected:
	impl_container_type data; // Container for elements.
	value_compare comparator; // Predicate used for comparison of elements.
};

}