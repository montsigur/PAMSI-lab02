#include "klasa_kolejka.hpp"
#include "klasa_lista.hpp"
using namespace std;

int main() {

  lista l1;
  kolejka k1;
  string dane;
  element* elem;

  dane = "elem1";
  elem = new element(dane);
  l1.dodaj(elem);

  dane = "elem2";
  elem = new element(elem);
  l1.dodaj(elem);

  dane = "elem3";
  elem = new element(elem);
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
