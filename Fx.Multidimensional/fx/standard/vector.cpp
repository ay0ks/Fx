// TODO(1): move this to a separate Fx.Standard package

#include "vector.hpp"

#include <string_view>

namespace fx
{
	namespace standard
	{
		template<typename Value>
		vector<Value>::vector():
			_vector{}
		{}

		template<typename Value>
		vector<Value>::vector(Value value):
			_vector(value)
		{}

		template<typename Value>
		vector<Value>::vector(std::initializer_list<Value> values):
			_vector(values)
		{}

		template<>
		vector<std::string>::vector():
			_vector{}
		{}

		template<>
		vector<std::string>::vector(std::string value):
			_vector{value}
		{}

		template<>
		vector<std::string>::vector(std::string value, std::string delimiter):
			_vector{}
		{
			for (const auto part : std::views::split(value, delimiter))
				_vector.push_back(std::string(std::string_view(part)));
		}

		template<>
		vector<std::string>::vector(std::initializer_list<std::string> values):
			_vector(values)
		{}
	}
}