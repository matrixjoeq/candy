
#pragma once

#include <stdint.h>
#include "utility/range.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "size.hpp"

namespace candy {
namespace detail {

template <
    typename TL,
    uint32_t N,
    bool = InRange<N, 0, Size<TL>::value>::value>
struct AtT;

template <typename TL, uint32_t N>
using At = typename AtT<TL, N>::Type;

template <typename... Ts, uint32_t N>
struct AtT<Typelist<Ts...>, N, true>
{
    using Type = At<PopFront<Typelist<Ts...>>, N - 1>;
};

template <typename... Ts>
struct AtT<Typelist<Ts...>, 0, true>
{
    using Type = Front<Typelist<Ts...>>;
};

} // namespace detail

template <typename TL, uint32_t N>
using At = detail::At<TL, N>;

} // namespace candy
