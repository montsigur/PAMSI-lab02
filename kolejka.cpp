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

element_kolejki* usunZwrocPierwszy(element_kolejki* &poczatek_kolejki) {

  element_kolejki* pierwszy;
  
  if (czyJestPusta(poczatek_kolejki)) {
    
    cout << "Blad. Kolejka jest pusta." << endl;
    return poczatek_kolejki;
    
  }

  else {

    pierwszy = poczatek_kolejki;
    poczatek_kolejki = poczatek_kolejki->nastepny;
    return pierwszy;

  }
}

element_kolejki* sprawdzZwrocPierwszy(element_kolejki* poczatek_kolejki) {

  if (czyJestPusta(poczatek_kolejki)) {

    cout << "Kolejka jest pusta.";
    return NULL;
    
  }

  else {

    return poczatek_kolejki;
    
  }
}

void dodajNaTyl(element_kolejki* &poczatek_kolejki,
		element_kolejki* element) {

  element_listy* ostatni = poczatek_listy;

  if (czyJestPusta(poczatek_listy))
    poczatek_listy = element;
  
  else {
    
    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }
    ostatni->nastepny = element;
    
  }
}

void usunWszystkie(element_kolejki* poczatek_kolejki) {

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
  element_kolejki *a, *b, *c, *d;

  a = stworzElement(3);
  b = stworzElement(5);
  c = stworzElement(43);

  dodajNaTyl(poczatek, a);
  dodajNaTyl(poczatek, b);
  dodajNaTyl(poczatek, c);

  d = usunZwrocPierwszy(poczatek);

  cout << d->wartosc << endl;

  delete d;
  d = sprawdzZwrocPierwszy(poczatek);

  cout << d->wartosc << endl;

  usunWszystkie(poczatek);
  
  return 0;
  
}
