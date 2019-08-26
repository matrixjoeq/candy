
#pragma once

#include <stdint.h>
#include "pop_front.hpp"

namespace candy {
namespace detail {

template <typename TL, typename T>
struct FindT;

template <typename TL, typename T>
using Find = FindT<TL, T>;

template <typename... Ts, typename T>
struct FindT<Typelist<Ts...>, T>
{
private:
    using TL = Typelist<Ts...>;
    static constexpr int32_t temp = Find<PopFront<TL>, T>::value;

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

} // namespace detail

template <typename TL, typename T>
using Find = detail::Find<TL, T>;

} // namespace candy
