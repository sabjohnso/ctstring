//
// ... iostream header files
//
#include <type_traits>
#include <string>
#include <iostream>
#include <sstream>

//
// ... Testing header files
//
#include <gtest/gtest.h>
//
// ... External header files
//
#include <type_utility/type_utility.hpp>

//
// ... CTString header files
//
#include <ctstring/ctstring.hpp>

namespace CTString::Testing
{
  namespace // anonymous
  {
    using namespace std::literals::string_literals;

    using std::is_same_v;
    using std::string;
    using std::ostringstream;

    using TypeUtility::nat;

    using ::CTString::static_string;

  } // end of anonymous namespace

  TEST(StaticString, ConstexprConstruction){
    constexpr auto x = static_string("x");
    static_assert(x.size() == 1);
    static_assert(x[0] == 'x');
    static_assert(x[1] == '\0');
  }

  TEST(Static_string, String){
    constexpr auto x = static_string("abc");
    static_assert(is_same_v<decltype(x.str()), string>);
    ASSERT_EQ(x.str(), "abc");
  }

  TEST(Static_string,Stream){
    constexpr auto x = static_string("abc");
    ostringstream oss;
    oss << x;
    ASSERT_EQ(oss.str(), "abc");
  }

  TEST(Static_string, ConstexprEquality){
    static_assert(static_string("abc") == static_string("abc"));
  }

  TEST(Static_string, ConstexprEqualityFail){
    static_assert(!( static_string("123") == static_string("abc")));
  }

  TEST(Static_string, ConstexprEqualityFailLength){
    static_assert(!( static_string("ab") == static_string("abc")));
  }

  TEST(Static_string, ConstexprInequality){
    static_assert(static_string("123") != static_string("abc"));
  }

  TEST(Static_string, ConstexprInequalityLength){
    static_assert(static_string("ab") != static_string("abc"));
  }

  TEST(Static_string, ConstexprInequalityFail){
    static_assert(!(static_string("abc") != static_string("abc")));
  }

  TEST(Static_string,Equality){
    ASSERT_TRUE(static_string("abc") == static_string("abc"));
  }

  TEST(Static_string,EqualityFail){
    ASSERT_TRUE(!(static_string("123") == static_string("abc")));
  }

  TEST(Static_string,EqualityFailLength){
    ASSERT_TRUE(!(static_string("ab") == static_string("abc")));
  }

  TEST(Static_string,Inequality){
    ASSERT_TRUE(static_string("123") != static_string("abc"));
  }

  TEST(Static_string,InequalityLength){
    ASSERT_TRUE(static_string("ab") != static_string("abc"));
  }

  TEST(Static_string, InEqualityFail){
    ASSERT_TRUE(!(static_string("abc") != static_string("abc")));
  }

  TEST(Static_string, StringEquality){
    ASSERT_TRUE(static_string("abc") == "abc"s);
  }

  TEST(Static_string, StringEqualityFail){
    ASSERT_FALSE(static_string("123") == "abc"s);
  }

  TEST(Static_string, StringInequality){
    ASSERT_TRUE(static_string("123") != "abc"s);
  }

  TEST(Static_string, StringInequalityFail){
    ASSERT_FALSE(static_string("abc") != "abc"s);
  }

  TEST(Static_string, Empty){
    ASSERT_EQ(static_string("").size(), 0);
  }

  TEST(Static_string, Take){
    static_assert(take(static_string("abc"), nat<2>) == static_string("ab"));
  }

  TEST(Static_string, TakeNone){
    static_assert(take(static_string("abc"), nat<0>) == static_string(""));
  }

  TEST(Static_string, TakeAll){
    static_assert(take(static_string("abc"), nat<3>) == static_string("abc"));
  }

  TEST(Static_string, TakeMore){
    static_assert(take(static_string("abc"), nat<100>) == static_string("abc"));
  }

  TEST(Static_string, Drop){
    static_assert(drop(static_string("abc"), nat<2>) == static_string("c"));
  }

  TEST(Static_string, DropNone){
    static_assert(drop(static_string("abc"), nat<0>) == static_string("abc"));
  }

  TEST(Static_string, DropAll){
    static_assert(drop(static_string("abc"), nat<3>) == static_string(""));
  }

  TEST(Static_string, DropMore){
    static_assert(drop(static_string("abc"), nat<100>) == static_string(""));
  }

  TEST(Static_string, Concat){
    static_assert( concat(static_string("abc"), static_string("123")) == static_string("abc123"));
  }

  TEST(Static_string, ConcatVariadic){
    static_assert(
      concat(static_string("abc"), static_string("def"), static_string("hij")) ==
      static_string("abcdefhij"));
  }

  TEST(Static_string, Add){
    static_assert(
      static_string("abc") + static_string("def") + static_string("hij") ==
      static_string("abcdefhij"));
  }


} // end of namespace CTString::Testing
