#include "kolejka.hpp"
#include "lista.hpp"
using namespace std;

int main() {

  lista l1;
  kolejka k1;
  element* elem;
  
  string dane("ciag1");
  elem = new element(dane);
  k1.dodaj(elem);
  
  dane = string("ciag2");
  elem = new element(dane);
  k1.dodaj(elem);

  dane = string("ciag3");
  elem = new element(dane);
  k1.dodaj(elem);

  elem = k1.zdejmij();
  cout << elem->wartosc << endl;
  elem = k1.zdejmij();
  cout << elem->wartosc << endl;
  elem = k1.zdejmij();
  cout << elem->wartosc << endl;
  
  //cout << elem->wartosc << endl;

  delete elem;
  

  dane = string("ciag1");
  elem = new element(dane);
  l1.dodaj(elem);
  
  dane = string("ciag2");
  elem = new element(dane);
  l1.dodaj(elem);

  dane = string("ciag3");
  elem = new element(dane);
  l1.dodaj(elem);

  elem = l1.zdejmij();
  cout << elem->wartosc << endl;
  elem = l1.zdejmij();
  cout << elem->wartosc << endl;
  elem = l1.zdejmij();
  cout << elem->wartosc << endl;
  
  //cout << elem->wartosc << endl;

  delete elem;
  
  return 0;
}
