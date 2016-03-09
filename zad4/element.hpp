#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <iostream>

struct element {

  element* nastepny;
  int wartosc;

  element(int wart_pocz) { nastepny = NULL; wartosc = wart_pocz; }
  element() { nastepny = NULL; }
  
};

#endif
