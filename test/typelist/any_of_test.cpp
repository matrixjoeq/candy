
#include <type_traits>
#include <string>
#include "typelist/any_of.hpp"

namespace candy {
namespace test {
namespace {

using TrivialTL = Typelist<int, char, bool, double>;
using NonTrivialTL = Typelist<std::string>;

static_assert(AnyOf<TrivialTL, std::is_trivial>::value == true, "");
static_assert(AnyOf<NonTrivialTL, std::is_trivial>::value == false, "");

} // namespace
} // namespace test
} // namespace candy
