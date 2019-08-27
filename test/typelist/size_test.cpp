
#include <type_traits>
#include "typelist/size.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;

static_assert(Size<EmptyTL>::value == 0, "");
static_assert(Size<FirstTL>::value == 1, "");
static_assert(Size<SecondTL>::value == 2, "");

} // namespace
} // namespace test
} // namespace candy
