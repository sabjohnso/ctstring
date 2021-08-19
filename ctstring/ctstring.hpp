#pragma once

//
// ... CTString header files
//
#include <ctstring/details/Hoist.hpp>
#include <ctstring/details/Lifted_string.hpp>
#include <ctstring/details/Literal_helper.hpp>
#include <ctstring/details/Static_string.hpp>
#include <ctstring/details/constants.hpp>

namespace CTString {
  using ::CTString::Details::hoist;
  using ::CTString::Details::lifted_string;
  using ::CTString::Details::Literal_helper;
  using ::CTString::Details::static_string;

  namespace Literals {
    template<Literal_helper str>
    constexpr auto operator""_ct()
    {
      return hoist([] { return static_string(str.value); });
    }
  } // end of namespace Literals

  namespace Constants {

    using ::CTString::Details::digits;
    using ::CTString::Details::empty;
    using ::CTString::Details::layout;
    using ::CTString::Details::lower;
    using ::CTString::Details::upper;

    using ::CTString::Details::eight;
    using ::CTString::Details::five;
    using ::CTString::Details::four;
    using ::CTString::Details::nine;
    using ::CTString::Details::one;
    using ::CTString::Details::seven;
    using ::CTString::Details::six;
    using ::CTString::Details::three;
    using ::CTString::Details::two;
    using ::CTString::Details::zero;

    using ::CTString::Details::a;
    using ::CTString::Details::b;
    using ::CTString::Details::c;
    using ::CTString::Details::d;
    using ::CTString::Details::e;
    using ::CTString::Details::f;
    using ::CTString::Details::g;
    using ::CTString::Details::h;
    using ::CTString::Details::i;
    using ::CTString::Details::j;
    using ::CTString::Details::k;
    using ::CTString::Details::l;
    using ::CTString::Details::m;
    using ::CTString::Details::n;
    using ::CTString::Details::o;
    using ::CTString::Details::p;
    using ::CTString::Details::q;
    using ::CTString::Details::r;
    using ::CTString::Details::s;
    using ::CTString::Details::t;
    using ::CTString::Details::u;
    using ::CTString::Details::v;
    using ::CTString::Details::w;
    using ::CTString::Details::x;
    using ::CTString::Details::y;
    using ::CTString::Details::z;

    using ::CTString::Details::A;
    using ::CTString::Details::B;
    using ::CTString::Details::C;
    using ::CTString::Details::D;
    using ::CTString::Details::E;
    using ::CTString::Details::F;
    using ::CTString::Details::G;
    using ::CTString::Details::H;
    using ::CTString::Details::I;
    using ::CTString::Details::J;
    using ::CTString::Details::K;
    using ::CTString::Details::L;
    using ::CTString::Details::M;
    using ::CTString::Details::N;
    using ::CTString::Details::O;
    using ::CTString::Details::P;
    using ::CTString::Details::Q;
    using ::CTString::Details::R;
    using ::CTString::Details::S;
    using ::CTString::Details::T;
    using ::CTString::Details::U;
    using ::CTString::Details::V;
    using ::CTString::Details::W;
    using ::CTString::Details::X;
    using ::CTString::Details::Y;
    using ::CTString::Details::Z;

  } // end of namespace Constants
} // end of namespace CTString
