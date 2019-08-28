
#pragma once

#include "any_of.hpp"

namespace candy {

template <
    typename TL,
    template <typename T> class Predicate>
struct NoneOfT
{
    static constexpr bool value = !AnyOf<TL, Predicate>::value;
};

template <
    typename TL,
    template <typename T> class Predicate>
using NoneOf = NoneOfT<TL, Predicate>;

} // namespace candy
