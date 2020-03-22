#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


LZespolona Oblicz(WyrazenieZesp WyrZ)
{
  LZespolona LW;
  switch(WyrZ.Op)
    {
    case Op_Dodaj:
      LW = WyrZ.Arg1 + WyrZ.Arg2;
      break;
    case Op_Odejmij:
      LW = WyrZ.Arg1 - WyrZ.Arg2;
      break;
    case Op_Mnoz:
      LW = WyrZ.Arg1 * WyrZ.Arg2;
      break;
    case Op_Dziel:
      LW = WyrZ.Arg1 / WyrZ.Arg2;
      break;
    }
}
  


std::istream & operator >> (std::istream & strm, WyrazenieZesp & WyrZ) {
  strm >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
  return strm;
}

std::istream & operator >> (std::istream & strm, Operator & Op) {
  char znak;
  strm >> znak;
    switch (znak)
      {
      case '+':
	WyrZ.Op = Op_Dodaj;
	break;
      case '-':
	WyrZ.Op = Op_Odejmij;
	break;
      case '*':
	WyrZ.Op = Op_Mnoz;
	break;
      case'/':
	WyrZ.Op = Op_Dziel;
	break;
  }
    return strm;
}
