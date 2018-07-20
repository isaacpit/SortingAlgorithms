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
  if (sortOpt == ByDepartureTime) {
    int minIndex = 0;
    for (int i = 0; i < flights.size(); ++i) {
      // set minimum element equal to first item 
      minIndex = i;
      for (int j = i + 1; j < flights.size(); ++j) {
        // cout << "current minIndex: " << minIndex << endl;
        if (j >= flights.size()-1) {
          // last case
          if (compareToDepartureTime(flights.at(j), flights.at(minIndex)) 
          && num_cmps++) {
            // minIndex is index of smallest item case
            Flight min = flights.at(minIndex);
            flights.at(minIndex) = flights.at(i);
            flights.at(i) = min; 
          }
          else {
            // minIndex is greater than current item
            minIndex = j;
            Flight min = flights.at(minIndex);
            flights.at(minIndex) = flights.at(i);
            flights.at(i) = min;
          }

        }
        else if (compareToDepartureTime(flights.at(j), flights.at(minIndex)) 
        && num_cmps++) {
          // do nothing bc flights.at(j) > flights.at(minIndex)
        }
        else {
          // since flights.at(j) < flights.at(minIndex), switch them
          minIndex = j;
        }
      }
    }
  }

  else if (sortOpt == ByDestination) {
    int minIndex = 0;
    for (int i = 0; i < flights.size(); ++i) {
      // set minimum element equal to first item 
      minIndex = i;
      for (int j = i + 1; j < flights.size(); ++j) {
        // cout << "current minIndex: " << minIndex << endl;
        if (j >= flights.size()-1) {
          // last case
          if (compareToDestination(flights.at(j), flights.at(minIndex)) 
          && num_cmps++) {
            // minIndex is index of smallest item case
            Flight min = flights.at(minIndex);
            flights.at(minIndex) = flights.at(i);
            flights.at(i) = min; 
          }
          else {
            // minIndex is greater than current item
            minIndex = j;
            Flight min = flights.at(minIndex);
            flights.at(minIndex) = flights.at(i);
            flights.at(i) = min;
          }

        }
        else if (compareToDestination(flights.at(j), flights.at(minIndex)) 
        && num_cmps++) {
          // do nothing bc flights.at(j) > flights.at(minIndex)
        }
        else {
          // since flights.at(j) < flights.at(minIndex), switch them
          minIndex = j;
        }
      }
    }
  }

  // cout << endl;
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
