
#pragma once

#include <stdint.h>
#include "utility/range.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"
#include "size.hpp"

namespace candy {
namespace detail {

template <typename TL, uint32_t N, bool = InRange<N, 0, Size<TL>::value>::value>
struct EraseT;

template <typename TL, uint32_t N>
using Erase = typename EraseT<TL, N>::Type;

template <typename TL, uint32_t N>
struct EraseT<TL, N, true> : public PushFrontT<Erase<PopFront<TL>, N - 1>, Front<TL>>
{
};

template <typename TL>
struct EraseT<TL, 0, true> : public PopFrontT<TL>
{
};

} // namespace detail

template <typename TL, uint32_t N>
using Erase = detail::Erase<TL, N>;

} // namespace candy
