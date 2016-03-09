#include "deque.hpp"
using namespace std;

deque::deque() {

}

deque::~deque() {

}

void deque::dodajNaPoczatek(element* elem) {
  ;
}

void deque::dodajNaKoniec(element* elem) {

  element* ostatni = poczatek;

  if (pusta())
    poczatek = elem;

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }
    ostatni->nastepny = elem;
    
  }
}

element* deque::sprawdzPoczatek() {

 element* ostatni = poczatek;
  
  if (pusta())
    cout << "Lista jest pusta.";

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }

  }
  
  return ostatni;

}

element* deque::sprawdzKoniec() {

 element* ostatni = poczatek;
  
  if (pusta())
    cout << "Lista jest pusta.";

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }

  }
  
  return ostatni;

}

element* deque::zdejmijPoczatek();

element* deque::zdejmijKoniec() {

  element* przedostatni;
  element* ostatni;

  if (pusta()) {
    cout << "Blad. Lista jest pusta." << endl;
    return poczatek;
  }

  else if (poczatek->nastepny == NULL) {

    ostatni = poczatek;
    poczatek = NULL;
    return ostatni;
    
  }

  else {

    przedostatni = poczatek;
    
    while (przedostatni->nastepny->nastepny != NULL) {
      
      przedostatni = przedostatni->nastepny;

    }

    ostatni = przedostatni->nastepny;
    przedostatni->nastepny = NULL;

    return ostatni;

  }
}

bool deque::pusta();

void deque::wyczysc();

