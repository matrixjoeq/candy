
#pragma once

#include "utility/if_then_else.hpp"
#include "utility/type.hpp"
#include "empty.hpp"
#include "front.hpp"
#include "pop_front.hpp"
#include "push_front.hpp"

namespace candy {
namespace detail {

template <
    typename TL,
    typename E,
    template <typename T, typename U> class Compare,
    bool = Empty<TL>::value>
struct InsertSortedT;

template <
    typename TL,
    typename E,
    template <typename T, typename U> class Compare>
using InsertSorted = typename InsertSortedT<TL, E, Compare>::Type;

template <
    typename TL,
    typename E,
    template <typename T, typename U> class Compare>
struct InsertSortedT<TL, E, Compare, false>
{
private:
    using Tail = IfThenElse<Compare<E, Front<TL>>::value,
                            Identity<TL>,
                            InsertSorted<PopFront<TL>, E, Compare>>;

    using Head = IfThenElse<Compare<E, Front<TL>>::value,
                            E,
                            Front<TL>>;

public:
    using Type = PushFront<Tail, Head>;
};

template <
    typename TL,
    typename E,
    template <typename T, typename U> class Compare>
struct InsertSortedT<TL, E, Compare, true>
{
    using Type = PushFront<TL, E>;
};

template <
    typename TL,
    template <typename T, typename U> class Compare,
    bool = Empty<TL>::value>
struct InsertionSortT;

template <
    typename TL,
    template <typename T, typename U> class Compare>
using InsertionSort = typename InsertionSortT<TL, Compare>::Type;

template <
    typename TL,
    template <typename T, typename U> class Compare>
struct InsertionSortT<TL, Compare, false>
{
    using Type = InsertSorted<InsertionSort<PopFront<TL>, Compare>, Front<TL>, Compare>;
};

template <
    typename TL,
    template <typename T, typename U> class Compare>
struct InsertionSortT<TL, Compare, true>
{
    using Type = TL;
};

} // namespace detail

template <typename TL, template <typename T, typename U> class Compare>
using Sort = detail::InsertionSort<TL, Compare>;

} // namespace candy
