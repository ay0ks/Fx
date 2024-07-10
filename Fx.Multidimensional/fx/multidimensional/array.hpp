#pragma once
#include <array>
#include <vector>

namespace fx
{
    namespace multidimensional
    {
        template<typename T, std::size_t Dimensions>
        class array
        {
        public:
            using value_type = T;
            using reference = value_type&;
            using const_reference = const value_type&;

        private:
            std::array<std::size_t, Dimensions> _dimensions;
            std::vector<value_type> _data;

            template <typename... Indices>
            constexpr std::size_t calculate_index(Indices... indices) const;

        public:
            template <typename... Sizes>
            array(Sizes... sizes);

            template <typename... Indices>
            reference operator()(Indices... indices);

            template <typename... Indices>
            const_reference operator()(Indices... indices) const;

            constexpr std::size_t shape(std::size_t dimension) const;
        };
    }
}