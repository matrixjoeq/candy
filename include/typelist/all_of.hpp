
#pragma once

#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"

namespace candy {

template <
    typename TL,
    template <typename T> class Predicate,
    bool = Empty<TL>::value>
struct AllOfT;

template <
    typename TL,
    template <typename T> class Predicate>
struct AllOfT<TL, Predicate, true>
{
    static constexpr bool value = true;
};

template <
    typename TL,
    template <typename T> class Predicate>
struct AllOfT<TL, Predicate, false>
{
private:
    static constexpr bool temp = AllOfT<PopFront<TL>, Predicate>::value;

public:
    static constexpr bool value = (temp ? Predicate<Front<TL>>::value : false);
};

template <
    typename TL,
    template <typename T> class Predicate>
using AllOf = AllOfT<TL, Predicate>;

} // namespace candy
