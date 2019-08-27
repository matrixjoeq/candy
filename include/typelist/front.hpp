
#pragma once

#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL>
struct FrontT;

template <typename T, typename... Ts>
struct FrontT<Typelist<T, Ts...>>
{
    using Type = T;
};

} // namespace detail

template <typename TL>
using Front = typename detail::FrontT<TL>::Type;

} // namespace candy
