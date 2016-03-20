#include <iostream>
#include <string>
using namespace std;

struct element_listy {

  element_listy* poprzedni;
  string wartosc;

};

element_listy* stworzListe() {

  return NULL;

}

element_listy* stworzElement(string wartosc) {

  element_listy* element = new element_listy;
  element->poprzedni = NULL;
  element->wartosc = wartosc;

  return element;
  
}

bool czyJestPusta(element_listy* koniec_listy) {

  if (koniec_listy == NULL)
    return true;

  else
    return false;

}

element_listy* usunZwrocOstatni(element_listy* &koniec_listy) {

  element_listy* ostatni = koniec_listy;

  if (czyJestPusta(koniec_listy))
    cout << "Blad. Lista jest pusta." << endl;

  else {
    
    koniec_listy = koniec_listy->poprzedni;
    ostatni->poprzedni = NULL;
    
  }

  return ostatni;
}

void wyswietlZawartosc(element_listy* &koniec_listy) {

  element_listy* elem = koniec_listy;

  if (czyJestPusta(koniec_listy))
    cout << "Blad. Lista jest pusta." << endl;

  else {

    cout << "Zawartosc listy:" << endl;
    
    while (elem != NULL) {

      cout << elem->wartosc << endl;
      elem = elem->poprzedni;
      
    }
  }

}

void dodajNaKoniec(element_listy* &koniec_listy,
		   element_listy* element) {

  if (czyJestPusta(koniec_listy)) {
    
    koniec_listy = element;
    element->poprzedni = NULL;

  }

  else {

    element->poprzedni = koniec_listy;
    koniec_listy = element;
    
  }
}

void usunWszystkie(element_listy* &koniec_listy) {

  if (!czyJestPusta(koniec_listy)) {

    element_listy* element;
    
    while (koniec_listy != NULL) {
      element = koniec_listy;
      koniec_listy = koniec_listy->poprzedni;
      delete element;
      
    }
  }
}


int rozmiar(element_listy* koniec_listy) {

  int ilosc = 0;
  element_listy* iterator = koniec_listy;

  if (czyJestPusta(koniec_listy))
    return 0;

  else {

    while (iterator != NULL) {
      
      ilosc++;
      iterator = iterator->poprzedni;
      
    }
  }

  return ilosc;
}


int main() {

  element_listy* koniec = stworzListe();
  element_listy *elem;

  string dane;
  int wybor = -1;

  string menu = "\t################# MENU #################\n\
\t1 - dodaj na poczatek listy\n\
\t2 - wyswietl zawartosc listy\n\
\t3 - zdejmij i wyswietl poczatek listy\n\
\t4 - sprawdz rozmiar listy\n\
\t5 - wyczysc liste\n\
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
      dodajNaKoniec(koniec, elem);
      elem = NULL;
      break;
      
    case 2:
      wyswietlZawartosc(koniec);
      break;

    case 3:
      elem = usunZwrocOstatni(koniec);
      if (elem != NULL)
	cout << "Zwrocona wartosc z listy: " << elem->wartosc << endl;
      break;
      
    case 4:
      cout << "Rozmiar listy: " << rozmiar(koniec) << endl;
      break;
      
    case 5:
      usunWszystkie(koniec);
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
