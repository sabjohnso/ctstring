#pragma once

//
// ... CTString header files
//
#include <ctstring/details/Lifted_string.hpp>
#include <ctstring/details/import.hpp>

namespace CTString::Details {
  template<typename F>
  class Hoist {
    struct Holder {
      static constexpr auto value = F()();
    };

  public:
    static constexpr auto value = lifted_string<Holder>;
  }; // end of class Hoist

  template<typename F>
  constexpr auto
  hoist(F&&) {
    return Hoist<decay_t<F>>::value;
  }

} // end of namespace CTString::Details
