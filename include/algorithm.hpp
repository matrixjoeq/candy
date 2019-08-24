#pragma once

#include <stdint.h>
#include <cmath>
#include <type_traits>

namespace candy {

/**
 * @brief Check is number is a prime number
 * @tparam T : number type, must be an unsigned integral type
 * @param [in] number : number to be checked
 * @return true if number is a prime number, false otherwise
 */
template <
    typename T,
    typename std::enable_if<std::is_unsigned<T>::value>::type* = nullptr>
bool isPrime(T number)
{
    if (number == 0 || number == 1)
    {
        return false;
    }
    else
    {
        T divisor = 0;
        for (divisor = number / 2; number % divisor != 0; divisor--)
        {
            // do nothing
        }

        return (divisor == 1);
    }
}

} // namespace candy
