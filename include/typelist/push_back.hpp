
#pragma once

#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL, typename T>
struct PushBackT;

template <typename... Ts, typename T>
struct PushBackT<Typelist<Ts...>, T>
{
    using Type = Typelist<Ts..., T>;
};

} // namespace detail

template <typename TL, typename T>
using PushBack = typename detail::PushBackT<TL, T>::Type;

} // namespace candy
