#include <iostream>
using namespace std;

struct element_listy {

  struct element_listy* nastepny;
  int wartosc;

};

struct element_listy* stworzListe() {

  return NULL;

}

struct element_listy* stworzElement(int wartosc) {

  struct element_listy* element = new struct element_listy;
  element->nastepny = NULL;
  element->wartosc = wartosc;

  return element;
  
}

bool czyJestPusta(struct element_listy* poczatek_listy) {

  if (poczatek_listy == NULL)
    return true;

  else
    return false;

}

struct element_listy* usunZwrocOstatni(struct element_listy* &poczatek_listy) {

  struct element_listy* przedostatni;
  struct element_listy* ostatni;

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

struct element_listy* sprawdzZwrocOstatni(struct element_listy* poczatek_listy) {

  struct element_listy* ostatni = poczatek_listy;
  
  if (czyJestPusta(poczatek_listy)) {

    cout << "Lista jest pusta.";
    return NULL;
    
  }

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }

    return ostatni;
    
  }
}

void dodajNaPrzod(struct element_listy* &poczatek_listy,
		  struct element_listy* element) {

  struct element_listy* ostatni = poczatek_listy;

  if (czyJestPusta(poczatek_listy))
    poczatek_listy = element;

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }
    ostatni->nastepny = element;
    
  }
}

void usunWszystkie(struct element_listy* poczatek_listy) {

  if (!czyJestPusta(poczatek_listy)) {

    struct element_listy* element;
    
    while (poczatek_listy != NULL) {
      element = poczatek_listy;
      poczatek_listy = poczatek_listy->nastepny;
      delete element;
      
    }
  }
}

int main() {

  struct element_listy* poczatek = stworzListe();
  struct element_listy *a, *b, *c, *d;

  a = stworzElement(3);
  b = stworzElement(5);
  c = stworzElement(43);

  dodajNaPrzod(poczatek, a);
  dodajNaPrzod(poczatek, b);
  dodajNaPrzod(poczatek, c);

  d = usunZwrocOstatni(poczatek);

  cout << d->wartosc << endl;

  delete d;
  d = sprawdzZwrocOstatni(poczatek);

  cout << d->wartosc << endl;

  usunWszystkie(poczatek);
  
  return 0;
}
