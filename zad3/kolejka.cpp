#include <iostream>
#include <string>
using namespace std;

struct element_kolejki {

  element_kolejki* nastepny;
  string wartosc;

};

element_kolejki* stworzKolejke() {

  return NULL;
  
}

element_kolejki* stworzElement(string wartosc) {

  element_kolejki* element = new element_kolejki;
  element->nastepny = NULL;
  element->wartosc = wartosc;

  return element;
  
}

bool czyJestPusta(element_kolejki* poczatek_kolejki) {

  if (poczatek_kolejki == NULL)
    return true;

  else
    return false;

}

element_kolejki* usunZwrocPierwszy(element_kolejki* &poczatek_kolejki,
				   element_kolejki* &koniec_kolejki) {

  element_kolejki* pierwszy = poczatek_kolejki;
  
  if (czyJestPusta(poczatek_kolejki))    
    cout << "Blad. Kolejka jest pusta." << endl;

  else if (poczatek_kolejki == koniec_kolejki)
    poczatek_kolejki = koniec_kolejki = NULL;

  else {
    
    poczatek_kolejki = poczatek_kolejki->nastepny;
    pierwszy->nastepny = NULL;

  }
    
  return pierwszy;
}

void dodajNaKoniec(element_kolejki* &poczatek_kolejki,
		   element_kolejki* &koniec_kolejki,
		   element_kolejki* element) {

  if (czyJestPusta(poczatek_kolejki))
    poczatek_kolejki = koniec_kolejki = element;
  
  else {

    koniec_kolejki->nastepny = element;
    element->nastepny = NULL;
    koniec_kolejki = element;
    
  }
}

void wyswietlZawartosc(element_kolejki* &poczatek_kolejki) {

  element_kolejki* elem = poczatek_kolejki;

  if (czyJestPusta(poczatek_kolejki))
    cout << "Blad. Kolejka jest pusta." << endl;

  else {

    cout << "Zawartosc kolejki:" << endl;
    
    while (elem != NULL) {

      cout << elem->wartosc << endl;
      elem = elem->nastepny;
      
    }
  }
}

void usunWszystkie(element_kolejki* &poczatek_kolejki) {

  if (!czyJestPusta(poczatek_kolejki)) {

    element_kolejki* element;
    
    while (poczatek_kolejki != NULL) {
      element = poczatek_kolejki;
      poczatek_kolejki = poczatek_kolejki->nastepny;
      delete element;
      
    }
  }
}

int rozmiar(element_kolejki* poczatek_kolejki) {

  int ilosc = 0;
  element_kolejki* iterator = poczatek_kolejki;

  if (czyJestPusta(poczatek_kolejki))
    return 0;

  else {

    while (iterator != NULL) {
      
      ilosc++;
      iterator = iterator->nastepny;
      
    }
  }

  return ilosc;
}
  
int main() {

  element_kolejki* poczatek = stworzKolejke();
  element_kolejki* koniec = poczatek;
  element_kolejki *elem;

  string dane;
  int wybor = -1;

  string menu = "\t################# MENU #################\n\
\t1 - dodaj na poczatek kolejki\n\
\t2 - wyswietl zawartosc kolejki\n\
\t3 - zdejmij i wyswietl poczatek kolejki\n\
\t4 - sprawdz rozmiar kolejki\n\
\t5 - wyczysc kolejke\n\
\t6 - wyswietl menu\n\
\t0 - wyjscie z programu\n";

  cout << endl << menu;
  
  while (wybor != 0) {

    cout << endl << "Wybor (6 - wyswietl menu): ";

    cin >> wybor;
    cout << endl;

    switch(wybor) {

    case 1:
      cout << "Dane: ";
      cin >> dane;
      elem = stworzElement(dane);
      dodajNaKoniec(poczatek, koniec, elem);
      elem = NULL;
      break;
      
    case 2:
      wyswietlZawartosc(poczatek);
      break;

    case 3:
      elem = usunZwrocPierwszy(poczatek, koniec);
      if (elem != NULL)
	cout << "Zwrocona wartosc z kolejki: " << elem->wartosc << endl;
      break;
      
    case 4:
      cout << "Rozmiar kolejki: " << rozmiar(poczatek) << endl;
      break;
      
    case 5:
      usunWszystkie(poczatek);
      break;

    case 6:
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
