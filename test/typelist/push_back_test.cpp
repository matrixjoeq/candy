
#include <type_traits>
#include "typelist/push_back.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;

static_assert(std::is_same<PushBack<EmptyTL, FirstType>, FirstTL>::value == true, "");
static_assert(std::is_same<PushBack<FirstTL, SecondType>, SecondTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
