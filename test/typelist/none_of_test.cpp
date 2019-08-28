
#include <type_traits>
#include <string>
#include "typelist/none_of.hpp"

namespace candy {
namespace test {
namespace {

using TrivialTL = Typelist<int, char, bool, double>;
using NonTrivialTL = Typelist<std::string>;

static_assert(NoneOf<TrivialTL, std::is_trivial>::value == false, "");
static_assert(NoneOf<NonTrivialTL, std::is_trivial>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
