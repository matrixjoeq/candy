
#pragma once

#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_back.hpp"

namespace candy {

template <typename TL1, typename TL2, bool = Empty<TL2>::value>
struct ConcatT;

template <typename TL1, typename TL2>
struct ConcatT<TL1, TL2, true>
{
    using Type = TL1;
};

template <typename TL1, typename TL2>
struct ConcatT<TL1, TL2, false>
    : ConcatT<PushBack<TL1, Front<TL2>>, PopFront<TL2>>
{
};

template <typename TL1, typename TL2>
using Concat = typename ConcatT<TL1, TL2>::Type;

} // namespace candy
