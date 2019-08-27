
#pragma once

#include "typelist.hpp"

namespace candy {

template <typename TL, typename T>
struct PushBackT;

template <typename... Ts, typename T>
struct PushBackT<Typelist<Ts...>, T>
{
    using Type = Typelist<Ts..., T>;
};

template <typename TL, typename T>
using PushBack = typename PushBackT<TL, T>::Type;

} // namespace candy
