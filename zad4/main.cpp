// Wojciech Michałowski
// nr albumu 218705

#include "kolejka.hpp"
#include "lista.hpp"
using namespace std;

int main() {

  lista l1;
  kolejka k1;
  element* elem = NULL;
  string dane;
  int wybor = -1;

  string menu = "\t################# MENU #################\n\
\t 1 - dodaj na poczatek listy\n\
\t 2 - wyswietl zawartosc listy\n\
\t 3 - zdejmij i wyswietl poczatek listy\n\
\t 4 - sprawdz rozmiar listy\n\
\t 5 - wyczysc liste\n\n\
\t 6 - dodaj na poczatek kolejki\n\
\t 7 - wyswietl zawartosc kolejki\n\
\t 8 - zdejmij i wyswietl poczatek kolejki\n\
\t 9 - sprawdz rozmiar kolejki\n\
\t10 - wyczysc kolejke\n\n\
\t11 - wyswietl menu\n\
\t 0 - wyjscie z programu\n";

  cout << endl << menu;
  
  while (wybor != 0) {

    cout << endl << "Wybor (11 - wyswietl menu): ";

    cin >> wybor;
    cout << endl;

    switch(wybor) {

    case 1:
      cout << "Dane: ";
      cin >> dane;
      elem = new element(dane);
      l1.dodaj(elem);
      elem = NULL;
      break;
      
    case 2:
      l1.zawartosc();
      break;

    case 3:
      elem = l1.zdejmij();
      if (elem != NULL)
	cout << "Zwrocona wartosc z listy: " << elem->wartosc << endl;
      break;
      
    case 4:
      cout << "Rozmiar listy: " << l1.rozmiar() << endl;
      break;
      
    case 5:
      l1.wyczysc();
      break;
      
    case 6:
      cout << "Dane: ";
      cin >> dane;
      elem = new element(dane);
      k1.dodaj(elem);
      elem = NULL;
      break;
      
    case 7:
      k1.zawartosc();
      break;

    case 8:
      elem = k1.zdejmij();
      if (elem != NULL)
	cout << "Zwrocona wartosc z kolejki: " << elem->wartosc << endl;
      break;
      
    case 9:
      cout << "Rozmiar kolejki: " << k1.rozmiar() << endl;
      break;
      
    case 10:
      k1.wyczysc();
      break;

    case 11:
      cout << menu;

    case 0:
      break;
      
    default:
      cout << "Nieznana opcja" << endl;
      break;

    }     
  }

  if (elem != NULL)
    delete elem;
 
  return 0;
}
