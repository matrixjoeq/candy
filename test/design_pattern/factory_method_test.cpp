
#include <assert.h>
#include "design_pattern.hpp"

struct Base
{
    virtual ~Base() = default;
};

struct Derived : Base
{
};

using Factory = candy::UniqueFactory<Base>;
using SimpleFactory = candy::SimpleFactory<Factory, Derived>;

void testSimpleFactory()
{
    SimpleFactory factory;
    auto obj = factory.create();
    assert(obj != nullptr);
}

enum eProductId
{
    kCommon = 0
};

using ParamFactory = candy::UniqueParamFactory<Base, eProductId>;
using ScalableFactory = candy::ScalableFactory<ParamFactory>;

struct CommonDerived
    : Base
    , private candy::SelfRegistration<
        CommonDerived, ScalableFactory, eProductId::kCommon>
{
private:
    using Delegate = candy::SelfRegistration<
        CommonDerived, ScalableFactory, eProductId::kCommon>;
    friend Delegate;

protected:
    CommonDerived()
    {
    }
};

void testScalableFactory()
{
    ScalableFactory factory;
    auto obj = factory.create(eProductId::kCommon);
    assert(obj != nullptr);
}

int main(int argc, char* argv[])
{
    testSimpleFactory();
    testScalableFactory();

    return 0;
}