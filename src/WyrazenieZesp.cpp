#include <iostream>
#include "WyrazenieZesp.hh"

using namespace std;


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


LZespolona Oblicz(WyrazenieZesp WyrZ) //W zaleznosci od operatora wykonuje obliczenie 
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
  return LW;
}
  


istream & operator >> (istream & strm_we, WyrazenieZesp & WyrZ) { //przeciazenie wczytywania wyraaazaenia, przypisuje odpowiednie wyrazenia ze wzgledu na znak
  char znak;
  strm_we >> znak;
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
    return strm_we;
}



ostream & operator << (ostream & strm_wy, WyrazenieZesp & WyrZ) {  // wyswietla wyrazenie   na podstawie wczzesniej wczytanego wyrazenia tak jakby wraca do tego co mial (znaku)

  cout << WyrZ.Arg1;

  switch (WyrZ.Op)
    {
    case Op_Dodaj:
      cout << '+';
      break;
    case Op_Odejmij:
      cout << '-';
      break;
    case Op_Mnoz:
      cout << '*';
      break;
    case Op_Dziel:
      cout << '/';
      break;
    }

  cout << WyrZ.Arg2;
  
  return strm_wy;
}

