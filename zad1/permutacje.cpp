// Wojciech Michałowski
// nr albumu 218705

#include <string>
#include "../zad4/kolejka.hpp"
using namespace std;

void usunDup(kolejka &zbior) {

  kolejka bezPowt;
  element* elem;

  while (zbior.rozmiar() > 0) {

    elem = zbior.zdejmij();
    
    if (!bezPowt.zawiera_wartosc(elem->wartosc))
      bezPowt.dodaj(elem);

    else
      delete elem;
    
  }

  while (bezPowt.rozmiar() > 0)
    zbior.dodaj(bezPowt.zdejmij());
}

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


bool jestPalindromem(string napis) {

  int dlugosc = napis.size();
  string podNapis;

  if (dlugosc < 2)
    return true;

  else if (napis[0] == napis[dlugosc-1]) {

    for (int ind=1; ind<dlugosc-1; ind++)
      podNapis += napis[ind];

    return jestPalindromem(podNapis);
  }

  else
    return false;
}


int main() {

  string ciag;

  cout << "Ciag znakow: ";
  cin >> ciag;
  
  kolejka permutacje;
  kolejka palindromy;
  element* elem;


  Permutacje(ciag, ciag.size(), permutacje);

  while (permutacje.rozmiar() > 0) {

    elem = permutacje.zdejmij();
    cout << elem->wartosc << endl;
    
    if (jestPalindromem(elem->wartosc))
      palindromy.dodaj(elem);
    
    else
      delete elem;
  }

  if (palindromy.rozmiar() > 0) {

    cout << endl << "Znalezione palindromy:" << endl;

    usunDup(palindromy);
    
    while (palindromy.rozmiar() > 0) {

      elem = palindromy.zdejmij();
      cout << elem->wartosc << endl;
      delete elem;
      
    }
  }
  
  return 0;

}
