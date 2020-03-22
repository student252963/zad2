#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1,  LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re + Skl1.im * Skl2.im)/(Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  Wynik.im = (Skl2.re * Skl1.im - Skl1.re * Skl2.im)/(Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  return Wynik;
}


LZespolona utworz(double re, double im){
  LZespolona Stworzona;
  
  Stworzona.re = re;
  Stworzona.im = im;
  return Stworzona;
}


std::istream & operator >> (std::istream & strm_we, LZespolona &Z1)
{
  char znak;
  strm>>znak;
  if(znak!='(')
    strm.setstate(std::ios::failbit);
  strm>>Z1.re;
  strm>>znak;
  strm>>Z1.im;
  strm>>znak;
  if(znak!='i')
    strm.setstate(std::ios::failbit);
    strm>>znak;
  if(znak!=')')
    strm.setstate(std::ios::failbit);
  return strm_we;
}


std::ostream & operator << (std::ostream & strm_wy, const LZespolona & Wynik)
{
  return strm_wy << '(' << Wynik.re << showpos << Wynik.im << noshowpos << 'i)';
}
  
