#include <fx/multidimensional/map.hpp>
#include <fx/standard/vector.hpp>

namespace fx::multidimensional
{
	template<typename Key, typename Value, std::size_t Depth>
	template<typename... Keys, std::size_t... Is>
	map<Key, Value, Depth>::reference
		map<Key, Value, Depth>::access_element(
			map<Key, Value, Depth>::map_type& m,
			const std::tuple<Keys...>& keys,
			std::index_sequence<Is...>
		)
	{
		return ((m)[std::get<Is>(keys)], ...);
	}

	template<typename Key, typename Value, std::size_t Depth>
	map<Key, Value, Depth>::map() :
		_map{}
	{}

	template<typename Key, typename Value, std::size_t Depth>
	map<Key, Value, Depth>::map(value_type value) :
		_map{ value }
	{}

	template<typename Key, typename Value, std::size_t Depth>
	map<Key, Value, Depth>::map(std::initializer_list<value_type> value) :
		_map{ value }
	{}

	template<typename Key, typename Value, std::size_t Depth>
	template<typename... Keys>
		requires std::same_as<Keys..., Key>
	map<Key, Value, Depth>::reference
	map<Key, Value, Depth>::operator ()(Keys... keys)
	{
		return access_element(
			_map,
			std::tuple<Keys...>(keys...),
			std::make_index_sequence<sizeof...(Keys) - 1>()
		);
	}

	template<typename Key, typename Value, std::size_t Depth>
	map<Key, Value, Depth>::reference
	map<Key, Value, Depth>::operator [](const Key& key)
	{
		return _map[key];
	}

	template<typename Key, typename Value, std::size_t Depth>
	map<Key, Value, Depth>::reference
	map<Key, Value, Depth>::operator [](Key&& key)
	{
		return _map[std::forward<Key>(key)];
	}

	template<typename Key, typename Value, std::size_t Depth>
	template<class K>
	map<Key, Value, Depth>::reference
	map<Key, Value, Depth>::operator [](K&& x)
	{
		return _map[std::forward<K>(x)];
	}

	template<typename Value, size_t Depth>
	map<std::string, Value, Depth>::reference
	map<std::string, Value, Depth>::operator ()(const std::string& key)
	{
		if (key.contains("."))
			return (*this)(vector<std::string>{ key, "." }...);

		return (*this)(key);
	}
}