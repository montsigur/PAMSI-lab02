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

element_listy* usunZwrocOstatni(element_listy* &poczatek_listy) {

  element_listy* przedostatni;
  element_listy* ostatni;

  if (czyJestPusta(poczatek_listy)) {
    cout << "Blad. Lista jest pusta." << endl;
    return NULL;
  }

  else if (poczatek_listy->nastepny == NULL) {

    ostatni = poczatek_listy;
    poczatek_listy = NULL;
    return ostatni;
    
  }

  else {

    przedostatni = poczatek_listy;
    
    while (przedostatni->nastepny->nastepny != NULL) {
      
      przedostatni = przedostatni->nastepny;

    }

    ostatni = przedostatni->nastepny;
    przedostatni->nastepny = NULL;

    return ostatni;

  }
}

element_listy* sprawdzZwrocOstatni(element_listy* poczatek_listy) {

  element_listy* ostatni = poczatek_listy;
  
  if (czyJestPusta(poczatek_listy)) {

    cout << "Lista jest pusta.";
    return NULL;
    
  }

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }

    return ostatni;
    
  }
}

void dodajNaTyl(element_listy* &poczatek_listy,
		  element_listy* element) {

  element_listy* ostatni = poczatek_listy;

  if (czyJestPusta(poczatek_listy))
    poczatek_listy = element;

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }
    ostatni->nastepny = element;
    
  }
}

void usunWszystkie(element_listy* poczatek_listy) {

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

  dodajNaTyl(poczatek, a);
  dodajNaTyl(poczatek, b);
  dodajNaTyl(poczatek, c);

  d = usunZwrocOstatni(poczatek);

  cout << d->wartosc << endl;

  delete d;
  d = sprawdzZwrocOstatni(poczatek);

  cout << d->wartosc << endl;

  usunWszystkie(poczatek);
  
  return 0;
}
