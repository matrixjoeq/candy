
#pragma once

#include "front.hpp"
#include "reverse.hpp"

namespace candy {

template <typename TL>
struct BackT : FrontT<Reverse<TL>>
{
};

template <typename TL>
using Back = typename BackT<TL>::Type;

} // namespace candy