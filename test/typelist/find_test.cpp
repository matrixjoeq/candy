
#include <type_traits>
#include "typelist/find.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;

static_assert(Find<EmptyTL, FirstType>::value == -1, "");
static_assert(Find<FirstTL, FirstType>::value == 0, "");
static_assert(Find<FirstTL, SecondType>::value == -1, "");
static_assert(Find<SecondTL, FirstType>::value == 0, "");
static_assert(Find<SecondTL, SecondType>::value == 1, "");

} // namespace
} // namespace test
} // namespace candy
