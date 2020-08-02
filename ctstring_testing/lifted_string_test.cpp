//
// ... Standard header files
//
#include <iostream>
#include <string>
#include <type_traits>

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
    using std::is_same_v;
    using TypeUtility::type;
    using TypeUtility::nat;
    using CTString::static_string;
    using namespace std::literals::string_literals;
  } // end of anonymous namespace

  namespace LiftedStringConstruction
  {
    struct Holder{ static constexpr auto value = static_string("abc"); };
    TEST(LiftedString,Construction){
      constexpr auto str = lifted_string<Holder>;
      static_assert(str == Holder::value);
      ASSERT_TRUE(str == Holder::value);
      ASSERT_TRUE(str.str() == "abc"s);
    }
  } // end of namespace LiftedStringConstruction

  namespace LiftedStringManip
  {
    struct Holder0{ static constexpr auto value = static_string("abc123"); };
    struct Holder1{ static constexpr auto value = static_string("abc123"); };
    struct Holder2{ static constexpr auto value = static_string("abc"); };
    struct Holder3{ static constexpr auto value = static_string("123"); };
    TEST(LiftedString,Manip){
      constexpr auto s0 = lifted_string<Holder0>;
      constexpr auto s1 = lifted_string<Holder1>;
      constexpr auto s2 = lifted_string<Holder2>;
      constexpr auto s3 = lifted_string<Holder3>;

      static_assert(is_same_v<decltype(s0), decltype(s1)>);
      static_assert(s0 == s1);

      static_assert(s2 == take(s1, nat<3>));
      static_assert(s3 == drop(s1, nat<3>));
      static_assert(s1 == take(s1, nat<3>) + drop(s1, nat<3>));





    }


  } // end of namespace LiftedStringManip

} // end of namespace CTString::Testing
