#pragma once

//
// ... CTString header files
//
#include <ctstring/details/Lifted_string_fwd.hpp>
#include <ctstring/details/Static_string.hpp>

namespace CTString::Details
{
  template<typename T>
  struct Lift_string;


  template<typename T, T ... xs>
  class Lifted_string{
    using value_type = Static_string<T,count_args(xs ...)>;
    static constexpr  value_type value{xs ..., T{0}};

  public:
    static constexpr auto
    s_str(){ return value; }

    static const char*
    c_str(){ return value.c_str(); }

    static string
    str(){ return value.str(); }

    constexpr
    operator value_type() const { return value; }

  private:

    template<T ... ys>
    friend constexpr Lifted_string<T,xs ..., ys ...>
    operator +(Lifted_string, Lifted_string<T, ys ...>){
      return {};
    }

    template<typename U>
    friend constexpr auto
    concat(Lifted_string, U){
      return Lifted_string{} + U{};
    }

    template<typename U, typename V, typename ... Vs>
    friend constexpr auto
    concat(Lifted_string, U, V, Vs ...){
      return concat(concat(Lifted_string{}, U{}), V{}, Vs{} ...);
    }

    template<integer N>
    struct TakeHelper
    {
      struct Holder{ static constexpr auto value = take(Lifted_string::value, idx<N>); };
      using type = typename Lift_string<Holder>::type;
    };

    template<integer N>
    friend constexpr typename TakeHelper<N>::type
    take(Lifted_string, Idx<N>){ return {}; }

    template<size_t N>
    friend constexpr auto
    take(Lifted_string, Nat<N>){ return take(Lifted_string{}, idx<N>); }


    template<integer N>
    struct DropHelper
    {
      struct Holder{ static constexpr auto value = drop(Lifted_string::value, idx<N>); };
      using type = typename Lift_string<Holder>::type;
    };

    template<integer N>
    friend constexpr typename DropHelper<N>::type
    drop(Lifted_string, Idx<N>){ return {}; }

    template<size_t N>
    friend constexpr auto
    drop(Lifted_string, Nat<N>){ return drop(Lifted_string{}, idx<N>); }

    friend constexpr bool
    operator ==(Lifted_string const&,  Lifted_string const&){ return true; }

    friend constexpr bool
    operator != (Lifted_string const&,  Lifted_string const&){ return false; }

    template< typename U, U ... ys>
    friend constexpr bool
    operator ==(Lifted_string const&, Lifted_string<U, ys ...> const&){ return false; }

    template< typename U, U ... ys>
    friend constexpr bool
    operator !=(Lifted_string const&, Lifted_string<U, ys ...> const&){ return true; }



    template<typename Stream>
    friend Stream&
    operator <<(Stream& os, Lifted_string const&){
      os << value.str();
      return os;
    }


    friend ostream&
    operator <<(ostream& os, Lifted_string const&){
      os << value.str();
      return os;
    }






  }; // end of class Lifted_string;

  template<typename T>
  struct Lift_string {
    using char_type = typename decltype(T::value)::char_type;
    static constexpr integer extent = decltype(T::value)::extent;

    template<integer I, typename Values, bool dummy = false>
    struct Aux;

    template<char_type ... xs, bool dummy>
    struct Aux<extent,integer_sequence<char_type, xs ...>, dummy>
      : Type<Lifted_string<char_type, xs ...>>
    {};

    template<integer I, char_type ... xs, bool dummy>
    struct Aux<I, integer_sequence<char_type, xs ...>, dummy>
      : Aux<I+1, integer_sequence<char_type, xs ..., T::value[I]>, dummy>
    {};

    using type = typename Aux<0,integer_sequence<char_type>>::type;
  };

  template<typename T>
  constexpr auto lifted_string = typename Lift_string<T>::type{};

} // end of namespace CTString::Details
