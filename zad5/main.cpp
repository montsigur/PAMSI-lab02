// Wojciech Michałowski
// nr albumu 218705

#include "deque.hpp"
using namespace std;

bool jestPalindromem(deque &ciag_znakow) {

  if (ciag_znakow.rozmiar() < 2)
    return true;

  else if (ciag_znakow.zdejmijPoczatek()->wartosc == ciag_znakow.zdejmijKoniec()->wartosc)
    return jestPalindromem(ciag_znakow);

  else
    return false;

}

int main() {

  deque d1;
  deque ciag_znakow;
  element* elem = NULL;
  string dane;
  int wybor = -1;

  string menu = "\t################# MENU #################\n\
\t 1 - dodaj na poczatek\n\
\t 2 - dodaj na koniec\n\
\t 3 - sprawdz poczatek\n\
\t 4 - sprawdz koniec\n\
\t 5 - zdejmij i wyswietl poczatek\n\
\t 6 - zdejmij i wyswietl koniec\n\
\t 7 - sprawdz rozmiar\n\
\t 8 - wyczysc\n\n\
\t 9 - czy ciag znakow jest palindromem\n\
\t10 - wyswietl menu\n\
\t 0 - wyjscie z programu\n";

  cout << endl << menu;
  
  while (wybor != 0) {

    cout << endl << "Wybor (10 - wyswietl menu): ";

    cin >> wybor;
    cout << endl;

    switch(wybor) {

    case 1:
      cout << "Dane: ";
      cin >> dane;
      elem = new element(dane);
      d1.dodajNaPoczatek(elem);
      elem = NULL;
      break;
      
    case 2:
      cout << "Dane: ";
      cin >> dane;
      elem = new element(dane);
      d1.dodajNaKoniec(elem);
      elem = NULL;
      break;

    case 3:
      elem = d1.sprawdzPoczatek();
      if (elem != NULL)
	cout << "Poczatek listy: " << elem->wartosc << endl;
      elem = NULL;
      break;
      
   case 4:
      elem = d1.sprawdzKoniec();
      if (elem != NULL)
	cout << "Koniec listy: " << elem->wartosc << endl;
      elem = NULL;
      break;
      
    case 5:
      elem = d1.zdejmijPoczatek();
      if (elem != NULL)
	cout << "Zwrocona wartosc: " << elem->wartosc << endl;
      break;
      
    case 6:
      elem = d1.zdejmijKoniec();
      if (elem != NULL)
	cout << "Zwrocona wartosc: " << elem->wartosc << endl;
      break;
      
    case 7:
      cout << "Rozmiar: " << d1.rozmiar() << endl;
      break;

    case 8:
      d1.wyczysc();
      break;

    case 9:
      cout << "Podaj ciag znakow: ";
      cin >> dane;
      
      for (unsigned int i=0; i < dane.size(); i++) {

	elem = new element(dane.substr(i, 1));
	ciag_znakow.dodajNaPoczatek(elem);

      }

      if (jestPalindromem(ciag_znakow))
	cout << dane << " jest palindromem." << endl;
      else
	cout << dane << " nie jest palindromem." << endl;

      ciag_znakow.wyczysc();      
      break;
      
    case 10:
      cout << menu;
      break;
      
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
