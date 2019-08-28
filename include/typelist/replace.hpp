
#pragma once

#include <type_traits>
#include "utility/if_then_else.hpp"
#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"

namespace candy {

template <typename TL, typename T, typename U, bool = Empty<TL>::value>
struct ReplaceT;

template <typename TL, typename T, typename U>
using Replace = typename ReplaceT<TL, T, U>::Type;

template <typename TL, typename T, typename U>
struct ReplaceT<TL, T, U, true>
{
    using Type = TL;
};

template <typename TL, typename T, typename U>
struct ReplaceT<TL, T, U, false>
{
    using Type = IfThenElse<std::is_same<Front<TL>, T>::value,
                            PushFront<PopFront<TL>, U>,
                            PushFront<Replace<PopFront<TL>, T, U>, Front<TL>>>;
};

template <typename TL, typename T, typename U, bool = Empty<TL>::value>
struct ReplaceAllT;

template <typename TL, typename T, typename U>
using ReplaceAll = typename ReplaceAllT<TL, T, U>::Type;

template <typename TL, typename T, typename U>
struct ReplaceAllT<TL, T, U, true>
{
    using Type = TL;
};

#if 0
// FIXME : why this doesn't work
template <typename TL, typename T, typename U>
struct ReplaceAllT<TL, T, U, false>
{
    using Type = IfThenElse<std::is_same<Front<TL>, T>::value,
                            ReplaceAll<PushFront<PopFront<TL>, U>, T, U>,
                            PushFront<ReplaceAll<PopFront<TL>, T, U>, Front<TL>>>;
};
#else
template <typename... Ts, typename T, typename U>
struct ReplaceAllT<Typelist<T, Ts...>, T, U, false>
{
private:
    using TL = Typelist<T, Ts...>;

public:
    using Type = ReplaceAll<PushFront<PopFront<TL>, U>, T, U>;
};

template <typename... Ts, typename T, typename U>
struct ReplaceAllT<Typelist<Ts...>, T, U, false>
{
private:
    using TL = Typelist<Ts...>;

public:
    using Type = PushFront<ReplaceAll<PopFront<TL>, T, U>, Front<TL>>;
};
#endif

} // namespace candy
