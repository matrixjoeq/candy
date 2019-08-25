
#pragma once

#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"
#include "remove.hpp"

namespace candy {
namespace detail {

template <typename TL>
struct UniqueT;

template <typename TL>
using Unique = typename UniqueT<TL>::Type;

template <>
struct UniqueT<Typelist<>>
{
    using Type = Typelist<>;
};

template <typename... Ts>
struct UniqueT<Typelist<Ts...>>
{
private:
    using TL = Typelist<Ts...>;
    using Tail = PopFront<TL>;
    using Head = Front<TL>;

public:
    using Type = PushFront<Remove<Unique<Tail>, Head>, Head>;
};

} // namespace detail

template <typename TL>
using Unique = detail::Unique<TL>;

} // namespace candy
