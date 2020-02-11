#pragma once

#include <utility>
#include "portable/cxx.hpp"
#include "utility/type.hpp"
#include "utility/owner.hpp"
#include "typelist/typelist.hpp"
#include "design_pattern/hierarchy.hpp"

namespace candy {

template <typename T, template <class> class Owner>
class AbstractFactoryUnit
{
public:
    virtual ~AbstractFactoryUnit() = default;
    virtual Owner<T> create(Identity<T>) = 0;
};

template <typename T>
using DefaultAFUnit = AbstractFactoryUnit<T, UniquePtr>;

template <class TList, template <class> class Unit = DefaultAFUnit>
class AbstractFactory
    : public GenScatterHierarchy<TList, Unit>
{
public:
    template <typename T>
    auto create() -> ResultOf<decltype(&Unit<T>::create)(Unit<T>, Identity<T>)>
    {
        Unit<T>& self = *this;
        return self.create(Identity<T>());
    }
};

template <typename...  Ts>
using VarAbstractFactory = AbstractFactory<Typelist<Ts...>>;

} // namespace candy
