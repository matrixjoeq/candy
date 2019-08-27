
#pragma once

#include "pop_front.hpp"
#include "reverse.hpp"

namespace candy {

template <typename TL>
struct PopBackT : ReverseT<PopFront<Reverse<TL>>>
{
};

template <typename TL>
using PopBack = typename PopBackT<TL>::Type;

} // namespace candy
