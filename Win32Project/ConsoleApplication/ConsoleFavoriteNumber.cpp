#include "stdafx.h"
#include "ConsoleFavoriteNumber.h"
#include <iostream>

using  namespace std;


ConsoleFavoriteNumber::ConsoleFavoriteNumber()
{
}


ConsoleFavoriteNumber::~ConsoleFavoriteNumber()
{
}

int ConsoleFavoriteNumber::printFavoriteNumber() {
	int favoriteNumber = 0;
	int x;

	cout << "Enter your favorite number between 1 and 100: ";

	// read the number
	std::cout << "Amazing! That is my favorite too!" << std::endl;

	// output
	std::cout << "No really!!" << favoriteNumber << " is my favorite number" << std::endl;

	return 0;

}
