#pragma once

//
// ... Standard header files
//
#include <cstdint>
#include <type_traits>
#include <array>
#include <string>
#include <iostream>
#include <stdexcept>
#include <iterator>


//
// ... External header files
//
#include <type_utility/type_utility.hpp>

namespace CTString::Details
{
  using std::integral_constant;
  using std::extent_v;
  using std::remove_all_extents_t;

  using integer = std::ptrdiff_t;


  template<integer I>
  using Idx = integral_constant<integer, I>;

  template<integer I>
  constexpr Idx<I> idx{};

  using std::integer_sequence;
  using std::index_sequence;

  using std::array;
  using std::string;
  using std::ostream;

  using std::next;
  using std::prev;

  using std::out_of_range;

  using TypeUtility::Type;
  using TypeUtility::type_count;
  using TypeUtility::count_args;
  using TypeUtility::generate_indices;
  using TypeUtility::nat;
  using TypeUtility::Nat;





} // end of namespace CTString::Details
