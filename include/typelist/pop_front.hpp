
#pragma once

#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL>
struct PopFrontT;

template <typename Head, typename... Ts>
struct PopFrontT<Typelist<Head, Ts...>>
{
    using Type = Typelist<Ts...>;
};

} // namespace detail

template <typename TL>
using PopFront = typename detail::PopFrontT<TL>::Type;

} // namespace candy
