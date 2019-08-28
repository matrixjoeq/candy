
#include <type_traits>
#include "typelist/concat.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<SecondType>;
using ThirdTL = Typelist<FirstType, SecondType>;

static_assert(std::is_same<Concat<EmptyTL, EmptyTL>, EmptyTL>::value == true, "");
static_assert(std::is_same<Concat<EmptyTL, FirstTL>, FirstTL>::value == true, "");
static_assert(std::is_same<Concat<FirstTL, EmptyTL>, FirstTL>::value == true, "");
static_assert(std::is_same<Concat<FirstTL, SecondTL>, ThirdTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
