#pragma once

#include <utility>
#include <functional>
#include <iterator>
#include <memory>
#include <type_traits>
#include <algorithm>
#include "contiguous_settings.h"

/**
    @file contiguous_internal.h
    @brief Iterators, traits, pair wrapper, comparator.
*/

namespace contiguous
{

namespace internal
{

	// add const to Key, if (USE_CONST_QUALIFIED_KEY)
	template <class Key>
	using qualify_key =
	    std::conditional_t<USE_CONST_QUALIFIED_KEY, const Key, Key>;

	/*!
	    Wrapper for a std::pair that allows for it to be stored in a
	    std::vector, even if one or both of the member types are not
	    assignable (e.g. const-qualified).

	    Requires:
	        std::is_move_constructible<Key>::value &&
	        std::is_move_constructible<Mapped>::value

	    This means that if Key = const K, then
	        std::is_constructible<K,const K&&>::value
	    must be true, i.e. it has to have one of the following constructors:
	    K(const K&), K(const K&&)
	*/
	template <class Key, class Mapped>
	class wrapped_pair
	{
	private:
		using T1 = Key; // stored pair types
		using T2 = Mapped;

		using value_type = std::pair<T1, T2>;

		// stored pair
		std::aligned_storage_t<sizeof(value_type), alignof(value_type)> p;

	public:
		static_assert(
		    std::is_move_constructible<T1>::value,
		    "Possibly const-qualified key type must be move constructible.");
		static_assert(
		    std::is_move_constructible<T2>::value,
		    "Possibly const-qualified mapped type must be move constructible.");

		// constructors

		// copy constructor
		wrapped_pair(const wrapped_pair& v) noexcept(
		    noexcept(value_type(v.get())))
		{
			new (&p) value_type(v.get());
		}

		// move constructor
		wrapped_pair(wrapped_pair&& v) noexcept(
		    noexcept(value_type(std::move(v.get()))))
		{
			new (&p)
			    value_type(std::move(v.get().first), std::move(v.get().second));
		}

		// default constructor
		template <
		    class = std::enable_if_t<std::is_default_constructible<T1>::value &&
		                             std::is_default_constructible<T2>::value>>
		constexpr wrapped_pair() noexcept(noexcept(value_type()))
		{
			new (&p) value_type();
		}

		// construct by copying member-wise
		template <
		    class = std::enable_if_t<std::is_copy_constructible<T1>::value &&
		                             std::is_copy_constructible<T2>::value>>
		constexpr wrapped_pair(const T1& x,
		                       const T2& y) noexcept(noexcept(value_type(x, y)))
		{
			new (&p) value_type(x, y);
		}

		// construct by forwarding member-wise
		template <
		    class U,
		    class V,
		    class = std::enable_if_t<std::is_constructible<T1, U&&>::value &&
		                             std::is_constructible<T2, V&&>::value &&
		                             std::is_convertible<U, T1>::value &&
		                             std::is_convertible<V, T2>::value>>
		constexpr wrapped_pair(U&& x, V&& y) noexcept(
		    noexcept(value_type(std::forward<U>(x), std::forward<V>(y))))
		{
			new (&p) value_type(std::forward<U>(x), std::forward<V>(y));
		}

		// initializes members from the corresponding members of the argument
		template <class U,
		          class V,
		          class = std::enable_if_t<
		              std::is_constructible<T1, const U&>::value &&
		              std::is_constructible<T2, const V&>::value &&
		              std::is_convertible<const U&, T1>::value &&
		              std::is_convertible<const V&, T2>::value>>
		constexpr wrapped_pair(const std::pair<U, V>& other) noexcept(
		    noexcept(value_type(other)))
		{
			new (&p) value_type(other);
		}

		// initializes members by forwarding the corresponding members of the
		// argument
		template <
		    class U,
		    class V,
		    class = std::enable_if_t<std::is_constructible<T1, U&&>::value &&
		                             std::is_constructible<T2, V&&>::value &&
		                             std::is_convertible<U, T1>::value &&
		                             std::is_convertible<V, T2>::value>>
		constexpr wrapped_pair(std::pair<U, V>&& other) noexcept(
		    noexcept(value_type(std::move(other))))
		{
			new (&p) value_type(std::move(other));
		}

		// piecewise construction
		template <class... Args1,
		          class... Args2,
		          class = std::enable_if_t<
		              std::is_constructible<T1, Args1&&...>::value &&
		              std::is_constructible<T2, Args2&&...>::value>>
		wrapped_pair(
		    std::piecewise_construct_t,
		    std::tuple<Args1...> first_args,
		    std::tuple<Args2...>
		        second_args) noexcept(noexcept(value_type(std::
		                                                      piecewise_construct,
		                                                  std::move(first_args),
		                                                  std::move(
		                                                      second_args))))
		{
			new (&p) value_type(std::piecewise_construct, std::move(first_args),
			                    std::move(second_args));
		}

