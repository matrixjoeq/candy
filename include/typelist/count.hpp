
#pragma once

#include <stddef.h>
#include <type_traits>
#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"

namespace candy {

template <
    typename TL,
    template <typename T> class Predicate,
    bool = Empty<TL>::value>
struct CountIfT;

template <
    typename TL,
    template <typename T> class Predicate>
struct CountIfT<TL, Predicate, true>
{
    static constexpr size_t value = 0;
};

template <
    typename TL,
    template <typename T> class Predicate>
struct CountIfT<TL, Predicate, false>
{
private:
    static constexpr size_t temp = CountIfT<PopFront<TL>, Predicate>::value;

public:
    static constexpr size_t value = temp + (Predicate<Front<TL>>::value ? 1 : 0);
};

template <
    typename TL,
    template <typename T> class Predicate>
using CountIf = CountIfT<TL, Predicate>;

template <typename TL, typename T, bool = Empty<TL>::value>
struct CountT;

template <typename TL, typename T>
struct CountT<TL, T, true>
{
    static constexpr size_t value = 0;
};

template <typename TL, typename T>
struct CountT<TL, T, false>
{
private:
    static constexpr size_t temp = CountT<PopFront<TL>, T>::value;

public:
    static constexpr size_t value = temp + (std::is_same<Front<TL>, T>::value ? 1 : 0);
};

template <typename TL, typename T>
using Count = CountT<TL, T>;

} // namespace candy
