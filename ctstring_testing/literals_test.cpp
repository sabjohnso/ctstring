//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... CTString header files
//
#include <ctstring/macros.hpp>

namespace CTString::Testing {
  namespace // anonymous
  {
    template<Literal_helper str>
    constexpr auto operator""_test1()
    {
      return hoist([] { return static_string(str.value); });
    }

    CTSTRING_LITERAL(test2);
  } // end of anonymous namespace

  TEST(StringLiteral, Explicit)
  {
    constexpr auto x = "abc"_test1;
    EXPECT_EQ(x.str(), "abc");
  }

  TEST(StringLiteral, WithMacro)
  {
    constexpr auto x = "abc123"_test2;
    EXPECT_EQ(x.str(), "abc123");
  }

} // end of namespace CTString::Testing
