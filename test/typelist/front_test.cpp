
#include <type_traits>
#include "typelist/front.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;

using TL = Typelist<FirstType>;

static_assert(std::is_same<Front<TL>, FirstType>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
