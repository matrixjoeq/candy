
#include <type_traits>
#include <string>
#include "typelist/all_of.hpp"

namespace candy {
namespace test {
namespace {

using TrivialTL = Typelist<int, char, bool, double>;
using NonTrivialTL = Typelist<int, char, bool, std::string>;

static_assert(AllOf<TrivialTL, std::is_trivial>::value == true, "");
static_assert(AllOf<NonTrivialTL, std::is_trivial>::value == false, "");

} // namespace
} // namespace test
} // namespace candy
