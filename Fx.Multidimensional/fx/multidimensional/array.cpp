#include "array.hpp"

namespace fx
{
    namespace multidimensional
    {
        template<typename T, std::size_t Dimensions>
        template<typename... Indices>
        constexpr std::size_t 
        array<T, Dimensions>::calculate_index(Indices... indices) const
        {
            std::size_t index_array[Dimensions]{ static_cast<std::size_t>(indices)... };
            std::size_t index = 0;
            std::size_t multiplier = 1;

            for (std::size_t i = Dimensions; i-- > 0;) {
                index += index_array[i] * multiplier;
                multiplier *= _dimensions[i];
            }

            return index;
        }

        template<typename T, std::size_t Dimensions>
        template<typename... Sizes>
        array<T, Dimensions>::array(Sizes... sizes):
            _dimensions{ static_cast<std::size_t>(sizes)... },
            _data(accumulate(_dimensions.begin(), _dimensions.end(), 1, multiplies<>{}))
        {}

        template<typename T, std::size_t Dimensions>
        template<typename... Indices>
        array<T, Dimensions>::reference
        array<T, Dimensions>::operator()(Indices... indices)
        {
            static_assert(sizeof...(indices) == Dimensions, "Number of indices must match the number of dimensions");
            return _data[calculate_index(indices...)];
        }

        template<typename T, std::size_t Dimensions>
        template <typename... Indices>
        array<T, Dimensions>::const_reference
        array<T, Dimensions>::operator()(Indices... indices) const
        {
            static_assert(sizeof...(indices) == Dimensions, "Number of indices must match the number of dimensions");
            return _data[calculate_index(indices...)];
        }

        template<typename T, std::size_t Dimensions>
        constexpr std::size_t 
        array<T, Dimensions>::shape(std::size_t dimension) const
        {
            return _dimensions[dimension];
        }
    }
}