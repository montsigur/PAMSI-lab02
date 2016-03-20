// Wojciech Michałowski
// nr albumu 218705

#ifndef DEQUE_HPP
#define DEQUE_HPP
#include <iostream>
#include "DequeEmptyException.hpp"
#include "element.hpp"
using namespace std;

class deque {

public:
  
  deque();

  ~deque();

  void dodajNaPoczatek(element* elem);

  void dodajNaKoniec(element* elem);

  element* sprawdzPoczatek();

  element* sprawdzKoniec();

  element* zdejmijPoczatek();

  element* zdejmijKoniec();

  bool pusta();

  void wyczysc();

  int rozmiar();

  void zawartosc();

private:

  element* poczatek;
  element* koniec;

};

#endif
