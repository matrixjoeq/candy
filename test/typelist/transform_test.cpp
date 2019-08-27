
#include <type_traits>
#include "typelist/transform.hpp"

namespace candy {
namespace test {
namespace {

template <typename T>
struct AddConst
{
    using Type = T const;
};

using TL = Typelist<int, char, short, double>;
using TransformedTL = Transform<TL, AddConst>;
using ExpectedTL = Typelist<int const, char const, short const, double const>;

static_assert(std::is_same<TransformedTL, ExpectedTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
