/*
	name
	section
	assignment
	file
*/


#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "sort.h"

std::vector<Flight> readFlights(std::string fileName);
using namespace std;

int main()
{
  Flight testFlight; 
  string file = "ascen10.csv";
  vector<Flight> flights;
  flights = readFlights(file);
  cout << "read file..." << endl;
  for (int i = 0; i < flights.size(); ++i) {
    cout << flights.at(i) << endl;
  }
  /*
    first read flights in files using readFlights()
    descen10.csv	ascen10.csv     rand10.csv
    descen100.csv	ascen100.csv	rand100.csv
    descen1000.csv	ascen1000.csv	rand1000.csv
    descen10000.csv ascen10000.csv	rand10000.csv
  */

  /*
    then use each of the sorting functions on each of the generated vectors
  */

  /*
    then output each of the resultant sorted vectors
    format them so that they look like the table of the front of the 
    instructions

    Flight Number	Destination Departure   Time	        Gate Number
    AA223			LAS VEGAS	21:15			A3
    BA023			DALLAS		21:00			A3
    AA220			LONDON		20:30			B4
    VI303			MEXICO		19:00			A7
    BA087			LONDON		17:45			A7
    AA342			PARIS		16:00			A7
    VI309			PRAGUE		13:20			F2
    QU607			TORONTO		08:30			F2
    AA224			SYDNEY		08:20			A7
    AF342			WASHINGTON	07:45			A3
  */

  /*
    then fill out the rest of the questions on the instructions 
    - the number of comparisons

    - to test your functions experimentally use difftime explained here 
    http://www.cplusplus.com/reference/ctime/time/
  */

  return 0;
}

string& removeDelim (string& str, char delim) {
  for (int i = 0; i < str.length(); ++i) {
    if (str.at(i) == delim) {
      str.at(i) = ' ';
    }
    else {
      // do nothing
    }
  }
  return str;
}


//read in the flights from the input file at fileName and store them in a vector
std::vector<Flight> readFlights(std::string fileName)
{
  std::vector<Flight> flights;
  // reads file
  ifstream is;
  is.open(fileName);
  if (!is) {
    cout << "could not read file\n";
  }
  else {
    cout << "reading file\n";
  }

  // temporary variables
  string tFN = "";
  string tD = "";
  string tDT = "";
  string tGN = "";
  string info = "";
  string nocommas = "";
  string header = "";

  char delim = ',';
  getline (is, header);


  // debug 
  cout << "header: " << header << endl;

  while (!is.eof()) {
    getline(is, info);
    cout << "info: " << info << endl;
    nocommas = removeDelim(info, delim);
    // debug
    cout << "nocommas: " << nocommas << endl;
    stringstream ss;
    ss << nocommas;
    ss >> tFN >> tD >> tDT >> tGN;
    cout << "variables:\n";
    cout << tFN << " " << tD << " " << tDT << " " << tGN << endl;
    Flight temp = Flight(tFN, tD, tDT, tGN);
    flights.push_back(temp);
  }
  
  return flights;
}

