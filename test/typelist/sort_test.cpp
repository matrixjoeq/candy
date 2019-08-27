
#include <type_traits>
#include "typelist/sort.hpp"

namespace candy {
namespace test {
namespace {

template <typename T, typename U>
struct SmallerThanT
{
    static constexpr bool value = sizeof(T) < sizeof(U);
};

using TL = Typelist<int, char, short, double>;
using ExpectedTL = Typelist<char, short, int, double>;
using SortedTL = Sort<TL, SmallerThanT>;

static_assert(std::is_same<SortedTL, ExpectedTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
