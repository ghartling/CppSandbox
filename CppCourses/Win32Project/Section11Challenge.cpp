#include "stdafx.h"
#include "Section11Challenge.h"
#include <iostream>
#include <vector>

using namespace std;


Section11Challenge::Section11Challenge(void)
{
}


Section11Challenge::~Section11Challenge(void)
{
}

int Section11Challenge::solution(void)
{
	vector<int> numbers
	;
	bool exitLoop = false;

	while(!exitLoop) {
		char option = getMenuOption();

		switch(option) {
		case 'P':
		case 'p':
			printNumbers(numbers);
			break;
		case 'A':
		case 'a':
			addNumber(numbers);
			break;
		case 'M':
		case 'm':
			calcMean(numbers);
			break;
		case 'S':
		case 's':
			displaySmallest(numbers);
			break;
		case 'L':
		case 'l':
			displayLargest(numbers);
			break;
		case 'Q':
		case 'q':
			cout<< "Goodbye"<<endl;
			exitLoop=true;
			break;
		default:
			cout<< "Unknown selection, please try again"<<endl;

			break;
		}
	}

	return 0;
}

char Section11Challenge::getMenuOption(void)
{
	cout << "P - print numbers" << endl;
	cout << "A - add a number" << endl;
	cout << "M - display mean of numbers" << endl;
	cout << "S - display the smallest number" << endl;
	cout << "L - display the largest number" << endl;
	cout << "Q - quit" << endl;
	cout << endl;

	char option = ' ';
	cin>>option;


	return option;
}

int Section11Challenge::printNumbers(vector<int> numbers)
{
	int size = numbers.size();

	if (size == 0) {
		cout << "[] - the list is empty" << endl;
	} else {
		cout <<"[";

		for(int i=0; i<size; ++i) {
			cout << numbers.at(i) << " ";
		}
		cout <<"]" << endl;
	}

	return 0;
}

int Section11Challenge::addNumber(vector<int> &numbers)
{
	int num = 0;

	cout <<"enter a number: ";
	cin >>num;

	numbers.push_back(num);
	cout <<num<<" added"<<endl;

	return num;
}

double Section11Challenge::calcMean(vector<int> numbers)
{
	int size = numbers.size();
	double mean = 0;
	double total = 0;

	if (size==0) {
		cout <<"Unable to calculate mean - no data"<<endl;
	} else {
		for(int i=0; i<size; ++i) {
			total+=numbers.at(i);
		}

		mean = total/size;
		cout <<"mean = " <<mean<< endl;
	}

	return mean;
}

int Section11Challenge::displayLargest(vector<int> numbers)
{
	int size = numbers.size();
	int max = MININT;

	if (size==0) {
		cout <<"Unable to determine largest number - list is empty"<<endl;
	} else {
		for(auto n : numbers) {
			if (n>max) {
				max = n;
			}
		}

		cout <<"max = " <<max<< endl;
	}

	return max;
}

int Section11Challenge::displaySmallest(vector<int> numbers)
{
	int size = numbers.size();
	int min = MAXINT;

	if (size==0) {
		cout <<"Unable to determine smallest number - list is empty"<<endl;
	} else {
		for(auto n : numbers) {
			if (n<min) {
				min = n;
			}
		}

		cout <<"min = " <<min<< endl;
	}

	return min;
}

