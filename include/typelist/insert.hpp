
#pragma once

#include <stdint.h>
#include "utility/range.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_back.hpp"
#include "push_front.hpp"
#include "size.hpp"

namespace candy {

template <
    typename TL,
    typename T,
    uint32_t N,
    bool = InRange<N, 0, Size<TL>::value + 1>::value>
struct InsertT;

template <typename TL, typename T, uint32_t N>
using Insert = typename InsertT<TL, T, N>::Type;

template <typename TL, typename T, uint32_t N, bool = (Size<TL>::value == N)>
struct InsertImplT : PushFrontT<Insert<PopFront<TL>, T, N - 1>, Front<TL>>
{
};

template <typename TL, typename T, uint32_t N>
struct InsertImplT<TL, T, N, true> : PushBackT<TL, T>
{
};

template <typename TL, typename T>
struct InsertT<TL, T, 0, true> : PushFrontT<TL, T>
{
};

template <typename TL, typename T, uint32_t N>
struct InsertT<TL, T, N, true> : InsertImplT<TL, T, N>
{
};

} // namespace candy
