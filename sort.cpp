/*
name
section
assignment
file
*/

#include "sort.h"
#include <iostream>

//use this to keep track of comparisons
int num_cmps;

using namespace std;

std::vector<Flight> selection_sort(std::vector<Flight> flights,
				   SortOption sortOpt)
{
  if (ByDepartureTime) {
    for (int i = 0; i < flights.size()-1; ++i) {
      if (compareToDepartureTime(flights.at(i), flights.at(i+1)) && num_cmps++) {
        Flight min = flights.at(i+1) ;
        flights.at(i+1) = flights.at(i);
        flights.at(i) = min;
        cout << num_cmps << " "; 
      }
    }
  }
  cout << endl;
  return flights;
}

std::vector<Flight> insertion_sort(std::vector<Flight> flights,
				   SortOption sortOpt)
{
  return flights;
}

std::vector<Flight> bubble_sort(std::vector<Flight> flights,
				SortOption sortOpt)
{
  return flights;
}
