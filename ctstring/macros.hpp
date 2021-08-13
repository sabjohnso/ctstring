#pragma once

//
// ... CTString header files
//
#include <ctstring/ctstring.hpp>

#define HOIST_STRING(str)                                                      \
  ::CTString::hoist([] { return ::CTString::static_string(str); })

#define CTSTRING_LITERAL(suffix)                                               \
  template<::CTString::Literal_helper str>                                     \
  constexpr auto operator""_##suffix()                                         \
  {                                                                            \
    return ::CTString::hoist(                                                  \
      [] { return ::CTString::static_string(str.value); });                    \
  }
