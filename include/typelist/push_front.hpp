
#pragma once

#include "typelist.hpp"

namespace candy {

template <typename TL, typename T>
struct PushFrontT;

template <typename... Ts, typename T>
struct PushFrontT<Typelist<Ts...>, T>
{
    using Type = Typelist<T, Ts...>;
};

template <typename TL, typename T>
using PushFront = typename PushFrontT<TL, T>::Type;

} // namespace candy
