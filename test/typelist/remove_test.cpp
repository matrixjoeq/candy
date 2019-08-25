
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
using ThirdTL = Typelist<FirstType, FirstType, SecondType>;
using FourthTL = Typelist<SecondType>;

static_assert(std::is_same<Remove<EmptyTL, FirstType>, EmptyTL>::value == true, "");
static_assert(std::is_same<Remove<FirstTL, FirstType>, EmptyTL>::value == true, "");
static_assert(std::is_same<Remove<FirstTL, SecondType>, FirstTL>::value == true, "");
static_assert(std::is_same<Remove<SecondTL, SecondType>, FirstTL>::value == true, "");
static_assert(std::is_same<Remove<ThirdTL, FirstType>, SecondTL>::value == true, "");

static_assert(std::is_same<RemoveAll<EmptyTL, FirstType>, EmptyTL>::value == true, "");
static_assert(std::is_same<RemoveAll<FirstTL, SecondType>, FirstTL>::value == true, "");
static_assert(std::is_same<RemoveAll<ThirdTL, FirstType>, FourthTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
