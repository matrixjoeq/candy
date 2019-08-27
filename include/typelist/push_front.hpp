
#pragma once

#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL, typename T>
struct PushFrontT;

template <typename... Ts, typename T>
struct PushFrontT<Typelist<Ts...>, T>
{
    using Type = Typelist<T, Ts...>;
};

} // namespace detail

template <typename TL, typename T>
using PushFront = typename detail::PushFrontT<TL, T>::Type;

} // namespace candy
