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

private:

  element* poczatek;
};

#endif
