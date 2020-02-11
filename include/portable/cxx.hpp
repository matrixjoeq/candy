#pragma once

#include <type_traits>

namespace candy {

template <bool B, class T = void>
using EnableIf = typename std::enable_if<B, T>::type;

template <class F, class... Args>
using ResultOf = typename std::result_of<F(Args...)>::type;

template <class Base, class Derived>
inline constexpr bool isBaseOf()
{
    return std::is_base_of<Base, Derived>::value;
}

template <class T>
inline constexpr bool isPointer()
{
    return std::is_pointer<T>::value;
}

} // namespace candy
