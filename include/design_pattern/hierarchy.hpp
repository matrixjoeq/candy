#pragma once

#include "typelist/typelist.hpp"
#include "typelist/front.hpp"
#include "typelist/pop_front.hpp"

namespace candy {

template <class TList, template <class> class Unit>
class GenScatterHierarchy;

template <class... Ts, template <class> class Unit>
class GenScatterHierarchy<Typelist<Ts...>, Unit>
    : public Unit<Front<Typelist<Ts...>>>
    , public GenScatterHierarchy<PopFront<Typelist<Ts...>>, Unit>
{

};

template <template <class> class Unit>
class GenScatterHierarchy<Typelist<>, Unit>
{

};

} // namespace candy
