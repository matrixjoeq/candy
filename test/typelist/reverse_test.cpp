
#include <type_traits>
#include "typelist/reverse.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;
using ReverseTL = Typelist<SecondType, FirstType>;

static_assert(std::is_same<Reverse<EmptyTL>, EmptyTL>::value == true, "");
static_assert(std::is_same<Reverse<FirstTL>, FirstTL>::value == true, "");
static_assert(std::is_same<Reverse<SecondTL>, ReverseTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
