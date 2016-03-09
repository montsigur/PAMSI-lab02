#include "klasa_lista.hpp"
using namespace std;

lista::lista() {

  poczatek = NULL;
  
}

lista::~lista() {

  wyczysc();
  
}

bool lista::pusta() {

  if (poczatek == NULL)
    return true;

  else
    return false;
  
}

void lista::wyczysc() {

  element* elem;
  
  if (!pusta()) {

    elem = poczatek;
    
    while (poczatek != NULL) {

      elem = poczatek;
      poczatek = poczatek->nastepny;
      delete elem;
      
    }
  }
}

void lista::dodaj(element* elem) {

  element* ostatni = poczatek;

  if (pusta())
    poczatek = elem;

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }
    ostatni->nastepny = elem;
    
  }
}

element* lista::sprawdz() {

  element* ostatni = poczatek;
  
  if (pusta())
    cout << "Lista jest pusta.";

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }

  }
  
  return ostatni;
  
}

element* lista::zdejmij() {

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
