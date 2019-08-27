
#include <type_traits>
#include "typelist/at.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;

static_assert(std::is_same<At<FirstTL, 0>, FirstType>::value == true, "");
static_assert(std::is_same<At<SecondTL, 1>, SecondType>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
