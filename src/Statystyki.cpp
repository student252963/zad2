#include <iostream>
#include "Statystyki.hh"

using namespace std;



Statystyka inicjuj_stat (Statystyka &st) //przypisuje statystyce wartosci 0 ktore w trakcie programu beda zwiekszane lub nie
{
  st.dobre = 0;
  st.zle = 0;
  return st;
}

Statystyka dodaj_dobra (Statystyka &st) //dodaaje dobra
{
  st.dobre++;
  return st;
}

Statystyka dodaj_zla (Statystyka &st) //tutaj zla
{
  st.zle++;
  return st;
}

int poprawnych (Statystyka & st) // no i przyda sie informacja o wszystkich pytaniach poprawnych  przyda sie do procentow
{
  int pop;

  pop = st.dobre;
  return pop;
}

int wszystkich (Statystyka & st) //tak samo jak iformacja o wszystkich zliczona ze zlych i dobrych odp
{
  int wszyst;

  wszyst = st.dobre + st.zle;
  return wszyst;
}

int procent_pop (Statystyka & st) //do procnetow poprawnych    wykorzystujemy poprzednie funkcje
{
  int pr_pop;

  pr_pop = poprawnych(st)*100 / wszystkich(st);

  return pr_pop;
}

ostream & operator << (ostream &strm, Statystyka &st)
{
  cout << " Ilosc poprawnych odpowiedzi: " << st.dobre << endl;
  cout << " Ilość blednych odpowiedzi: " << st.zle << endl;
  cout << " Wynik procentowy poprawnych odpowiedzi: " << procent_pop(st) << "%" << endl;
	 return strm;
}
    

  
