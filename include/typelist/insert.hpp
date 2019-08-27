
#pragma once

#include <stdint.h>
#include "utility.hpp"
#include "typelist.hpp"
#include "size.hpp"

namespace candy {

template <
    typename TL,
    typename T,
    uint32_t N,
    bool = InRange<N, 0, Size<TL>::value + 1>::value>
struct InsertT;

template <typename TL, typename T, uint32_t N>
struct InsertT<TL, T, N, true>
{
    using Type = TL;
};

template <typename TL, typename T, uint32_t N>
using Insert = typename InsertT<TL, T, N>::Type;

} // namespace candy
