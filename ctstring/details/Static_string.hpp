#pragma once

//
// ... CTString header files
//
#include <ctstring/details/Lifted_string_fwd.hpp>
#include <ctstring/details/import.hpp>

namespace CTString::Details {

  template<typename T>
  constexpr auto
  static_string(T const& cstr);

  template<typename T, integer N>
  class Static_string
  {
    static_assert(N >= 0);

  public:
    using char_type = T;
    static constexpr integer extent = N;
    static constexpr integer full_extent = extent + 1;

    static constexpr integer
    size()
    {
      return N;
    }

    constexpr const char*
    c_str() const
    {
      return &value[0];
    }

    string
    str() const
    {
      return {c_str()};
    }

    auto
    begin() const
    {
      return value.begin();
    }

    auto
    end() const
    {
      return prev(value.end());
    }

    auto
    cbegin() const
    {
      return begin();
    }

    auto
    cend() const
    {
      return end();
    }

    auto
    rbegin() const
    {
      return next(value.rbegin());
    }

    auto
    rend() const
    {
      return value.rend();
    }

    constexpr T
    operator[](integer index) const
    {
      return value[index];
    }

    T
    at(integer index) const
    {
      if (index >= 0 && index < N) {
        return value[index];
      } else {
        throw out_of_range("Invalid index for Static_string");
      }
    }

  private:
    using storage = array<T, N + 1>;
    storage value;

    template<typename T1, typename T2, typename... Ts>
    constexpr Static_string(T1 x1, T2 x2, Ts... xs)
      : value{{x1, x2, xs...}}
    {}

    constexpr Static_string(T x)
      : value{{{x}}}
    {
      static_assert(N == 0);
    }

    template<typename U>
    friend constexpr auto
    static_string(U const& cstr);

    template<typename U, U... xs>
    friend class Lifted_string;

    template<typename U, integer M>
    friend class Static_string;

    template<typename U>
    static constexpr Static_string
    make(U const& cstr)
    {
      return make_aux(idx<extent_v<U>>, cstr);
    }

    template<typename U, typename... Us>
    static constexpr auto
    make_aux(Idx<0>, U const&, Us... xs)
    {
      return Static_string{xs...};
    }

    template<integer I, typename U, typename... Us>
    static constexpr auto
    make_aux(Idx<I>, U const& cstr, Us... xs)
    {
      static_assert(I > 0);
      return make_aux(idx<I - 1>, cstr, cstr[I - 1], xs...);
    }

    template<typename Stream>
    friend Stream&
    operator<<(Stream& os, Static_string const& str)
    {
      os << str.c_str();
      return os;
    }

    friend ostream&
    operator<<(ostream& os, Static_string const& str)
    {
      os << str.c_str();
      return os;
    }

    static constexpr bool
    equal(Idx<N>, Static_string const&, Static_string const&)
    {
      return true;
    }

    template<integer I>
    static constexpr bool
    equal(Idx<I>, Static_string const& str1, Static_string const& str2)
    {
      return str1[I] == str2[I] ? equal(idx<I + 1>, str1, str2) : false;
    }

    friend constexpr bool
    operator==(Static_string const& str1, Static_string const& str2)
    {
      return equal(idx<0>, str1, str2);
    }

    template<typename U, integer M>
    friend constexpr bool
    operator==(Static_string const&, Static_string<U, M> const&)
    {
      return false;
    }

    friend bool
    operator==(Static_string const& str1, string const& str2)
    {
      return str1.str() == str2;
    }

    friend bool
    operator==(string const& str1, Static_string const& str2)
    {
      return str1 == str2.str();
    }

    template<typename U>
    friend constexpr bool
    operator!=(Static_string const& str1, Static_string const& str2)
    {
      return !(str1 == str2);
    }

    template<typename U, integer M>
    friend constexpr bool
    operator!=(Static_string const& str1, Static_string<U, M> const& str2)
    {
      return !(str1 == str2);
    }

