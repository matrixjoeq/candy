
#pragma once

#include "empty.hpp"
#include "front.hpp"
#include "push_back.hpp"
#include "pop_front.hpp"

namespace candy {

template <typename TL, bool = Empty<TL>::value>
struct ReverseT;

template <typename TL>
using Reverse = typename ReverseT<TL>::Type;

template <typename TL>
struct ReverseT<TL, false>
    : PushBackT<Reverse<PopFront<TL>>, Front<TL>>
{
};

template <typename TL>
struct ReverseT<TL, true>
{
    using Type = TL;
};

} // namespace candy