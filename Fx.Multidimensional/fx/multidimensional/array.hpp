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
            using item = T;

        private:
            std::array<std::size_t, Dimensions> dimensions;
            std::vector<T> data;

            template <typename... Indices>
            constexpr std::size_t calculate_index(Indices... indices) const;

        public:
            template <typename... Sizes>
            array(Sizes... sizes);

            template <typename... Indices>
            T& operator()(Indices... indices);

            template <typename... Indices>
            const T& operator()(Indices... indices) const;

            constexpr std::size_t shape(std::size_t dimension) const;
        };
    }
}