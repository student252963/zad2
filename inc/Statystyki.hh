#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



struct Statystyka { //stworzona struktura zawieraa informacje o ilosci dobrych izlych odpowiedzi
  int dobre;
  int zle;
};



Statystyka inicjuj_stat (Statystyka &st);
Statystyka dodaj_dobra (Statystyka &st);
Statystyka dodaj_zla (Statystyka &st);

int poprawnych (Statystyka &st);
int wszystkich (Statystyka &st);
int procent_pop (Statystyka &st);

std::ostream & operator << (std::ostream &strm, Statystyka &st);

#endif
