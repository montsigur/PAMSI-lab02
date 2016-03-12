#include "klasa_kolejka.hpp"
#include "klasa_lista.hpp"
using namespace std;

int main() {

  lista l1;
  kolejka k1;
  element* elem;
  string dane("ciag1");

  elem = new element(dane);
  l1.dodaj(elem);

  dane = string("ciag2");
  elem = new element(dane);
  l1.dodaj(elem);

  dane = string("ciag3");
  elem = new element(dane);
  l1.dodaj(elem);

  l1.zdejmij();
  l1.zdejmij();
  l1.zdejmij();
  elem = l1.zdejmij();

  //cout << elem->wartosc << endl;

  //delete elem;
  l1.wyczysc();
  
  return 0;

}
