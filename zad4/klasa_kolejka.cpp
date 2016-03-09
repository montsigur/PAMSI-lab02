#include "klasa_kolejka.hpp"
using namespace std;

kolejka::kolejka() {

  poczatek = NULL;
  
}

kolejka::~kolejka() {

  wyczysc();
  
}

bool kolejka::pusta() {

  if (poczatek == NULL)
    return true;

  else
    return false;
  
}

void kolejka::wyczysc() {

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

void kolejka::dodaj(element* elem) {

  element* ostatni = poczatek;

  if (pusta())
    poczatek = elem;

  else {

    while (ostatni->nastepny != NULL) { ostatni = ostatni->nastepny; }
    ostatni->nastepny = elem;
    
  }
}

element* kolejka::sprawdz() {

  if (pusta())
    cout << "Kolejka jest pusta." << endl;

  return poczatek;
    
}

element* kolejka::zdejmij() {

  element* pierwszy;
  
  if (pusta()) {

    cout << "Blad. Kolejka jest pusta." << endl;
    return poczatek;

  }

  else {

    pierwszy = poczatek;
    poczatek = poczatek->nastepny;
    return pierwszy;
    
  }
}
