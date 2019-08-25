
#pragma once

#include "front.hpp"
#include "reverse.hpp"

namespace candy {
namespace detail {

template <typename TL>
struct BackT
{
    using Type = Front<Reverse<TL>>;
};

} // namespace detail

template <typename TL>
using Back = typename detail::BackT<TL>::Type;

} // namespace candy