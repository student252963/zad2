#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"

using namespace std;



int main(int argc, char **argv) //W zaleznosci od wywolania programu okresli rodzaj testu, za mala liczba argumentow sprawi zamkniecie programu tak samo jak nieprawidlowa nazwa testu
{

  if (argc < 2) {//za mala liczba argumentow
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) { //nieprawidlowa nazwa
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  //nizej inicjujemy statystyke, wyrazenie i liczbe zespolonych na ktorych bedziemy dzialac
  Statystyka stat;
  inicjuj_stat (stat);
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona LzO;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) { //pobiera pytanie z bazy
    cout << endl;
    cout << endl;
    cout << ":? Podaj wynik operacji:   " << WyrZ_PytanieTestowe << endl;
    cout << "   Twoja odpowiedz:   ";
    cin >> LzO;

    for (int poprawnosc=0; poprawnosc<2; ++poprawnosc){ //program daje 3 szanse na poprawne wpisanie liczby zespolonej w dopuszczalnym formacie
      if (!cin.good()) {
	cin.clear();
	cin.ignore(10000, '\n');
	cout << ":! Liczba zespolona została zle zapisana! Sprobuj jeszcze raz." << endl;
	cout << ":v Przykładowy zapis liczby zespolonej: (1+2i). Uzywaj tez kropek zamiast przecinkow :)" << endl;
	cout << endl;
	cout << endl;
	cout << "     Twoja odpowiedz:   ";
	cin >> LzO;
      }
      else
	poprawnosc=3;
    }
    //nastepnie w zaleznosci od poprawnosci zwiekszy sie liczba dobrych/zlych odp
      if (LzO == Oblicz(WyrZ_PytanieTestowe)) {
	cout << ":) Odpowiedz poprawna" << endl;
	dodaj_dobra(stat);
      }
      else {
	cout << ":( Blad. Prawidlowym wynikiem jest:   " << Oblicz(WyrZ_PytanieTestowe) << endl;
	dodaj_zla(stat);
      }

      cin.clear();
      cin.ignore(10000, '\n');
  }

  //Nizej program przedstawi wyniki koncowe i zakonczy dzialanie
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  
  cout << endl;
  cout << stat;
}
