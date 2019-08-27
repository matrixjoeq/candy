
#pragma once

#include <stddef.h>
#include "empty.hpp"
#include "pop_front.hpp"

namespace candy {

template <typename TL, bool = Empty<TL>::value>
struct SizeT;

template <typename TL>
struct SizeT<TL, false>
{
    static constexpr size_t value = SizeT<PopFront<TL>>::value + 1;
};

template <typename TL>
struct SizeT<TL, true>
{
    static constexpr size_t value = 0;
};

template <typename TL>
using Size = SizeT<TL>;

} // namespace candy
