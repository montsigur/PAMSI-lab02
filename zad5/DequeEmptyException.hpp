// Wojciech Michałowski
// nr albumu 218705

#ifndef DEQUEEMPTYEXCEPTION_HPP
#define DEQUEEMPTYEXCEPTION_HPP
#include <exception>
using namespace std;

class DequeEmptyException: public exception {

public:
  
  virtual char const* what() const throw() {

    return "Blad. Lista jest pusta.";
    
  }
};

#endif
