
#pragma once

#include "typelist.hpp"

namespace candy {

template <typename TL>
struct FrontT;

template <typename T, typename... Ts>
struct FrontT<Typelist<T, Ts...>>
{
    using Type = T;
};

template <typename TL>
using Front = typename FrontT<TL>::Type;

} // namespace candy
