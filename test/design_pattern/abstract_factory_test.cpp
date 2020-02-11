
#include "portable/cxx.hpp"
#include "design_pattern/abstract_factory.hpp"

class BaseA
{
public:
    virtual ~BaseA() = default;
};

class BaseB
{
public:
    virtual ~BaseB() = default;
};

using Factory = candy::VarAbstractFactory<BaseA, BaseB>;

static_assert(candy::isBaseOf<candy::DefaultAFUnit<BaseA>, Factory>(), "");
static_assert(candy::isBaseOf<candy::DefaultAFUnit<BaseB>, Factory>(), "");

int main(int argc, char* argv[])
{
    return 0;
}
