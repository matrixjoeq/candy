
#pragma once

#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL>
struct FrontT;

template <typename Head, typename... Tail>
struct FrontT<Typelist<Head, Tail...>>
{
    using Type = Head;
};

} // namespace detail

template <typename TL>
using Front = typename detail::FrontT<TL>::Type;

} // namespace candy