		// destructor

		~wrapped_pair()
		{
			get().~value_type();
		}

		// operators

		wrapped_pair& operator=(const wrapped_pair& other) noexcept(
		    noexcept(get().~value_type()) && noexcept(value_type(other.get())))
		{
			if (&other == this) // self-assignment check
				return *this;

			// destruct p and copy-construct from other.p
			get().~value_type();
			new (&p) value_type(other.get());

			return *this;
		}

		wrapped_pair& operator=(wrapped_pair&& other) noexcept(
		    noexcept(get().~value_type()) &&
		    noexcept(value_type(std::move(other.get()))))
		{
			if (&other == this) // self-assignment check
				return *this;

			// destruct p and move-construct from other.p
			get().~value_type();
			new (&p) value_type(std::move(other.get()));

			return *this;
		}

		// get the reference to the wrapped pair
		const value_type& get() const noexcept
		{
			return *reinterpret_cast<const value_type*>(&p);
		}

		// get the reference to the wrapped pair
		value_type& get() noexcept
		{
			return *reinterpret_cast<value_type*>(&p);
		}

		// swap

		void swap(wrapped_pair& other) noexcept(noexcept(std::swap(*this,
		                                                           other)))
		{
			std::swap(*this, other);
		}

		template <class Key, class Mapped>
		friend constexpr bool operator==(const wrapped_pair<Key, Mapped>& x,
		                                 const wrapped_pair<Key, Mapped>& y);
		template <class Key, class Mapped>
		friend constexpr bool operator<(const wrapped_pair<Key, Mapped>& x,
		                                const wrapped_pair<Key, Mapped>& y);
		template <class Key, class Mapped>
		friend constexpr bool operator!=(const wrapped_pair<Key, Mapped>& x,
		                                 const wrapped_pair<Key, Mapped>& y);
		template <class Key, class Mapped>
		friend constexpr bool operator>(const wrapped_pair<Key, Mapped>& x,
		                                const wrapped_pair<Key, Mapped>& y);
		template <class Key, class Mapped>
		friend constexpr bool operator>=(const wrapped_pair<Key, Mapped>& x,
		                                 const wrapped_pair<Key, Mapped>& y);
		template <class Key, class Mapped>
		friend constexpr bool operator<=(const wrapped_pair<Key, Mapped>& x,
		                                 const wrapped_pair<Key, Mapped>& y);
	};

	template <class Key, class Mapped>
	constexpr bool operator==(const wrapped_pair<Key, Mapped>& x,
	                          const wrapped_pair<Key, Mapped>& y)
	{
		return x.get() == y.get();
	}

	template <class Key, class Mapped>
	constexpr bool operator<(const wrapped_pair<Key, Mapped>& x,
	                         const wrapped_pair<Key, Mapped>& y)
	{
		return x.get() < y.get();
	}

	template <class Key, class Mapped>
	constexpr bool operator!=(const wrapped_pair<Key, Mapped>& x,
	                          const wrapped_pair<Key, Mapped>& y)
	{
		return x.get() != y.get();
	}
	template <class Key, class Mapped>
	constexpr bool operator>(const wrapped_pair<Key, Mapped>& x,
	                         const wrapped_pair<Key, Mapped>& y)
	{
		return x.get() > y.get();
	}
	template <class Key, class Mapped>
	constexpr bool operator>=(const wrapped_pair<Key, Mapped>& x,
	                          const wrapped_pair<Key, Mapped>& y)
	{
		return x.get() >= y.get();
	}

	template <class Key, class Mapped>
	constexpr bool operator<=(const wrapped_pair<Key, Mapped>& x,
	                          const wrapped_pair<Key, Mapped>& y)
	{
		return x.get() <= y.get();
	}

	template <class Key, class Mapped>
	void swap(wrapped_pair<Key, Mapped>& x,
	          wrapped_pair<Key, Mapped>& y) noexcept(noexcept(x.swap(y)))
	{
		x.swap(y);
	}

	//! Compares various combinations of @c wrapped_pair<K,M>,
	//! @c pair<K,M>, and @c Key.
	template <class Key, class Mapped, class Compare>
	class wrapped_pair_compare
	{
	protected:
		using key_type = Key;
		using impl_value_type = wrapped_pair<Key, Mapped>;
		using value_type = std::pair<Key, Mapped>;

