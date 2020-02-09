#pragma once

#if defined(__GNUC__) && !defined(COMPILER_ICC)
#  define CANDY_ATTRIBUTE_UNUSED __attribute__ ((unused))
#elif defined(__clang__)
#  if __has_attribute(unused)
#    define CANDY_ATTRIBUTE_UNUSED __attribute__ ((unused))
#  endif
#endif

#ifndef CANDY_ATTRIBUTE_UNUSED
#  define CANDY_ATTRIBUTE_UNUSED
#endif
