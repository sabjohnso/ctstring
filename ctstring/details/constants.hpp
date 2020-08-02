#pragma once

//
// ... CTString header files
//
#include <ctstring/details/Static_string.hpp>
#include <ctstring/details/Lifted_string.hpp>


#define CTSTRING_DEFCONST(name, str)                                    \
  struct name##Holder{ static constexpr auto value = static_string(str);}; \
  constexpr auto name = lifted_string<name##Holder>
namespace CTString::Details
{

  CTSTRING_DEFCONST(empty, "");
  CTSTRING_DEFCONST(layout, " \t\n\r");
  CTSTRING_DEFCONST(digits, "0123456789");
  CTSTRING_DEFCONST(lower, "abcdefghijklmnopqrstuvwxyz");
  CTSTRING_DEFCONST(upper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");



} // end of namespace CTString::Details
