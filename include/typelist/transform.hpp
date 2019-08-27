
#pragma once

#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"

namespace candy {
namespace detail {

template <
    typename TL,
    template <typename T> class MetaFunc,
    bool = Empty<TL>::value>
struct TransformT;

template <
    typename TL,
    template <typename T> class MetaFunc>
using Transform = typename TransformT<TL, MetaFunc>::Type;

template <
    typename TL,
    template <typename T> class MetaFunc>
struct TransformT<TL, MetaFunc, false>
{
    using Type = PushFront<Transform<PopFront<TL>, MetaFunc>,
                           typename MetaFunc<Front<TL>>::Type>;
};

template <
    typename TL,
    template <typename T> class MetaFunc>
struct TransformT<TL, MetaFunc, true>
{
    using Type = Typelist<>;
};

} // namespace detail

template <
    typename TL,
    template <typename T> class MetaFunc>
using Transform = detail::Transform<TL, MetaFunc>;

} // namespace candy
