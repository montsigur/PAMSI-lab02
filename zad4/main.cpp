#include "klasa_kolejka.hpp"
#include "klasa_lista.hpp"
using namespace std;

int main() {

  lista l1;
  kolejka k1;
  element* elem;

  elem = new element(5);
  l1.dodaj(elem);

  elem = new element(7);
  l1.dodaj(elem);

  elem = new element(78);
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
