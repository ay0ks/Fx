#pragma once
#include <initializer_list>
#include <map>
#include <string>
#include <utility>

namespace fx::multidimensional
{
	namespace details
	{
		template<typename Key, typename Value, std::size_t Depth>
		struct map_helper
		{
			typedef std::map<Key, typename map_helper<Key, Value, Depth - 1>::type> type;
		};

		template<typename Key, typename Value>
		struct map_helper<Key, Value, 1>
		{
			typedef std::map<Key, Value> type;
		};

		template<typename Key, typename Value>
		struct map_helper<Key, Value, 0>
		{
			static_assert(false, "Illegal map of depth 0");
		};

		template<typename Key, typename Value, std::size_t Depth>
		using map = typename map_helper<Key, Value, Depth>::type;
	}

	template<typename Key, typename Value, std::size_t Depth>
	class map
	{
	public:
		using map_type = typename details::map<Key, Value, Depth>::type;

		using key_type = map_type::key_type;
		using mapped_type = map_type::mapped_type;
		using value_type = map_type::value_type;
		using size_type = map_type::size_type;
		using difference_type = map_type::difference_type;
		using key_compare = map_type::key_compare;
		using allocator_type = map_type::allocator_type;
		using reference = map_type::reference;
		using const_reference = map_type::const_reference;
		using pointer = map_type::pointer;
		using const_pointer = map_type::const_pointer;
		using iterator = map_type::iterator;
		using const_iterator = map_type::const_iterator;
		using reverse_iterator = map_type::reverse_iterator;
		using const_reverse_iterator = map_type::const_reverse_iterator;
		using node_type = map_type::node_type;
		using insert_return_type = map_type::insert_return_type;

		using value_compare = map_type::value_compare;

	private:
		map_type _map;

	private:
		template<typename... Keys, std::size_t... Is>
		reference
			access_element(map_type& m, const std::tuple<Keys...>& keys, std::index_sequence<Is...>);

	public:
		map();
		map(value_type value);
		map(std::initializer_list<value_type> values);

		template<typename... Keys>
			requires std::same_as<Keys..., Key>
		reference
			operator ()(Keys... keys);

		reference
			operator [](const Key& key);

		reference
			operator [](Key&& key);

		template<class K>
		reference
			operator [](K&& x);
	};

	template <typename Value, size_t Depth>
	class map<std::string, Value, Depth> : public map<std::string, Value, Depth>
	{
	public:
		using map_type = typename details::map<std::string, Value, Depth>::type;

		using key_type = map_type::key_type;
		using mapped_type = map_type::mapped_type;
		using value_type = map_type::value_type;
		using size_type = map_type::size_type;
		using difference_type = map_type::difference_type;
		using key_compare = map_type::key_compare;
		using allocator_type = map_type::allocator_type;
		using reference = map_type::reference;
		using const_reference = map_type::const_reference;
		using pointer = map_type::pointer;
		using const_pointer = map_type::const_pointer;
		using iterator = map_type::iterator;
		using const_iterator = map_type::const_iterator;
		using reverse_iterator = map_type::reverse_iterator;
		using const_reverse_iterator = map_type::const_reverse_iterator;
		using node_type = map_type::node_type;
		using insert_return_type = map_type::insert_return_type;

		using value_compare = map_type::value_compare;

	public:
		reference
			operator ()(const std::string& key);
	};
}