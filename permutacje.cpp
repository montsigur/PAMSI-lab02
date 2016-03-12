#include <string>
#include "zad4/klasa_kolejka.hpp"
using namespace std;

void Permutacje(string ciag_znakow, kolejka& permutacje, string permutacja="") {

  if (ciag_znakow.size() > 0) {

    for (unsigned int i = 0; i < ciag_znakow.size(); i++) {

      char znak_chr[1] {ciag_znakow[0]};
      string znak(znak_chr);
      string tymczasowy = ciag_znakow;
      tymczasowy.erase(i, 1);
      Permutacje(tymczasowy, permutacje, permutacja + znak);

    }
  }
  
  else {

    element* elem = new element(permutacja);
    permutacje.dodaj(elem);
    
  } 
}

int main() {

  string ciag("abcd");
  kolejka permutacje;
  element* elem;
  
  Permutacje(ciag, permutacje);

  while (true) {

    elem = permutacje.zdejmij();
    if (elem == NULL)
      break;
    cout << elem->wartosc << endl;
    delete elem;
    
  }
  
  return 0;

}
