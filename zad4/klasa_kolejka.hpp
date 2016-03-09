#ifndef KLASA_KOLEJKA_HPP
#define KLASA_KOLEJKA_HPP
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

private:

  element* poczatek;
};

#endif
