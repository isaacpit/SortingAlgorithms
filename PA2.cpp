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
  string file = "rand10.csv";
  vector<Flight> flights;
  flights = readFlights(file);

  // debug code to verify that .csv's are read correctly
  // cout << "\nread file successfully..." << endl;
  // ofstream out;
  // string ofile = "output.txt";
  // out.open(ofile);
  // cout << "\nvector flights contents:\n";
  // for (int i = 0; i < flights.size(); ++i) {
  //   cout << "\ni: " << i  << "\nflight: " << flights.at(i) << endl;
  //   out << flights.at(i) << endl;
  // }

  // debug: selection sort by departure time 
  cout << "Selection Sort: By Departure Time";
  SortOption s = ByDepartureTime;
  vector<Flight> sortedTime = selection_sort(flights, s);
  for (int i = 0; i < sortedTime.size(); ++i) {
    cout << "i: " << i << " " << sortedTime.at(i) << endl;
  }

  // debug: selection sort by departure time
  cout << "SelectionSort: By Destination";
  SortOption s2 = ByDestination;
  vector<Flight> sortedDest = selection_sort(flights, s2);
  for (int i = 0; i < sortedDest.size(); ++i) {
    cout << "i: " << i << " " << sortedDest.at(i) << endl;
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

// converts a stringstream to Flight class
Flight ssToFlight (stringstream& ss) {

  bool first = 0; bool second = 0; bool third = 0; bool fourth = 0;
  string s, tFN, tD, tDT, tGN = "";
  int i = 0;

  s = ss.str();
  while (s.length() > 0) {
    if (s.at(i) == ',' && first == false) {
      tFN = s.substr(0, i);
      // debug
      // cout << "tFN:" << tFN << endl;
      s = s.substr(i + 1,s.length());
      i = 0;
      first = true;
    } 
    else if (s.at(i) == ',' && second == false) {
      tD = s.substr(0, i);

      // debug
      // cout << "tD:" << tD << endl;
      s = s.substr(i + 1,s.length());
      i = 0;
      second = true;
    }
    else if (s.at(i) == ',' && third == false) {
      tDT= s.substr(0, i);
      // debug
      // cout << "tDT:" << tDT << endl;
      s = s.substr(i + 1,s.length());
      i = 0;
      third = true;
    }
    else if (i == s.length()-1 && fourth == false) {
      tGN = s.substr(0, i);
      // debug
      // cout << "tGN:" << tGN << endl;
      s = "";
      i = 0;
      Flight temp(tFN, tD, tDT, tGN);
      // debug
      // cout << "temp: " << temp << endl;
      return temp;
    }
    else {
      ++i;
    }
  }
  Flight Erroneous;
  return Erroneous;
}


//read in the flights from the input file at fileName and 
// store them in a vector
std::vector<Flight> readFlights(std::string fileName)
{
  // reads file
  ifstream is;
  is.open(fileName);
  if (!is) {
    // cout << "could not read file\n";
  }
  else {
    // cout << "reading file\n";
  }

  // temporary variables
  vector<Flight> flights;
  string tFN = "", tD = "", tDT = "", tGN = "" , info = "", 
    nocommas = "", header = "";
  char delim = ',';
  getline (is, header);

  // debug 
  // cout << "header: " << header << endl;

  int i = 0;

  // cout << "in readFlights() function:\n";
  while (!is.eof()) {

    // first grab line up to new line character, then place into
    // a string
    getline(is, info, '\n');

    // debug
    // cout << info << endl;
    // place this string into a stringstream

    stringstream ss;
    ss << info;

    // debug
    // cout << ss.str() << endl;
    // use ssToFlight to convert this stringstream to a 
    // Flight instance

    Flight tempFlight = ssToFlight(ss);
    flights.push_back(tempFlight);
    ss.clear();

    // debug: 
    // cout << "\ni: " << i << endl;
    // cout << flights.at(i);
    // ++i;


  }
  flights.erase(flights.end()-1);
  return flights;
}

