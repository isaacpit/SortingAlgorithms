/*
	Isaac Pitblado
  Carly Fohn
  Shane Manley 
	section 512
	Programming Assignment 2
	PA2.cpp
*/

#pragma once
#include <string>
using namespace std;

struct Flight 
{
  std::string flightNum;
  std::string destination;
  std::string departureTime;
  std::string gateNum;

  Flight();
  Flight(std::string fn, std::string dest, std::string dt, std::string gn);
  ~Flight();
  //...
};

ostream& operator<<(ostream& os, const Flight& f);

//compare this Flight object against another Flight object
//returns true if this object is >= other
bool compareToDestination(Flight f1, Flight f2);
bool compareToDepartureTime(Flight f1, Flight f2);
