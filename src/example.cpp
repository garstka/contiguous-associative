#include <iostream>
#include <string>
#include <utility>
#include <contiguous/map.h>
#include <contiguous/multimap.h>
#include <contiguous/multiset.h>
#include <contiguous/set.h>
#include <map>

// Extremely basic example, shows the container behavior with unique vs
// equivalent keys.
int main()
{
	using namespace contiguous;

	// show map/multimap unique-key

	auto m1 = map<int, std::string>();
	auto m2 = multimap<int, std::string>();

	std::cout << "\nmap:\n";

	m1.insert({{3, "three"},
	           {1, "one"},
	           {30, "thirty"},
	           {10, "ten"},
	           {10, "eleven"}});

	for (auto& x : m1)
		std::cout << x.first << " -> " << x.second << '\n';

	std::cout << "\nmultimap:\n";

	m2.insert({{3, "three"},
	           {1, "one"},
	           {30, "thirty"},
	           {10, "ten"},
	           {10, "seventy"},
	           {3, "definitely not three"}});

	for (auto& x : m2)
		std::cout << x.first << " -> " << x.second << '\n';

	struct Basic
	{
		Basic(int x, int y, std::string lab) : position(x, y), label(lab)
		{
		}

		std::pair<int, int> position;
		std::string label;
	};
	struct Cmp
	{
		bool operator()(const Basic& a, const Basic& b) const
		{
			return a.position < b.position;
		}
	};

	std::cout << "\nset:\n";

	auto s1 = set<Basic, Cmp>();
	auto s2 = multiset<Basic, Cmp>();

	s1.emplace(0, 1, "set");
	s1.emplace(7, 3, "multiset");
	s1.emplace(0, 2, "map");
	s1.emplace(0, 1, "std::set");
	s1.emplace(-1, -1, "map");

	for (auto& x : s1)
		std::cout << "(" << x.position.first << ", " << x.position.second
		          << ") - " << x.label << '\n';

	std::cout << "\nmultiset:\n";

	s2.emplace(0, 1, "set");
	s2.emplace(7, 3, "multiset");
	s2.emplace(0, 2, "map");
	s2.emplace(0, 1, "std::set");
	s2.emplace(-1, -1, "map");
	s2.emplace(-1, -1, "std::map");
	s2.emplace(0, 2, "std::map");

	for (auto& x : s2)
		std::cout << "(" << x.position.first << ", " << x.position.second
		          << ") - " << x.label << '\n';
}