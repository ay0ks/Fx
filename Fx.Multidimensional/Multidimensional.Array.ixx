export module fx.multidimensional.array;

import <algorithm>;
import <array>;
import <cstdint>;
import <numeric>;
import <vector>;

using namespace std;

export
template <typename T, size_t Dimensions>
class multi_array 
{
public:
    using item = T;
    size_t dimensions = Dimensions;

private:
    array<size_t, Dimensions> dimensions_;
    vector<T> data;

    template <typename... Indices>
    size_t calculate_index(Indices... indices) const 
    {
        array<size_t, dimensions> index_array{ indices... };
        size_t index = 0;
        size_t multiplier = 1;

        for (size_t i = dimensions; i-- > 0;) {
            index += index_array[i] * multiplier;
            multiplier *= dimensions_[i];
        }

        return index;
    }

public:
    template <typename... Sizes>
    explicit multi_array(Sizes... sizes):
        dimensions_{ sizes... },
        data(accumulate(dimensions_.begin(), dimensions_.end(), 1, multiplies<>{}))
    {}

    template <typename... Indices>
    T& operator()(Indices... indices) 
    {
        static_assert(sizeof...(indices) == dimensions, "Number of indices must match the number of dimensions");
        return data[calculate_index(indices...)];
    }

    template <typename... Indices>
    const T& operator()(Indices... indices) const 
    {
        static_assert(sizeof...(indices) == dimensions, "Number of indices must match the number of dimensions");
        return data[calculate_index(indices...)];
    }

    size_t shape(size_t dimension) const 
    {
        return dimensions_[dimension];
    }
};
