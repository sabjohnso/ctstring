#pragma once

namespace CTString::Details {
  template<typename Char, size_type N>
  struct Literal_helper
  {
    static constexpr auto extent = N;

    constexpr Literal_helper(const Char* cstring)
    {
      for (size_type i = 0u; i < N; ++i) {
        value[i] = cstring[i];
      }
    }
    Char value[N];
  };

  template<typename Char, size_type N>
  Literal_helper(Char const (&)[N]) -> Literal_helper<Char, N>;
} // end of namespace CTString::Details
