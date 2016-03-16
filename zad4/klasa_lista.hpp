#ifndef KLASA_LISTA_HPP
#define KLASA_LISTA_HPP
#include "element.hpp"

class lista {

public:

  lista();

  ~lista();

  void dodaj(element* elem);

  element* sprawdz();

  element* zdejmij();

  bool pusta();

  void wyczysc();

  int rozmiar();

private:

  element* poczatek;
  element* koniec;
};

#endif
