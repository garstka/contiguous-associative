#pragma once

/**
    @file contiguous_settings.h
    @brief Alternative behavior settings.
*/

namespace contiguous
{

namespace internal
{
	enum : bool
	{
		// set to false to make std::pair<Key,T> the value type of map/multimap
		// instead of std::pair<const Key,T>
		USE_CONST_QUALIFIED_KEY = true
	};
}
}