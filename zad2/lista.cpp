#include <iostream>
using namespace std;

struct element_listy {

  element_listy* nastepny;
  int wartosc;

};

element_listy* stworzListe() {

  return NULL;

}

element_listy* stworzElement(int wartosc) {

  element_listy* element = new element_listy;
  element->nastepny = NULL;
  element->wartosc = wartosc;

  return element;
  
}

bool czyJestPusta(element_listy* poczatek_listy) {

  if (poczatek_listy == NULL)
    return true;

  else
    return false;

}

element_listy* usunZwrocPierwszy(element_listy* &poczatek_listy) {

  element_listy* pierwszy = poczatek_listy;

  if (czyJestPusta(poczatek_listy))
    cout << "Blad. Lista jest pusta." << endl;

  else
    poczatek_listy = poczatek_listy->nastepny;

  return pierwszy;
}

element_listy* sprawdzZwrocPierwszy(element_listy* poczatek_listy) {
  
  if (czyJestPusta(poczatek_listy))
    cout << "Lista jest pusta.";

  return poczatek_listy;

}

void dodajNaPoczatek(element_listy* &poczatek_listy,
		     element_listy* element) {

  if (czyJestPusta(poczatek_listy)) {
    
    poczatek_listy = element;
    element->nastepny = NULL;

  }

  else {

    element->nastepny = poczatek_listy;
    poczatek_listy = element;
    
  }
}

void usunWszystkie(element_listy* &poczatek_listy) {

  if (!czyJestPusta(poczatek_listy)) {

    element_listy* element;
    
    while (poczatek_listy != NULL) {
      element = poczatek_listy;
      poczatek_listy = poczatek_listy->nastepny;
      delete element;
      
    }
  }
}

int main() {

  element_listy* poczatek = stworzListe();
  element_listy *a, *b, *c, *d;

  a = stworzElement(3);
  b = stworzElement(5);
  c = stworzElement(43);

  dodajNaPoczatek(poczatek, a);
  dodajNaPoczatek(poczatek, b);
  dodajNaPoczatek(poczatek, c);

  d = usunZwrocPierwszy(poczatek);

  cout << d->wartosc << endl;

  delete d;
  d = sprawdzZwrocPierwszy(poczatek);

  cout << d->wartosc << endl;

  usunWszystkie(poczatek);
  
  return 0;
}
