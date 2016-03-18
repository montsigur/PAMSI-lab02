#include <iostream>
using namespace std;

struct element_kolejki {

  element_kolejki* nastepny;
  int wartosc;

};

element_kolejki* stworzKolejke() {

  return NULL;
  
}

element_kolejki* stworzElement(int wartosc) {

  element_kolejki* element = new element_kolejki;
  element->nastepny = NULL;
  element->wartosc = wartosc;

  return element;
  
}

bool czyJestPusta(element_kolejki* poczatek_kolejki) {

  if (poczatek_kolejki == NULL)
    return true;

  else
    return false;

}

element_kolejki* usunZwrocPierwszy(element_kolejki* &poczatek_kolejki,
				   element_kolejki* &koniec_kolejki) {

  element_kolejki* pierwszy = poczatek_kolejki;
  
  if (czyJestPusta(poczatek_kolejki))    
    cout << "Blad. Kolejka jest pusta." << endl;

  else if (poczatek_kolejki == koniec_kolejki)
    poczatek_kolejki = koniec_kolejki = NULL;

  else
    poczatek_kolejki = poczatek_kolejki->nastepny;

  return pierwszy;
}

element_kolejki* sprawdzZwrocPierwszy(element_kolejki* poczatek_kolejki) {

  if (czyJestPusta(poczatek_kolejki))
    cout << "Kolejka jest pusta.";

  return poczatek_kolejki;
}

void dodajNaKoniec(element_kolejki* &poczatek_kolejki,
		   element_kolejki* &koniec_kolejki,
		   element_kolejki* element) {

  if (czyJestPusta(poczatek_kolejki))
    poczatek_kolejki = koniec_kolejki = element;
  
  else {

    koniec_kolejki->nastepny = element;
    element->nastepny = NULL;
    koniec_kolejki = element;
    
  }
}

void usunWszystkie(element_kolejki* &poczatek_kolejki) {

  if (!czyJestPusta(poczatek_kolejki)) {

    element_kolejki* element;
    
    while (poczatek_kolejki != NULL) {
      element = poczatek_kolejki;
      poczatek_kolejki = poczatek_kolejki->nastepny;
      delete element;
      
    }
  }
}
  
int main() {

  element_kolejki* poczatek = stworzKolejke();
  element_kolejki* koniec = poczatek;
  element_kolejki *a, *b, *c, *d;

  a = stworzElement(3);
  b = stworzElement(5);
  c = stworzElement(43);

  dodajNaKoniec(poczatek, koniec, a);
  dodajNaKoniec(poczatek, koniec, b);
  dodajNaKoniec(poczatek, koniec, c);

  d = usunZwrocPierwszy(poczatek, koniec);

  cout << d->wartosc << endl;

  delete d;
  d = sprawdzZwrocPierwszy(poczatek);

  cout << d->wartosc << endl;

  usunWszystkie(poczatek);
  
  return 0;
  
}
