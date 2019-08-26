
#pragma once

#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"

namespace candy {
namespace detail {

template <typename TL, typename T, typename U>
struct ReplaceT;

template <typename TL, typename T, typename U>
using Replace = typename ReplaceT<TL, T, U>::Type;

template <typename T, typename U>
struct ReplaceT<Typelist<>, T, U>
{
    using Type = Typelist<>;
};

template <typename... Ts, typename T, typename U>
struct ReplaceT<Typelist<T, Ts...>, T, U>
{
    using Type = Typelist<U, Ts...>;
};

template <typename... Ts, typename T, typename U>
struct ReplaceT<Typelist<Ts...>, T, U>
{
private:
    using TL = Typelist<Ts...>;

public:
    using Type = PushFront<Replace<PopFront<TL>, T, U>, Front<TL>>;
};

template <typename TL, typename T, typename U>
struct ReplaceAllT;

template <typename TL, typename T, typename U>
using ReplaceAll = typename ReplaceAllT<TL, T, U>::Type;

template <typename T, typename U>
struct ReplaceAllT<Typelist<>, T, U>
{
    using Type = Typelist<>;
};

template <typename... Ts, typename T, typename U>
struct ReplaceAllT<Typelist<T, Ts...>, T, U>
{
    using Type = ReplaceAll<Typelist<U, Ts...>, T, U>;
};

template <typename... Ts, typename T, typename U>
struct ReplaceAllT<Typelist<Ts...>, T, U>
{
private:
    using TL = Typelist<Ts...>;

public:
    using Type = PushFront<ReplaceAll<PopFront<TL>, T, U>, Front<TL>>;
};

} // namespace detail

template <typename TL, typename T, typename U>
using Replace = detail::Replace<TL, T, U>;

template <typename TL, typename T, typename U>
using ReplaceAll = detail::ReplaceAll<TL, T, U>;

} // namespace candy
