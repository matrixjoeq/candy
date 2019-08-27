
#pragma once

#include <type_traits>
#include "utility/if_then_else.hpp"
#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"

namespace candy {

template <typename TL, typename T, bool = Empty<TL>::value>
struct RemoveT;

template <typename TL, typename T>
using Remove = typename RemoveT<TL, T>::Type;

template <typename TL, typename T>
struct RemoveT<TL, T, true>
{
    using Type = TL;
};

template <typename TL, typename T>
struct RemoveT<TL, T, false>
{
    using Type = IfThenElse<std::is_same<Front<TL>, T>::value,
                            PopFront<TL>,
                            PushFront<Remove<PopFront<TL>, T>, Front<TL>>>;
};

template <typename TL, typename T, bool = Empty<TL>::value>
struct RemoveAllT;

template <typename TL, typename T>
using RemoveAll = typename RemoveAllT<TL, T>::Type;

template <typename TL, typename T>
struct RemoveAllT<TL, T, true>
{
    using Type = TL;
};

template <typename TL, typename T>
struct RemoveAllT<TL, T, false>
{
    using Type = IfThenElse<std::is_same<Front<TL>, T>::value,
                            RemoveAll<PopFront<TL>, T>,
                            PushFront<RemoveAll<PopFront<TL>, T>, Front<TL>>>;
};

} // namespace candy
