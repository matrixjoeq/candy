
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

} // namespace candy
