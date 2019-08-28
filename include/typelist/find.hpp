
#pragma once

#include <stdint.h>
#include <type_traits>
#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"

namespace candy {

template <typename TL, typename T, bool = Empty<TL>::value>
struct FindT;

template <typename TL, typename T>
struct FindT<TL, T, false>
{
private:
    static constexpr bool temp = std::is_same<Front<TL>, T>::value;
    static constexpr int32_t value_tail = FindT<PopFront<TL>, T>::value;

public:
    static constexpr int32_t value = (temp ? 0 : (value_tail == -1 ? -1 : value_tail + 1));
};

template <typename TL, typename T>
struct FindT<TL, T, true>
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

template <
    typename TL,
    template <typename T> class Predicate,
    bool = Empty<TL>::value>
struct FindIfNotT;

template <
    typename TL,
    template <typename T> class Predicate>
struct FindIfNotT<TL, Predicate, true>
{
    static constexpr int32_t value = -1;
};

template <
    typename TL,
    template <typename T> class Predicate>
struct FindIfNotT<TL, Predicate, false>
{
private:
    static constexpr bool temp = Predicate<Front<TL>>::value;

public:
    static constexpr int32_t value = (temp ? FindIfNotT<PopFront<TL>, Predicate>::value + 1 : 0);
};

template <
    typename TL,
    template <typename T> class Predicate>
using FindIfNot = FindIfNotT<TL, Predicate>;

} // namespace candy
