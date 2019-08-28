
#pragma once

#include <stdint.h>
#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"

namespace candy {

template <typename TL, typename T>
struct FindT;

template <typename... Ts, typename T>
struct FindT<Typelist<Ts...>, T>
{
private:
    using TL = Typelist<Ts...>;
    static constexpr int32_t temp = FindT<PopFront<TL>, T>::value;

public:
    static constexpr int32_t value = (temp == -1 ? -1 : temp + 1);
};

template <typename... Ts, typename T>
struct FindT<Typelist<T, Ts...>, T>
{
    static constexpr int32_t value = 0;
};

template <typename T>
struct FindT<Typelist<>, T>
{
    static constexpr int32_t value = -1;
};

template <typename TL, typename T>
using Find = FindT<TL, T>;

template <
    typename TL,
    template <typename T> class Predicate,
    bool = Empty<TL>::value>
struct FindIfT;

template <
    typename TL,
    template <typename T> class Predicate>
struct FindIfT<TL, Predicate, true>
{
    static constexpr int32_t value = -1;
};

template <
    typename TL,
    template <typename T> class Predicate>
struct FindIfT<TL, Predicate, false>
{
private:
    static constexpr bool temp = Predicate<Front<TL>>::value;

public:
    static constexpr int32_t value = (temp ? 0 : FindIfT<PopFront<TL>, Predicate>::value + 1);
};

template <
    typename TL,
    template <typename T> class Predicate>
using FindIf = FindIfT<TL, Predicate>;

} // namespace candy
