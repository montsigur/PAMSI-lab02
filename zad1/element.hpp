// Wojciech Michałowski
// nr albumu 218705

#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <iostream>
#include <string>
using namespace std;

struct element {

  element* nastepny;
  element* poprzedni;
  string wartosc;

  element(string wart_pocz) {

    nastepny = NULL;
    poprzedni = NULL;
    wartosc = wart_pocz;

  }

  element() {
    nastepny = NULL;
    poprzedni = NULL;

  }
};

#endif
