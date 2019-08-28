
#include <type_traits>
#include "typelist/count.hpp"

namespace candy {
namespace test {
namespace {

using EmptyTL = Typelist<>;
using TL = Typelist<int, int, char, double>;

static_assert(Count<EmptyTL, int>::value == 0, "");
static_assert(Count<TL, int>::value == 2, "");
static_assert(Count<TL, bool>::value == 0, "");

template <typename T>
struct SizeLargerThanOne
{
    static constexpr bool value = (sizeof(T) > 1);
};

static_assert(CountIf<EmptyTL, SizeLargerThanOne>::value == 0, "");
static_assert(CountIf<TL, SizeLargerThanOne>::value == 3, "");

} // namespace
} // namespace test
} // namespace candy
