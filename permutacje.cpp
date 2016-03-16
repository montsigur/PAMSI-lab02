#include <string>
#include "zad4/klasa_kolejka.hpp"
using namespace std;

// Przy pierwszym wywolaniu funkcji n to dlugosc ciagu znakow
void Permutacje(string &ciag_znakow, unsigned int n, kolejka& permutacje) {

  if (n == 1) {

    element* elem = new element(ciag_znakow);
    permutacje.dodaj(elem);
    
  }

  else {

    for (unsigned int i = 0; i < n-1; i++) {

      Permutacje(ciag_znakow, n-1, permutacje);
      
      if (n % 2 == 0) {

        string znak = ciag_znakow.substr(n-1, 1);
	ciag_znakow.replace(n-1, 1, ciag_znakow.substr(i, 1));
	ciag_znakow.replace(i, 1, znak);
	
      }
      
      else {
	string znak = ciag_znakow.substr(n-1, 1);
	ciag_znakow.replace(n-1, 1, ciag_znakow.substr(0, 1));
	ciag_znakow.replace(0, 1, znak);
      }
    }
    
    Permutacje(ciag_znakow, n-1, permutacje);
  }
}

int main() {

  string ciag;

  cout << "Ciag znakow: ";
  cin >> ciag;
  
  kolejka permutacje;
  kolejka palindromy;
  element* elem;
  
  Permutacje(ciag, ciag.size(), permutacje);

  while (true) {

    elem = permutacje.zdejmij();
    if (elem == NULL)
      break;
    cout << elem->wartosc << endl;
    delete elem;
    
  }
  
  return 0;

}
