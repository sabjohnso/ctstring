//
// ... Standard header files
//
#include <type_traits>

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... CTString header files
//
#include <ctstring/ctstring.hpp>
#include <ctstring/macros.hpp>

using std::is_same_v;

namespace CTString::Testing
{
  TEST(Hoist, Simple)
  {
    constexpr auto str = hoist([]{return static_string("abc123");});
    EXPECT_EQ(str.str(), "abc123");
  }

  TEST(Hoist, Macro)
  {
    constexpr auto str = HOIST_STRING("abc123");
    EXPECT_EQ(str.str(), "abc123");
  }

  TEST(Hoist, Type)
  {
    constexpr auto str1 = HOIST_STRING("abc123");
    constexpr auto str2 = HOIST_STRING("abc123");
    constexpr auto str3 = HOIST_STRING("123abc");
    EXPECT_TRUE((is_same_v<decltype(str1), decltype(str2)>));
    EXPECT_TRUE(!(is_same_v<decltype(str1), decltype(str3)>));
  }

} // end of namespace CTString::Testing
