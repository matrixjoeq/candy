
#pragma once

namespace candy {

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

template <bool Cond, typename TrueType, typename FalseType>
using IfThenElse = typename IfThenElseT<Cond, TrueType, FalseType>::Type;

} // namespace candy
