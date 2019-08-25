
#pragma once

#include <stdint.h>

namespace candy {

template <int64_t N, int64_t M>
struct Equal
{
    static constexpr bool value = (N == M);
};

template <int64_t N, int64_t M>
struct NotEqual
{
    static constexpr bool value = (N != M);
};

template <int64_t N, int64_t M>
struct GreaterThan
{
    static constexpr bool value = (N > M);
};

template <int64_t N, int64_t M>
struct GreaterEqual
{
    static constexpr bool value = (N >= M);
};

template <int64_t N, int64_t M>
struct LessThan
{
    static constexpr bool value = (N < M);
};

template <int64_t N, int64_t M>
struct LessEqual
{
    static constexpr bool value = (N <= M);
};

} // namespace candy
