
#include <type_traits>
#include "typelist/replace.hpp"

namespace candy {
namespace test {
namespace {

struct FirstType;
struct SecondType;

using EmptyTL = Typelist<>;
using FirstTL = Typelist<FirstType>;
using SecondTL = Typelist<FirstType, SecondType>;
using ThirdTL = Typelist<FirstType, FirstType, SecondType>;
using FourthTL = Typelist<SecondType>;
using FifthTL = Typelist<FirstType, FirstType>;
using SixthTL = Typelist<SecondType, FirstType, SecondType>;
using SeventhTL = Typelist<SecondType, SecondType, SecondType>;

static_assert(std::is_same<Replace<EmptyTL, FirstType, SecondType>, EmptyTL>::value == true, "");
static_assert(std::is_same<Replace<FirstTL, FirstType, SecondType>, FourthTL>::value == true, "");
static_assert(std::is_same<Replace<FirstTL, SecondType, FirstType>, FirstTL>::value == true, "");
static_assert(std::is_same<Replace<SecondTL, SecondType, FirstType>, FifthTL>::value == true, "");
static_assert(std::is_same<Replace<ThirdTL, FirstType, SecondType>, SixthTL>::value == true, "");
static_assert(std::is_same<Replace<SixthTL, FirstType, SecondType>, SeventhTL>::value == true, "");

static_assert(std::is_same<ReplaceAll<EmptyTL, FirstType, SecondType>, EmptyTL>::value == true, "");
static_assert(std::is_same<ReplaceAll<FirstTL, FirstType, SecondType>, FourthTL>::value == true, "");
static_assert(std::is_same<ReplaceAll<ThirdTL, FirstType, SecondType>, SeventhTL>::value == true, "");

} // namespace
} // namespace test
} // namespace candy
