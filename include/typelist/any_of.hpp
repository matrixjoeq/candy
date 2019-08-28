
#pragma once

#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"

namespace candy {

template <
    typename TL,
    template <typename T> class Predicate,
    bool = Empty<TL>::value>
struct AnyOfT;

template <
    typename TL,
    template <typename T> class Predicate>
struct AnyOfT<TL, Predicate, true>
{
    static constexpr bool value = false;
};

template <
    typename TL,
    template <typename T> class Predicate>
struct AnyOfT<TL, Predicate, false>
{
private:
    static constexpr bool temp = AnyOfT<PopFront<TL>, Predicate>::value;

public:
    static constexpr bool value = (temp ? true : Predicate<Front<TL>>::value);
};

template <
    typename TL,
    template <typename T> class Predicate>
using AnyOf = AnyOfT<TL, Predicate>;

} // namespace candy
