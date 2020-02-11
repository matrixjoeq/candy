
#pragma once

#include <functional>
#include <map>
#include <utility>
#include "utility/owner.hpp"

namespace candy {

template <
    typename Product,
    template <typename> class Owner,
    typename... Args
>
class Factory
{
public:
    using owner_type = Owner<Product>;
    using identifier = void;

public:
    virtual ~Factory() = default;
    virtual owner_type create(Args&&... args) = 0;
};

template <typename Product, typename... Args>
using UniqueFactory = Factory<Product, UniquePtr, Args...>;

template <
    typename Factory,
    typename T
>
class SimpleFactory : public Factory
{
public:
    using OwnerType = typename Factory::owner_type;

    OwnerType create() override
    {
        return OwnerType(new T);
    }
};

template <
    typename Product,
    template <typename> class Owner,
    typename ProductIdentifier,
    typename... Args
>
class ParamFactory
{
public:
    using owner_type = Owner<Product>;
    using identifier = ProductIdentifier;

public:
    virtual ~ParamFactory() = default;
    virtual Owner<Product> create(const ProductIdentifier& id, Args&&... args) = 0;
};

template <typename Product, typename ProductIdentifier, typename... Args>
using UniqueParamFactory = ParamFactory<Product, UniquePtr, ProductIdentifier, Args...>;

template <typename Key, typename T>
using DefaultContainer = std::map<Key, T>;

template <
    typename Factory,
    template <typename, typename> class AssociativeContainer = DefaultContainer
>
class ScalableFactory : public Factory
{
public:
    using ProductIdentifier = typename Factory::identifier;
    using OwnerType = typename Factory::owner_type;
    using Creator = std::function<OwnerType()>;

    static bool registerType(const ProductIdentifier& id, Creator creator)
    {
        using ValueType = typename Container::value_type;
        return registration_.insert(ValueType(id, creator)).second;
    }

    OwnerType create(const ProductIdentifier& id) override
    {
        const auto creator = registration_.find(id);
        if (creator == registration_.end())
        {
            return nullptr;
        }
        else
        {
            return (creator->second)();
        }
    }

private:
    using Container = AssociativeContainer<ProductIdentifier, Creator>;
    static Container registration_;
};

template <
    typename Factory,
    template <typename, typename> class AssociativeContainer
>
typename ScalableFactory<Factory, AssociativeContainer>::Container
ScalableFactory<Factory, AssociativeContainer>::registration_;

template <typename T, typename Factory, int32_t Id>
class SelfRegistration
{
protected:
    using OwnerType = typename Factory::OwnerType;

    static OwnerType create()
    {
        return OwnerType(new T);
    }

    static bool registered_;

protected:
    SelfRegistration()
    {
        (void)registered_;
    }
};

template <typename T, typename Factory, int32_t Id>
bool SelfRegistration<T, Factory, Id>::registered_ =
    Factory::registerType(
        static_cast<typename Factory::identifier>(Id),
        &SelfRegistration<T, Factory, Id>::create);

} // namespace candy