    friend bool
    operator!=(Static_string const& str1, string const& str2)
    {
      return !(str1 == str2);
    }

    friend bool
    operator!=(string const& str1, Static_string const& str2)
    {
      return !(str1 == str2);
    }

    template<integer M, typename... Ts>
    static constexpr Static_string<char_type, M>
    take_aux(Idx<M>, Idx<M>, Static_string const&, Ts... xs)
    {
      return {xs..., char_type(0)};
    }

    template<integer I, integer M, typename... Ts>
    static constexpr Static_string<char_type, M>
    take_aux(Idx<I>, Idx<M>, Static_string const& str, Ts... xs)
    {
      return take_aux(idx<I + 1>, idx<M>, str, xs..., str[I]);
    }

    template<integer M>
    friend constexpr auto
    take(Static_string const& str)
    {
      return take_aux(idx<0>, idx<M>, str);
    }

    template<integer M>
    friend constexpr auto
    take(Static_string const& str, Idx<M>)
    {
      return take_aux(idx<0>, idx < M < N ? M : N >, str);
    }

    template<size_t M>
    friend constexpr auto
    take(Static_string const& str, Nat<M>)
    {
      return take(str, idx<M>);
    }

    template<typename... Ts>
    static constexpr auto
    drop_aux(Idx<N>, Static_string const&, Ts... xs)
    {
      return Static_string<char_type, count_args(xs...)>{xs..., char_type(0)};
    }

    template<integer I, typename... Ts>
    static constexpr auto
    drop_aux(Idx<I>, Static_string const& str, Ts... xs)
    {
      return drop_aux(idx<I + 1>, str, xs..., str[I]);
    }

    template<integer M>
    friend constexpr auto
    drop(Static_string const& str, Idx<M>)
    {
      return drop_aux(idx < M < N ? M : N >, str);
    }

    template<size_t M>
    friend constexpr auto
    drop(Static_string const& str, Nat<M>)
    {
      return drop_aux(idx < M < N ? M : N >, str);
    }

    template<typename Indices1, typename Indices2>
    struct ConcatHelper;

    template<size_t... indices1, size_t... indices2>
    struct ConcatHelper<
      index_sequence<indices1...>,
      index_sequence<indices2...>>
    {
      template<integer M1, integer M2>
      static constexpr auto
      exec(
        Static_string<char_type, M1> const& str1,
        Static_string<char_type, M2> const& str2)
      {
        return Static_string<char_type, M1 + M2>{
          str1[indices1]..., str2[indices2]..., char_type(0)};
      }
    };

    template<integer M>
    friend constexpr auto
    concat(Static_string const& str1, Static_string<char_type, M> const& str2)
    {
      return ConcatHelper<
        decltype(generate_indices<N>()),
        decltype(generate_indices<M>())>::exec(str1, str2);
    }

    template<integer M, typename U, typename... Us>
    friend constexpr auto
    concat(
      Static_string const& str1,
      Static_string<char_type, M> const& str2,
      U const& str3,
      Us const&... strs)
    {
      return concat(concat(str1, str2), str3, strs...);
    }

    template<integer M>
    friend constexpr auto
    operator+(
      Static_string const& str1,
      Static_string<char_type, M> const& str2)
    {
      return concat(str1, str2);
    }

  }; // end of class Static_string

  template<integer N>
  Static_string(char (&)[N]) -> Static_string<char, N>;

  /**
   * @brief Return a static string constructed from an input c string
   */
  template<typename T>
  constexpr auto
  static_string(T const& cstr)
  {
    return Static_string<remove_all_extents_t<T>, extent_v<T> - 1>::make(cstr);
  }

} // end of namespace CTString::Details

namespace std {
  template<
    ::CTString::Details::integer I,
    typename T,
    ::CTString::Details::integer N>
  constexpr T
  get(::CTString::Details::Static_string<T, N> const& str)
  {
    return str[I];
    static_assert(I < N);
    static_assert(I > 0);
  }

} // end of namespace std
