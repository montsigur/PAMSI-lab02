#ifndef DEQUE_HPP
#define DEQUE_HPP
#include <iostream>
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

private:

  element* poczatek;

  element* koniec;

};

#endif
