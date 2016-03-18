#include "deque.hpp"
using namespace std;

int main() {

  deque d1;
  element* elem;
  string dane("ciag_znakow");

  elem = new element(dane);
  d1.dodajNaPoczatek(elem);

  dane = string("ciag2");
  elem = new element(dane);
  d1.dodajNaKoniec(elem);

  dane = string("ciag3");
  elem = new element(dane);
  d1.dodajNaPoczatek(elem);

  cout << "Rozmiar: " << d1.rozmiar() << endl;

  elem = d1.zdejmijKoniec();
  cout << "Zdjeta wartosc: " << elem->wartosc << endl;

  cout << "Rozmiar: " << d1.rozmiar() << endl;

  delete elem;
  
  return 0;
  
}
