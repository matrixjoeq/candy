
#include <type_traits>
#include "typelist/erase.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;
using ThirdTL = Typelist<SecondType>;

static_assert(std::is_same<Erase<FirstTL, 0>, EmptyTL>::value == true, "");
static_assert(std::is_same<Erase<SecondTL, 0>, ThirdTL>::value == true, "");
static_assert(std::is_same<Erase<SecondTL, 1>, FirstTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
