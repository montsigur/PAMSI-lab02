#include "kolejka.hpp"
#include "lista.hpp"
#include "deque.hpp"
using namespace std;

int main() {

  lista l1;
  kolejka k1;
  deque d1;
  element* elem;
  
  string dane("ciag1");
  elem = new element(dane);
  d1.dodajNaPoczatek(elem);

  dane = string("ciag2");
  elem = new element(dane);
  d1.dodajNaPoczatek(elem);

  dane = string("ciag3");
  elem = new element(dane);
  d1.dodajNaKoniec(elem);

  elem = d1.zdejmijKoniec();
  cout << elem->wartosc << endl;
  d1.zdejmijKoniec();
  elem = d1.zdejmijPoczatek();
  cout << elem->wartosc << endl;
  d1.zdejmijPoczatek();

  //cout << elem->wartosc << endl;

  delete elem;
  d1.wyczysc();
  
  return 0;

}
