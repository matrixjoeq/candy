
#pragma once

#include "pop_front.hpp"
#include "reverse.hpp"

namespace candy {
namespace detail {

template <typename TL>
struct PopBackT
{
    using Type = Reverse<PopFront<Reverse<TL>>>;
};

} // namespace detail

template <typename TL>
using PopBack = typename detail::PopBackT<TL>::Type;

} // namespace candy
