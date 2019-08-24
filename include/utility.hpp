
#pragma once

#include <stddef.h>

namespace candy {

/**
 * @brief Get array size
 * @tparam T : array element type
 * @tparam N : array size
 * @param [in] ignored : array reference
 * @return array size
 */
template <typename T, size_t N>
constexpr size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

/**
 * @brief Convert integer value to a type
 */
template <int N>
struct IntToType
{
    static constexpr int value = N;
};

} // namespace candy
