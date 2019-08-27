
#pragma once

#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"

namespace candy {

template <
    typename TL,
    template <typename X, typename Y> class F,
    typename I,
    bool = Empty<TL>::value>
struct AccumulateT;

template <
    typename TL,
    template <typename X, typename Y> class F,
    typename I>
struct AccumulateT<TL, F, I, false>
    : AccumulateT<PopFront<TL>, F, typename F<I, Front<TL>>::Type>
{
};

template <
    typename TL,
    template <typename X, typename Y> class F,
    typename I>
struct AccumulateT<TL, F, I, true>
{
    using Type = I;
};

template <
    typename TL,
    template <typename X, typename Y> class F,
    typename I>
using Accumulate = typename AccumulateT<TL, F, I>::Type;

} // namespace candy
