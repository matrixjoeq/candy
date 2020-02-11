#pragma once

#include <memory>
#include <type_traits>
#include "portable/cxx.hpp"

namespace candy {

template <
    typename T,
    typename = EnableIf<isPointer<T>()>
>
using owner_t = T;

template <typename T>
using OwnerPtr = owner_t<T*>;

template <typename T>
using UniquePtr = std::unique_ptr<T>;

} // namespace candy