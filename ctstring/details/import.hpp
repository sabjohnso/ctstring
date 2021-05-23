#pragma once

//
// ... Standard header files
//
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <type_traits>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>

namespace CTString::Details {
  using std::decay_t;
  using std::extent_v;
  using std::integral_constant;
  using std::remove_all_extents_t;

  using integer = std::ptrdiff_t;

  template<integer I>
  using Idx = integral_constant<integer, I>;

  template<integer I>
  constexpr Idx<I> idx{};

  using std::index_sequence;
  using std::integer_sequence;

  using std::array;
  using std::ostream;
  using std::string;

  using std::next;
  using std::prev;

  using std::out_of_range;

  using TypeUtility::count_args;
  using TypeUtility::generate_indices;
  using TypeUtility::nat;
  using TypeUtility::Nat;
  using TypeUtility::Type;
  using TypeUtility::type_count;

} // end of namespace CTString::Details
