
#pragma once

#include <type_traits>
#include "utility/if_then_else.hpp"
#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"

namespace candy {

template <typename TL, typename T, typename U, bool = Empty<TL>::value>
struct ReplaceT;

template <typename TL, typename T, typename U>
using Replace = typename ReplaceT<TL, T, U>::Type;

template <typename TL, typename T, typename U>
struct ReplaceT<TL, T, U, true>
{
    using Type = TL;
};

template <typename TL, typename T, typename U>
struct ReplaceT<TL, T, U, false>
{
    using Type = IfThenElse<std::is_same<Front<TL>, T>::value,
                            PushFront<PopFront<TL>, U>,
                            PushFront<Replace<PopFront<TL>, T, U>, Front<TL>>>;
};

template <typename TL, typename T, typename U, bool = Empty<TL>::value>
struct ReplaceAllT;

template <typename TL, typename T, typename U>
using ReplaceAll = typename ReplaceAllT<TL, T, U>::Type;

template <typename TL, typename T, typename U>
struct ReplaceAllT<TL, T, U, true>
{
    using Type = TL;
};

template <typename TL, typename T, typename U>
struct ReplaceAllT<TL, T, U, false>
{
    using Type = IfThenElse<std::is_same<Front<TL>, T>::value,
                            ReplaceAll<PushFront<PopFront<TL>, U>, T, U>,
                            PushFront<ReplaceAll<PopFront<TL>, T, U>, Front<TL>>>;
};

} // namespace candy
