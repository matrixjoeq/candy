
#pragma once

#include <type_traits>
#include "typelist.hpp"

namespace candy {
namespace detail {

template <typename TL>
struct EmptyT;

template <typename... Ts>
struct EmptyT<Typelist<Ts...>> : public std::false_type
{
};

template <>
struct EmptyT<Typelist<>> : public std::true_type
{
};

} // namespace detail

template <typename TL>
using Empty = detail::EmptyT<TL>;

} // namespace candy
