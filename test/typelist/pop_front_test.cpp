
#include <type_traits>
#include "typelist/pop_front.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<SecondType, FirstType>;

static_assert(std::is_same<PopFront<SecondTL>, FirstTL>::value == true, "");
static_assert(std::is_same<PopFront<FirstTL>, EmptyTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
