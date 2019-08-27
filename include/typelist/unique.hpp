
#pragma once

#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"
#include "remove.hpp"

namespace candy {

template <typename TL, bool = Empty<TL>::value>
struct UniqueT;

template <typename TL>
using Unique = typename UniqueT<TL>::Type;

template <typename TL>
struct UniqueT<TL, true>
{
    using Type = TL;
};

template <typename TL>
struct UniqueT<TL, false>
    : PushFrontT<Remove<Unique<PopFront<TL>>, Front<TL>>, Front<TL>>
{
};

} // namespace candy
