
#include <type_traits>
#include "typelist/accumulate.hpp"
#include "typelist/push_front.hpp"

namespace candy {
namespace test {
namespace {

using EmptyTL = Typelist<>;
using TL = Typelist<int, char, bool, double>;
using AccTL = Accumulate<TL, PushFrontT, EmptyTL>;
using ExpectedTL = Typelist<double, bool, char, int>;

static_assert(std::is_same<AccTL, ExpectedTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
