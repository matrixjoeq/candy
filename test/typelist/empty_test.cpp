
#include "typelist/empty.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;

using NonEmptyTL = Typelist<FirstType>;
using EmptyTL = Typelist<>;

static_assert(Empty<EmptyTL>::value == true, "");
static_assert(Empty<NonEmptyTL>::value == false, "");

} // namespace
} // namespace test
} // namespace candy
