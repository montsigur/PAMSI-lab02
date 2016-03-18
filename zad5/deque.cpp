#include "deque.hpp"
using namespace std;

deque::deque() {

  poczatek = koniec = NULL;

}

deque::~deque() {

  wyczysc();

}

void deque::dodajNaPoczatek(element* elem) {

  if (pusta()) {

    poczatek = koniec = elem;
    elem->poprzedni = NULL;
    elem->nastepny = NULL;

  }
  
  else {

    elem->nastepny = poczatek;
    elem->nastepny->poprzedni = elem;
    elem->poprzedni = NULL;
    poczatek = elem;

  }
}

void deque::dodajNaKoniec(element* elem) {

  if (pusta()) {
    
    poczatek = koniec = elem;
    elem->poprzedni = NULL;
    elem->nastepny = NULL;
    
  }

  else {

    elem->poprzedni = koniec;
    elem->poprzedni->nastepny = elem;
    elem->nastepny = NULL;
    koniec = elem;

  }
}

element* deque::sprawdzPoczatek() {

  try {
  
    if (pusta())
      throw DequeEmptyException();
    
  }

  catch (exception& blad) { cout << blad.what() << endl; }

  return poczatek;

}

element* deque::sprawdzKoniec() {

  try {
  
    if (pusta())
      throw DequeEmptyException();
    
  }

  catch (exception& blad) { cout << blad.what() << endl; }
    
  return koniec;

}

element* deque::zdejmijPoczatek() {

  element* elem;

  try {
  
    if (pusta())
      throw DequeEmptyException();

    else {

      elem = poczatek;
      poczatek = poczatek->nastepny;
      return elem;
      
    }
  }

  catch (exception& blad) {

    cout << blad.what() << endl;
    return koniec;

  }
}

element* deque::zdejmijKoniec() {

  element* elem;

  try {
  
    if (pusta())
      throw DequeEmptyException();

    else {

      elem = koniec;
      koniec = koniec->poprzedni;
      return elem;
      
    }
  }

  catch (exception& blad) {

    cout << blad.what() << endl;
    return koniec;
    
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

  while(iterator != NULL) {

    ilosc++;
    iterator = iterator->nastepny;

  }

  return ilosc;
}
