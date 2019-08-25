
#include <type_traits>
#include "typelist.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<SecondType, FirstType>;

static_assert(std::is_same<PushFront<EmptyTL, FirstType>, FirstTL>::value == true, "");
static_assert(std::is_same<PushFront<FirstTL, SecondType>, SecondTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