		Compare comp;

	public:
		using result_type = bool;
		using first_argument_type = value_type;
		using second_argument_type = value_type;

		wrapped_pair_compare(Compare c) : comp(c)
		{
		}

		//! Template compare - fetch the key from x and y, and compare them.
		template <class Left, class Right>
		bool operator()(const Left& x, const Right& y) const
		{
			return comp(fetch_key<Left>().fetch(x),
			            fetch_key<Right>().fetch(y));
		}

		//! Return a copy of the key comparator.
		Compare key_comp() const
		{
			return comp;
		}

		void swap(wrapped_pair_compare& other) noexcept(
		    noexcept(adl::swap_with_adl(comp, other.comp)))
		{
			adl::swap_with_adl(comp, other.comp);
		}

	private:
		/* Fetch key_type or T that may be comparable to key_type. */
		template <class T>
		struct fetch_key
		{
			/* Fetch T that may be comparable to key_type,
			   fetch it as long as Compare::is_transparent */
			template <class = Compare::is_transparent>
			const T& fetch(const T& x) const
			{
				return x;
			}
		};

		/* Fetch the regular key_type */
		template <>
		struct fetch_key<std::remove_const_t<key_type>> // Don't care if
		                                                // key_type is
		                                                // const_qualified.
		{
			const key_type& fetch(const key_type& x) const
			{
				return x;
			}
		};
		/* Fetch the key_type from the value_type */
		template <>
		struct fetch_key<value_type>
		{
			const key_type& fetch(const value_type& x) const
			{
				return x.first;
			}
		};

		/* Fetch the key_type from the impl_value_type */
		template <>
		struct fetch_key<impl_value_type>
		{
			const key_type& fetch(const impl_value_type& x) const
			{
				return x.get().first;
			}
		};
	};

	//! swap
	template <class Key, class Mapped, class Compare>
	void swap(wrapped_pair_compare<Key, Mapped, Compare>& x,
	          wrapped_pair_compare<Key, Mapped, Compare>&
	              y) noexcept(noexcept(x.swap(y)))
	{
		x.swap(y);
	}

	// immutable iterator

	//! A random access iterator to @c const @c ValueType
	//! To obtain a Value&, it calls (*[wrapped iterator]).get().
	template <class ImplConstIterator, class ValueType, class Pointer>
	class wrapped_pair_const_iterator
	    : public std::iterator<
	          typename ImplConstIterator::
	              iterator_category,                       // iterator_category
	          ValueType,                                   // value_type
	          typename ImplConstIterator::difference_type, // difference_type
	          Pointer,                                     // pointer
	          const ValueType&>                            // reference
	{
	protected:
		using impl_const_iterator = ImplConstIterator;
		impl_const_iterator it;

		using MyBase =
		    std::iterator<typename ImplConstIterator::iterator_category,
		                  ValueType,
		                  typename ImplConstIterator::difference_type,
		                  Pointer,
		                  const ValueType&>;

	public:
		using typename MyBase::iterator_category;
		using typename MyBase::value_type;
		using typename MyBase::difference_type;
		using typename MyBase::pointer;
		using typename MyBase::reference;

		// empty iterator
		wrapped_pair_const_iterator()
		{
		}

		// from container iterator
		wrapped_pair_const_iterator(impl_const_iterator it_in) : it(it_in)
		{
		}

		// return reference
		reference operator*() const
		{
			return it->get(); // return the wrapped pair
		}

		// return pointer
		pointer operator->() const
		{
			return std::pointer_traits<pointer>::pointer_to(**this);
		}

		// preincrement
		wrapped_pair_const_iterator& operator++()
		{
			++it;
			return *this;
		}

		// postincrement
		wrapped_pair_const_iterator operator++(int)
		{
			auto tmp = *this;
			++(*this);
			return tmp;
		}

		// predecrement
		wrapped_pair_const_iterator& operator--()
		{
			--it;
			return *this;
		}

		// postdecrement
		wrapped_pair_const_iterator operator--(int)
		{
			auto tmp = *this;
			--(*this);
			return tmp;
		}

		// add offset
		wrapped_pair_const_iterator& operator+=(difference_type offset)
		{
			it += offset;
			return *this;
		}

		// return this + offset
		wrapped_pair_const_iterator operator+(difference_type offset) const
		{
			auto tmp = *this;
			return tmp += offset;
		}

		// add -offset
		wrapped_pair_const_iterator& operator-=(difference_type offset)
		{
			return (*this) += (-offset);
		}

		// return this - offset
		wrapped_pair_const_iterator operator-(difference_type offset) const
		{
			auto tmp = *this;
			return tmp -= offset;
		}

		// difference of iterators
		difference_type operator-(
		    const wrapped_pair_const_iterator& right) const
		{
			return it - right.it;
		}

		// offset dereference
		reference operator[](difference_type offset) const
		{
			return *(*this + offset);
		}

		// equality
		bool operator==(const wrapped_pair_const_iterator& right) const
		{
			return it == right.it;
		}

		// inequality
		bool operator!=(const wrapped_pair_const_iterator& right) const
		{
			return it != right.it;
		}

		// less than
		bool operator<(const wrapped_pair_const_iterator& right) const
		{
			return it < right.it;
		}

		// greater than
		bool operator>(const wrapped_pair_const_iterator& right) const
		{
			return it > right.it;
		}

		// less or equal to
		bool operator<=(const wrapped_pair_const_iterator& right) const
		{
			return it <= right.it;
		}

		// greater or equal to
		bool operator>=(const wrapped_pair_const_iterator& right) const
		{
			return it >= right.it;
		}

		// convert to container const iterator
		operator impl_const_iterator() const
		{
			return it;
		}
	};

