#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <iostream>
#include <string>
using namespace std;

struct element {

  element* nastepny;
  string dane;

  element(string dane_pocz) { nastepny = NULL; dane = dane_pocz; }
  element() { nastepny = NULL; }
  
};

#endif
