
#include <type_traits>
#include "typelist/insert.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;
struct ThirdType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;
using ThirdTL = Typelist<SecondType, FirstType>;
using FourthTL = Typelist<FirstType, ThirdType, SecondType>;

static_assert(std::is_same<Insert<EmptyTL, FirstType, 0>, FirstTL>::value == true, "");
static_assert(std::is_same<Insert<FirstTL, SecondType, 1>, SecondTL>::value == true, "");
static_assert(std::is_same<Insert<FirstTL, SecondType, 0>, ThirdTL>::value == true, "");
static_assert(std::is_same<Insert<SecondTL, ThirdType, 1>, FourthTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
