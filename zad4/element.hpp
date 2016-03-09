#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <iostream>
#include <string>
using namespace std;

struct element {

  element* nastepny;
  int dane;

  element(int dane_pocz) { nastepny = NULL; dane = dane_pocz; }
  element() { nastepny = NULL; }
  
};

#endif
