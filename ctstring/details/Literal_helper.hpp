#pragma once

namespace CTString::Details {
  template<typename Char, auto N>
  struct Literal_helper
  {
    static constexpr auto extent = N;

    constexpr Literal_helper(const char* cstring)
    {
      for (auto i = 0; i < N; ++i) {
        value[i] = cstring[i];
      }
    }
    Char value[N];
  };

  template<typename Char, auto N>
  Literal_helper(Char const (&)[N]) -> Literal_helper<Char, N>;
} // end of namespace CTString::Details
