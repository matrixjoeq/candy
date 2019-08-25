
#pragma once

#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL, typename Tail>
struct PushBackT;

template <typename... Ts, typename Tail>
struct PushBackT<Typelist<Ts...>, Tail>
{
    using Type = Typelist<Ts..., Tail>;
};

} // namespace detail

template <typename TL, typename Tail>
using PushBack = typename detail::PushBackT<TL, Tail>::Type;

} // namespace candy
