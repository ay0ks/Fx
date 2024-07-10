// TODO(1): move this to a separate Fx.Standard package

#pragma once
#include <initializer_list>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

namespace fx
{
	namespace standard
	{
		template<typename Value>
		class vector
		{
		public:
			using vector_type = std::vector<Value>;

			using value_type = vector_type::value_type;
			using allocator_type = vector_type::allocator_type;
			using size_type = vector_type::size_type;
			using difference_type = vector_type::difference_type;
			using reference = vector_type::reference;
			using const_reference = vector_type::const_reference;
			using pointer = vector_type::pointer;
			using const_pointer = vector_type::const_pointer;
			using iterator = vector_type::iterator;
			using const_iterator = vector_type::const_iterator;
			using reverse_iterator = vector_type::reverse_iterator;
			using const_reverse_iterator = vector_type::const_reverse_iterator;

		private:
			vector_type _vector;

		public:
			vector();
			vector(Value value);
			vector(std::initializer_list<Value> values);
		};

		template<>
		class vector<std::string>
		{
		public:
			using vector_type = std::vector<std::string>;

			using value_type = vector_type::value_type;
			using allocator_type = vector_type::allocator_type;
			using size_type = vector_type::size_type;
			using difference_type = vector_type::difference_type;
			using reference = vector_type::reference;
			using const_reference = vector_type::const_reference;
			using pointer = vector_type::pointer;
			using const_pointer = vector_type::const_pointer;
			using iterator = vector_type::iterator;
			using const_iterator = vector_type::const_iterator;
			using reverse_iterator = vector_type::reverse_iterator;
			using const_reverse_iterator = vector_type::const_reverse_iterator;

		private:
			vector_type _vector;

		public:
			vector();
			vector(std::string value);
			vector(std::string value, std::string delimiter);
			vector(std::initializer_list<std::string>);
		};
	}
}