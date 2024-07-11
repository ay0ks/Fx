#pragma once
#include <initializer_list>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

namespace fx::standard
{
	namespace details
	{
		template<typename Value>
		using base_vector = std::vector<Value>;
	}

	template<typename Value>
	class vector : public details::base_vector<Value>
	{};

	template<>
	class vector<std::string> : public details::base_vector<std::string>
	{
	public:
		vector(std::string value, std::string delimiter);
	};
}