	// mutable iterator

	//! A random access iterator to @c const @c ValueType.
	//! To obtain a ValueType&, it calls (*[wrapped iterator]).get().
	template <class ImplIterator,
	          class ImplConstIterator,
	          class ValueType,
	          class Pointer,
	          class ConstIterator>
	class wrapped_pair_iterator
	    : public std::iterator<
	          typename ImplIterator::iterator_category, // iterator_category
	          ValueType,                                // value_type
	          typename ImplIterator::difference_type,   // difference_type
	          Pointer,                                  // pointer
	          ValueType&>                               // reference
	{
	private:
		using MyBase = std::iterator<typename ImplIterator::iterator_category,
		                             ValueType,
		                             typename ImplIterator::difference_type,
		                             Pointer,
		                             ValueType&>;

	protected:
		using impl_iterator = ImplIterator;
		using impl_const_iterator = ImplConstIterator;

		using const_iterator = ConstIterator;

		impl_iterator it;

	public:
		using typename MyBase::iterator_category;
		using typename MyBase::value_type;
		using typename MyBase::difference_type;
		using typename MyBase::pointer;
		using typename MyBase::reference;

		// empty iterator
		wrapped_pair_iterator()
		{
		}

		// from container iterator
		wrapped_pair_iterator(impl_iterator it_in) : it(it_in)
		{
		}

		// return reference
		reference operator*()
		{
			return it->get(); // return the wrapped object reference
		}

		// return pointer
		pointer operator->()
		{
			return std::pointer_traits<pointer>::pointer_to(**this);
		}

		// preincrement
		wrapped_pair_iterator& operator++()
		{
			++it;
			return *this;
		}

		// postincrement
		wrapped_pair_iterator operator++(int)
		{
			auto tmp = *this;
			++(*this);
			return tmp;
		}

		// predecrement
		wrapped_pair_iterator& operator--()
		{
			--it;
			return *this;
		}

		// postdecrement
		wrapped_pair_iterator operator--(int)
		{
			auto tmp = *this;
			--(*this);
			return tmp;
		}

		// add offset
		wrapped_pair_iterator& operator+=(difference_type offset)
		{
			it += offset;
			return *this;
		}

		// return this + offset
		wrapped_pair_iterator operator+(difference_type offset) const
		{
			auto tmp = *this;
			return tmp += offset;
		}

		// add -offset
		wrapped_pair_iterator& operator-=(difference_type offset)
		{
			return (*this) += (-offset);
		}

		// return this - offset
		wrapped_pair_iterator operator-(difference_type offset) const
		{
			auto tmp = *this;
			return tmp -= offset;
		}

		// difference of iterators
		difference_type operator-(const wrapped_pair_iterator& right) const
		{
			return it - right.it;
		}

		// offset dereference
		reference operator[](difference_type offset) const
		{
			return *(*this + offset);
		}

		// equality
		bool operator==(const wrapped_pair_iterator& right) const
		{
			return it == right.it;
		}

		// inequality
		bool operator!=(const wrapped_pair_iterator& right) const
		{
			return it != right.it;
		}

		// less than
		bool operator<(const wrapped_pair_iterator& right) const
		{
			return it < right.it;
		}

		// greater than
		bool operator>(const wrapped_pair_iterator& right) const
		{
			return it > right.it;
		}

		// less or equal to
		bool operator<=(const wrapped_pair_iterator& right) const
		{
			return it <= right.it;
		}

		// greater or equal to
		bool operator>=(const wrapped_pair_iterator& right) const
		{
			return it >= right.it;
		}


		// equality to const iterator
		bool operator==(const const_iterator& right) const
		{
			return it == impl_const_iterator(right);
		}

		// inequality to const iterator
		bool operator!=(const const_iterator& right) const
		{
			return it != impl_const_iterator(right);
		}

		// less than const iterator
		bool operator<(const const_iterator& right) const
		{
			return it < impl_const_iterator(right);
		}
		// greater than const iterator
		bool operator>(const const_iterator& right) const
		{
			return it > impl_const_iterator(right);
		}

		// less or equal to const iterator
		bool operator<=(const const_iterator& right) const
		{
			return it <= impl_const_iterator(right);
		}

		// greater or equal to const iterator
		bool operator>=(const const_iterator& right) const
		{
			return it >= impl_const_iterator(right);
		}


		// convert to container iterator
		operator impl_iterator() const
		{
			return it;
		}

		// convert to container iterator
		operator impl_const_iterator() const
		{
			return it;
		}

		// convert to const_iterator
		operator const_iterator() const
		{
			return it;
		}
	};

