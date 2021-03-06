/*
	Isaac Pitblado
 	Carly Fohn
 	Shane Manley 
	section 512
	Programming Assignment 2
	PA2.cpp
*/

#pragma once
#include <vector>
#include <string>

#include "flight.h"

enum SortOption {
  ByDestination,
  ByDepartureTime
};

//implement each of these functions for their respective sort
std::vector<Flight> selection_sort(std::vector<Flight> flights,
				   SortOption sortOpt);

std::vector<Flight> insertion_sort(std::vector<Flight> flights,
				   SortOption sortOpt);

std::vector<Flight> bubble_sort(std::vector<Flight> flights,
				SortOption sortOpt);
