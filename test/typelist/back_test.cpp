
#include <type_traits>
#include "typelist/back.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;

using TL = Typelist<FirstType>;

static_assert(std::is_same<Back<TL>, FirstType>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
