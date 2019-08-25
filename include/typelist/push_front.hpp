
#pragma once

#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL, typename Head>
struct PushFrontT;

template <typename... Ts, typename Head>
struct PushFrontT<Typelist<Ts...>, Head>
{
    using Type = Typelist<Head, Ts...>;
};

} // namespace detail

template <typename TL, typename Head>
using PushFront = typename detail::PushFrontT<TL, Head>::Type;

} // namespace candy
