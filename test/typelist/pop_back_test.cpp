
#include <type_traits>
#include "typelist.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;

static_assert(std::is_same<PopBack<SecondTL>, FirstTL>::value == true, "");
static_assert(std::is_same<PopBack<FirstTL>, EmptyTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
