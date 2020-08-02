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

  constexpr auto zero  = take(drop(lower, idx<0>), idx<1>);
  constexpr auto one   = take(drop(lower, idx<1>), idx<1>);
  constexpr auto two   = take(drop(lower, idx<2>), idx<1>);
  constexpr auto three = take(drop(lower, idx<3>), idx<1>);
  constexpr auto four  = take(drop(lower, idx<4>), idx<1>);
  constexpr auto five  = take(drop(lower, idx<5>), idx<1>);
  constexpr auto six   = take(drop(lower, idx<6>), idx<1>);
  constexpr auto seven = take(drop(lower, idx<7>), idx<1>);
  constexpr auto eight = take(drop(lower, idx<8>), idx<1>);
  constexpr auto nine  = take(drop(lower, idx<9>), idx<1>);

  constexpr auto a = take( drop(lower, idx<0>),  idx<1>);
  constexpr auto b = take( drop(lower, idx<1>),  idx<1>);
  constexpr auto c = take( drop(lower, idx<2>),  idx<1>);
  constexpr auto d = take( drop(lower, idx<3>),  idx<1>);
  constexpr auto e = take( drop(lower, idx<4>),  idx<1>);
  constexpr auto f = take( drop(lower, idx<5>),  idx<1>);
  constexpr auto g = take( drop(lower, idx<6>),  idx<1>);
  constexpr auto h = take( drop(lower, idx<7>),  idx<1>);
  constexpr auto i = take( drop(lower, idx<8>),  idx<1>);
  constexpr auto j = take( drop(lower, idx<9>),  idx<1>);
  constexpr auto k = take( drop(lower, idx<10>), idx<1>);
  constexpr auto l = take( drop(lower, idx<11>), idx<1>);
  constexpr auto m = take( drop(lower, idx<12>), idx<1>);
  constexpr auto n = take( drop(lower, idx<13>), idx<1>);
  constexpr auto o = take( drop(lower, idx<14>), idx<1>);
  constexpr auto p = take( drop(lower, idx<15>), idx<1>);
  constexpr auto q = take( drop(lower, idx<16>), idx<1>);
  constexpr auto r = take( drop(lower, idx<17>), idx<1>);
  constexpr auto s = take( drop(lower, idx<18>), idx<1>);
  constexpr auto t = take( drop(lower, idx<19>), idx<1>);
  constexpr auto u = take( drop(lower, idx<20>), idx<1>);
  constexpr auto v = take( drop(lower, idx<21>), idx<1>);
  constexpr auto w = take( drop(lower, idx<22>), idx<1>);
  constexpr auto x = take( drop(lower, idx<23>), idx<1>);
  constexpr auto y = take( drop(lower, idx<24>), idx<1>);
  constexpr auto z = take( drop(lower, idx<25>), idx<1>);

  constexpr auto A = take( drop(upper, idx<0>),  idx<1>);
  constexpr auto B = take( drop(upper, idx<1>),  idx<1>);
  constexpr auto C = take( drop(upper, idx<2>),  idx<1>);
  constexpr auto D = take( drop(upper, idx<3>),  idx<1>);
  constexpr auto E = take( drop(upper, idx<4>),  idx<1>);
  constexpr auto F = take( drop(upper, idx<5>),  idx<1>);
  constexpr auto G = take( drop(upper, idx<6>),  idx<1>);
  constexpr auto H = take( drop(upper, idx<7>),  idx<1>);
  constexpr auto I = take( drop(upper, idx<8>),  idx<1>);
  constexpr auto J = take( drop(upper, idx<9>),  idx<1>);
  constexpr auto K = take( drop(upper, idx<10>), idx<1>);
  constexpr auto L = take( drop(upper, idx<11>), idx<1>);
  constexpr auto M = take( drop(upper, idx<12>), idx<1>);
  constexpr auto N = take( drop(upper, idx<13>), idx<1>);
  constexpr auto O = take( drop(upper, idx<14>), idx<1>);
  constexpr auto P = take( drop(upper, idx<15>), idx<1>);
  constexpr auto Q = take( drop(upper, idx<16>), idx<1>);
  constexpr auto R = take( drop(upper, idx<17>), idx<1>);
  constexpr auto S = take( drop(upper, idx<18>), idx<1>);
  constexpr auto T = take( drop(upper, idx<19>), idx<1>);
  constexpr auto U = take( drop(upper, idx<20>), idx<1>);
  constexpr auto V = take( drop(upper, idx<21>), idx<1>);
  constexpr auto W = take( drop(upper, idx<22>), idx<1>);
  constexpr auto X = take( drop(upper, idx<23>), idx<1>);
  constexpr auto Y = take( drop(upper, idx<24>), idx<1>);
  constexpr auto Z = take( drop(upper, idx<25>), idx<1>);

} // end of namespace CTString::Details