	// Used in noexcept specifiers that depend on ADL-enabled swap.
	namespace adl
	{
		using std::swap; // enable adl for swap

		template <class T>
		void swap_with_adl(T& a, T& b) noexcept(noexcept(swap(a, b)))
		{
			swap(a, b);
		}
	}

	// base_traits - template argument for contiguous_multi_base,
	// contiguous_single_base and contiguous_base
	template <class KeyT,
	          class ContainerT,
	          class ImplContainerT,
	          class CompareT,
	          class ValueCompareT,
	          class IteratorT,
	          class ConstIteratorT>
	struct base_traits
	{
		using Key = KeyT;
		using Container = ContainerT;
		using ImplContainer = ImplContainerT;
		using Compare = CompareT;
		using ValueCompare = ValueCompareT;
		using Iterator = IteratorT;
		using ConstIterator = ConstIteratorT;
	};

	// base_traits for contiguous_set and contiguous_multiset
	template <class Key, class Compare, class Container>
	using set_traits =
	    base_traits<Key,                                 // Key
	                Container,                           // Container
	                Container,                           // ImplContainer
	                Compare,                             // Compare
	                Compare,                             // ValueCompare
	                typename Container::const_iterator,  // Iterator
	                typename Container::const_iterator>; // ConstIterator

	// A helper struct that correctly specializes the iterator wrappers for
	// contiguous::map and contiguous::multimap
	template <class Key,
	          class T,
	          class Alloc,
	          template <class V, class A> class Container>
	struct specialize_map_iterators
	{
	private:
		// helper types

		using impl_value_type = wrapped_pair<qualify_key<Key>, T>;
		using impl_container = Container<impl_value_type, Alloc>;
		using impl_pointer = typename impl_container::pointer;
		using value_type = std::pair<qualify_key<Key>, T>;
		using pointer = typename std::pointer_traits<
		    impl_pointer>::template rebind<value_type>;
		using const_pointer = typename std::pointer_traits<
		    impl_pointer>::template rebind<const value_type>;

	public:
		// immutable iterator
		using const_iterator = wrapped_pair_const_iterator<
		    /* ImplConstIterator */ typename impl_container::const_iterator,
		    /* ValueType         */ value_type,
		    /* Pointer           */ const_pointer>;

		// mutable iterator
		using iterator = wrapped_pair_iterator<
		    /* ImplIterator      */ typename impl_container::iterator,
		    /* ImplConstIterator */ typename impl_container::const_iterator,
		    /* ValueType         */ value_type,
		    /* Pointer           */ pointer,
		    /* ConstIterator     */ const_iterator>;
	};

	// base_traits for contiguous::map and contiguous::multimap
	template <class Key,
	          class T,
	          class Compare,
	          class Alloc,
	          template <class V, class A> class Container>
	using map_traits = base_traits<
	    /* Key           */ Key,
	    /* Container     */ Container<std::pair<qualify_key<Key>, T>, Alloc>,
	    /* ImplContainer */ Container<wrapped_pair<qualify_key<Key>, T>, Alloc>,
	    /* Compare       */ Compare,
	    /* ValueCompare  */ wrapped_pair_compare<qualify_key<Key>, T, Compare>,
	    /* Iterator      */
	    typename specialize_map_iterators<Key, T, Alloc, Container>::iterator,
	    /* ConstIterator */
	    typename specialize_map_iterators<Key, T, Alloc, Container>::
	        const_iterator>;
}
}