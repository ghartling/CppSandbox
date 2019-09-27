#include "stdafx.h"
#include "FavoriteNumber.h"
#include <iostream>

using namespace std;

FavoriteNumber::FavoriteNumber()
{
}


FavoriteNumber::~FavoriteNumber()
{
}

int FavoriteNumber::getFavoriteNumber() {
	int favoriteNumber = 0;
	int x;

	cout << "Enter your favorite number between 1 and 100: ";

	// read the number
	std::cin >> favoriteNumber;
	std::cout << "Amazing! That is my favorite too!" << std::endl;

	// output
	std::cout << "No really!!" << favoriteNumber << " is my favorite number" << std::endl;
	std::cin >> x;

	return 0;

}


int FavoriteNumber::printFavoriteNumber() {
	int favoriteNumber = 0;
	int x;

	cout << "Enter your favorite number between 1 and 100: ";

	// read the number
	std::cout << "Amazing! That is my favorite too!" << std::endl;

	// output
	std::cout << "No really!!" << favoriteNumber << " is my favorite number" << std::endl;

	return 0;

}

