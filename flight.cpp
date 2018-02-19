/*
	Isaac Pitblado
  Carly Fohn
  Shane Manley 
	section 512
	Programming Assignment 2
	PA2.cpp
*/

#include "flight.h"
#include "iostream"

using namespace std;

Flight::Flight()
{
  flightNum = "";
  destination = "";
  departureTime = "";
  gateNum = "";
}

Flight::Flight(std::string fn, std::string dest, std::string dt, std::string gn)
{
  flightNum = fn;
  destination = dest;
  departureTime = dt;
  gateNum = gn;
}

Flight::~Flight()
{
}

ostream& operator<<(ostream& os, const Flight& f) {
  os << f.flightNum;
  os.width(5);
  os << " | ";
  os.width(30);
  os << f.destination << " | ";
  os << f.departureTime;
  os << " | ";
  os << f.gateNum;


  return os;
}

bool compareToDestination(Flight f1, Flight f2)
{

  if (f1.destination >= f2.destination ) {
    return true;
  }
  else {
      return false;
  }

}

bool compareToDepartureTime(Flight f1, Flight f2)
{
  if (f1.departureTime >= f2.departureTime) {
    return true;
  }
  else {
    return false;
  }
}
