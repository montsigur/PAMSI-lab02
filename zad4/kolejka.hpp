// Wojciech Michałowski
// nr albumu 218705

#ifndef KOLEJKA_HPP
#define KOLEJKA_HPP
#include "element.hpp"

class kolejka {

public:

  kolejka();

  ~kolejka();

  void dodaj(element* elem);

  element* sprawdz();

  element* zdejmij();

  bool pusta();

  void wyczysc();

  int rozmiar();

  bool zawiera_wartosc(string wartosc);

  void zawartosc();
  
private:

  element* poczatek;
  element* koniec;
};

#endif
