
#pragma once

#include <stdint.h>

namespace candy {

/**
 * @brief Convert integer value to a type
 */
template <int64_t N>
struct Int2Type
{
    static constexpr int64_t value = N;
};

} // namespace candy
