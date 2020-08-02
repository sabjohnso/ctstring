//
// ... Standard header files
//
#include <string>

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... CTString header files
//
#include <ctstring/ctstring.hpp>

namespace CTString::Testing
{

  namespace // anonymous
  {
    using namespace ::std::literals::string_literals;
    using namespace ::CTString::Constants;
  } // end of anonymous namespace

  TEST(Constants, empty){ ASSERT_EQ(empty.str(), ""s); }
  TEST(Constants, digits){ ASSERT_EQ(digits.str(), "0123456789"s); }
  TEST(Constants, lower){ ASSERT_EQ(lower.str(), "abcdefghijklmnopqrstuvwxyz"s); }
  TEST(Constants, upper){ ASSERT_EQ(upper.str(), "ABCDEFGHIJKLMNOPQRSTUVWXYZ"s); }

  TEST(Constants, a){ ASSERT_EQ(a.str(), "a"s); }
  TEST(Constants, b){ ASSERT_EQ(b.str(), "b"s); }
  TEST(Constants, c){ ASSERT_EQ(c.str(), "c"s); }
  TEST(Constants, d){ ASSERT_EQ(d.str(), "d"s); }
  TEST(Constants, e){ ASSERT_EQ(e.str(), "e"s); }
  TEST(Constants, f){ ASSERT_EQ(f.str(), "f"s); }
  TEST(Constants, g){ ASSERT_EQ(g.str(), "g"s); }
  TEST(Constants, h){ ASSERT_EQ(h.str(), "h"s); }
  TEST(Constants, i){ ASSERT_EQ(i.str(), "i"s); }
  TEST(Constants, j){ ASSERT_EQ(j.str(), "j"s); }
  TEST(Constants, k){ ASSERT_EQ(k.str(), "k"s); }
  TEST(Constants, l){ ASSERT_EQ(l.str(), "l"s); }
  TEST(Constants, m){ ASSERT_EQ(m.str(), "m"s); }
  TEST(Constants, n){ ASSERT_EQ(n.str(), "n"s); }
  TEST(Constants, o){ ASSERT_EQ(o.str(), "o"s); }
  TEST(Constants, p){ ASSERT_EQ(p.str(), "p"s); }
  TEST(Constants, q){ ASSERT_EQ(q.str(), "q"s); }
  TEST(Constants, r){ ASSERT_EQ(r.str(), "r"s); }
  TEST(Constants, s){ ASSERT_EQ(s.str(), "s"s); }
  TEST(Constants, t){ ASSERT_EQ(t.str(), "t"s); }
  TEST(Constants, u){ ASSERT_EQ(u.str(), "u"s); }
  TEST(Constants, v){ ASSERT_EQ(v.str(), "v"s); }
  TEST(Constants, w){ ASSERT_EQ(w.str(), "w"s); }
  TEST(Constants, x){ ASSERT_EQ(x.str(), "x"s); }
  TEST(Constants, y){ ASSERT_EQ(y.str(), "y"s); }
  TEST(Constants, z){ ASSERT_EQ(z.str(), "z"s); }

  TEST(Constants, A){ ASSERT_EQ(A.str(), "A"s); }
  TEST(Constants, B){ ASSERT_EQ(B.str(), "B"s); }
  TEST(Constants, C){ ASSERT_EQ(C.str(), "C"s); }
  TEST(Constants, D){ ASSERT_EQ(D.str(), "D"s); }
  TEST(Constants, E){ ASSERT_EQ(E.str(), "E"s); }
  TEST(Constants, F){ ASSERT_EQ(F.str(), "F"s); }
  TEST(Constants, G){ ASSERT_EQ(G.str(), "G"s); }
  TEST(Constants, H){ ASSERT_EQ(H.str(), "H"s); }
  TEST(Constants, I){ ASSERT_EQ(I.str(), "I"s); }
  TEST(Constants, J){ ASSERT_EQ(J.str(), "J"s); }
  TEST(Constants, K){ ASSERT_EQ(K.str(), "K"s); }
  TEST(Constants, L){ ASSERT_EQ(L.str(), "L"s); }
  TEST(Constants, M){ ASSERT_EQ(M.str(), "M"s); }
  TEST(Constants, N){ ASSERT_EQ(N.str(), "N"s); }
  TEST(Constants, O){ ASSERT_EQ(O.str(), "O"s); }
  TEST(Constants, P){ ASSERT_EQ(P.str(), "P"s); }
  TEST(Constants, Q){ ASSERT_EQ(Q.str(), "Q"s); }
  TEST(Constants, R){ ASSERT_EQ(R.str(), "R"s); }
  TEST(Constants, S){ ASSERT_EQ(S.str(), "S"s); }
  TEST(Constants, T){ ASSERT_EQ(T.str(), "T"s); }
  TEST(Constants, U){ ASSERT_EQ(U.str(), "U"s); }
  TEST(Constants, V){ ASSERT_EQ(V.str(), "V"s); }
  TEST(Constants, W){ ASSERT_EQ(W.str(), "W"s); }
  TEST(Constants, X){ ASSERT_EQ(X.str(), "X"s); }
  TEST(Constants, Y){ ASSERT_EQ(Y.str(), "Y"s); }
  TEST(Constants, Z){ ASSERT_EQ(Z.str(), "Z"s); }



} // end of namespace CTString::Testing
