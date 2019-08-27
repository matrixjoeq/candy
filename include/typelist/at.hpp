
#pragma once

#include <stdint.h>
#include "utility/range.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "size.hpp"

namespace candy {

template <
    typename TL,
    uint32_t N,
    bool = InRange<N, 0, Size<TL>::value>::value>
struct AtT;

template <typename TL, uint32_t N>
struct AtT<TL, N, true> : AtT<PopFront<TL>, N - 1>
{
};

template <typename TL>
struct AtT<TL, 0, true> : FrontT<TL>
{
};

template <typename TL, uint32_t N>
using At = typename AtT<TL, N>::Type;

} // namespace candy
