
#pragma once

#include <stdint.h>
#include <type_traits>

namespace candy {
namespace detail {

template <int64_t N, int64_t Min, int64_t Max, bool>
struct InRangeImpl;

template <int64_t N, int64_t Min, int64_t Max>
struct InRangeImpl<N, Min, Max, true>
    : public std::true_type
{
};

template <int64_t N, int64_t Min, int64_t Max>
struct InRangeImpl<N, Min, Max, false>
    : public std::false_type
{
};

} // namespace detail

struct RangeCheckPolicy
{
    struct IncludeMin;
    struct IncludeMax;
    struct IncludeMinMax;
    struct NoInclude;
};

template <
    int64_t N,
    int64_t Min,
    int64_t Max,
    typename = RangeCheckPolicy::IncludeMin>
struct InRange;

template <int64_t N, int64_t Min, int64_t Max>
struct InRange<N, Min, Max, RangeCheckPolicy::IncludeMin>
    : public detail::InRangeImpl<N, Min, Max, GreaterEqual<N, Min>::value && LessThan<N, Max>::value>
{
};

template <int64_t N, int64_t Min, int64_t Max>
struct InRange<N, Min, Max, RangeCheckPolicy::IncludeMax>
    : public detail::InRangeImpl<N, Min, Max, GreaterThan<N, Min>::value && LessEqual<N, Max>::value>
{
};

template <int64_t N, int64_t Min, int64_t Max>
struct InRange<N, Min, Max, RangeCheckPolicy::IncludeMinMax>
    : public detail::InRangeImpl<N, Min, Max, GreaterEqual<N, Min>::value && LessEqual<N, Max>::value>
{
};

template <int64_t N, int64_t Min, int64_t Max>
struct InRange<N, Min, Max, RangeCheckPolicy::NoInclude>
    : public detail::InRangeImpl<N, Min, Max, GreaterThan<N, Min>::value && LessThan<N, Max>::value>
{
};

} // namespace candy
