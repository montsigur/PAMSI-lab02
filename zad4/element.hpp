#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <iostream>
#include <string>
using namespace std;

struct element {

  element* nastepny;
  string wartosc;

  element(string wart_pocz) { nastepny = NULL; wartosc = wart_pocz; }
  element() { nastepny = NULL; }
  
};

#endif
