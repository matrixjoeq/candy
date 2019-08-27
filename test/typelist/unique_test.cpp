
#include <type_traits>
#include "typelist/unique.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;
struct ThirdType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType, SecondType, ThirdType>;
using SecondTL = Typelist<FirstType, SecondType, SecondType, FirstType, ThirdType>;

static_assert(std::is_same<Unique<EmptyTL>, EmptyTL>::value == true, "");
static_assert(std::is_same<Unique<SecondTL>, FirstTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
