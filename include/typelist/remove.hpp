
#pragma once

#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"

namespace candy {
namespace detail {

template <typename TL, typename T>
struct RemoveT;

template <typename TL, typename T>
using Remove = typename RemoveT<TL, T>::Type;

template <typename T>
struct RemoveT<Typelist<>, T>
{
    using Type = Typelist<>;
};

template <typename... Ts, typename T>
struct RemoveT<Typelist<T, Ts...>, T>
{
    using Type = Typelist<Ts...>;
};

template <typename... Ts, typename T>
struct RemoveT<Typelist<Ts...>, T>
{
private:
    using TL = Typelist<Ts...>;

public:
    using Type = PushFront<Remove<PopFront<TL>, T>, Front<TL>>;
};

template <typename TL, typename T>
struct RemoveAllT;

template <typename TL, typename T>
using RemoveAll = typename RemoveAllT<TL, T>::Type;

template <typename T>
struct RemoveAllT<Typelist<>, T>
{
    using Type = Typelist<>;
};

template <typename... Ts, typename T>
struct RemoveAllT<Typelist<T, Ts...>, T>
{
    using Type = RemoveAll<Typelist<Ts...>, T>;
};

template <typename... Ts, typename T>
struct RemoveAllT<Typelist<Ts...>, T>
{
private:
    using TL = Typelist<Ts...>;

public:
    using Type = PushFront<RemoveAll<PopFront<TL>, T>, Front<TL>>;
};

} // namespace detail

template <typename TL, typename T>
using Remove = detail::Remove<TL, T>;

template <typename TL, typename T>
using RemoveAll = detail::RemoveAll<TL, T>;

} // namespace candy
