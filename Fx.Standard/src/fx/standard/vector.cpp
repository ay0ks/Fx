#include <fx/standard/vector.hpp>
#include <string_view>

namespace fx::standard
{
	using details::base_vector;

	vector<std::string>::vector(std::string value, std::string delimiter) :
		base_vector<std::string>{}
	{
		for (const auto part : std::views::split(value, delimiter))
			this->push_back(std::string(std::string_view(part)));
	}
}