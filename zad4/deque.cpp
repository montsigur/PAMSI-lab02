#include "deque.hpp"
using namespace std;

deque::deque() {

  poczatek = koniec = NULL;

}

deque::~deque() {

  wyczysc();

}

void deque::dodajNaPoczatek(element* elem) {

  if (pusta())
    poczatek = koniec = elem;

  else {

    elem->nastepny = poczatek;
    elem->poprzedni = NULL;
    poczatek = elem;

  }
}

void deque::dodajNaKoniec(element* elem) {

  if (pusta())
    poczatek = koniec = elem;

  else {

    elem->poprzedni = koniec;
    elem->nastepny = NULL;
    koniec = elem;

  }
}

element* deque::sprawdzPoczatek() {

  if (pusta())
    throw DequeEmptyException;
  
  return poczatek;

}

element* deque::sprawdzKoniec() {

  if (pusta())
    throw DequeEmptyException;
  
  return koniec;

}

element* deque::zdejmijPoczatek() {

  element* elem;

  if (pusta()) {

    cout << "Blad. Lista jest pusta." << endl;
    return poczatek;

  }

  else {

    elem = poczatek;
    poczatek = poczatek->nastepny;
    return elem;

  }
}

element* deque::zdejmijKoniec() {

  element* elem;

  if (pusta()) {

    cout << "Blad. Lista jest pusta." << endl;
    return koniec;

  }

  else {

    elem = koniec;
    koniec = koniec->poprzedni;
    return elem;

  }
}

bool deque::pusta() {

  if (poczatek == NULL)
    return true;

  else
    return false;

}

void deque::wyczysc() {

  element* elem;

  if (!pusta()) {

    while (poczatek != NULL) {

      elem = poczatek;
      poczatek = poczatek->nastepny;
      delete elem;

    }
  }
}

int deque::rozmiar() {

  int ilosc = 0;
  element* iterator = poczatek;

  if (pusta())
    return 0;

  while(iterator->nastepny != NULL) {

    ilosc++;
    iterator = iterator->nastepny;

  }

  return ilosc;
}
