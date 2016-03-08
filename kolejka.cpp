#include <iostream>
using namespace std;

struct element_kolejki {

  struct element_kolejki* nastepny;
  int wartosc;

};

struct element_kolejki* stworzKolejke() {

  return NULL;
  
}

struct element_kolejki* stworzElement(int wartosc) {

  struct element_kolejki* element = new struct element_kolejki;
  element->nastepny = NULL;
  element->wartosc = wartosc;

  return element;
  
}

bool czyJestPusta(struct element_kolejki* poczatek_kolejki) {

  if (poczatek_kolejki == NULL)
    return true;

  else
    return false;

}

struct element_kolejki* usunZwrocPierwszy(struct element_kolejki* &poczatek_kolejki) {

  struct element_kolejki* pierwszy;
  
  if (czyJestPusta(poczatek_kolejki)) {
    
    cout << "Blad. Lista jest pusta." << endl;
    return poczatek_kolejki;
    
  }

  else {

    pierwszy = poczatek_kolejki;
    poczatek_kolejki = poczatek_kolejki->nastepny;
    return pierwszy;

  }
}

struct element_kolejki* sprawdzZwrocPierwszy(struct element_kolejki* poczatek_kolejki) {

  if (czyJestPusta(poczatek_kolejki)) {

    cout << "Kolejka jest pusta.";
    return NULL;
    
  }

  else {

    return poczatek_kolejki;
    
  }
}

void dodajNaTyl(struct element_kolejki* &poczatek_kolejki,
		struct element_kolejki* element) {

  element->nastepny = poczatek_kolejki;
  poczatek_kolejki = element;
  
}

void usunWszystkie(struct element_kolejki* poczatek_kolejki) {

  if (!czyJestPusta(poczatek_kolejki)) {

    struct element_kolejki* element;
    
    while (poczatek_kolejki != NULL) {
      element = poczatek_kolejki;
      poczatek_kolejki = poczatek_kolejki->nastepny;
      delete element;
      
    }
  }
}
  
int main() {

  struct element_kolejki* poczatek = stworzKolejke();
  struct element_kolejki *a, *b, *c, *d;

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
