
#pragma once

#include <type_traits>
#include "typelist.hpp"

namespace candy {

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

template <typename TL>
using Empty = EmptyT<TL>;

} // namespace candy
