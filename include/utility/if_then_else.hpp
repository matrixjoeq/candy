
#pragma once

namespace candy {
namespace detail {

template <bool Cond, typename TrueType, typename FalseType>
struct IfThenElseT
{
    using Type = TrueType;
};

template <typename TrueType, typename FalseType>
struct IfThenElseT<false, TrueType, FalseType>
{
    using Type = FalseType;
};

} // namespace detail

template <bool Cond, typename TrueType, typename FalseType>
using IfThenElse = typename detail::IfThenElseT<Cond, TrueType, FalseType>::Type;

} // namespace candy
