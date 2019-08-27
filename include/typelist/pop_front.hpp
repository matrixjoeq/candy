
#pragma once

#include "typelist.hpp"

namespace candy {

template <typename TL>
struct PopFrontT;

template <typename T, typename... Ts>
struct PopFrontT<Typelist<T, Ts...>>
{
    using Type = Typelist<Ts...>;
};

template <typename TL>
using PopFront = typename PopFrontT<TL>::Type;

} // namespace candy
