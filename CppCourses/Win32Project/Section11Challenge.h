#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Section11Challenge
{
public:
	Section11Challenge(void);
	~Section11Challenge(void);
	int solution(void);
	char getMenuOption(void);
	int printNumbers(vector<int>);
	int addNumber(vector<int> &);

	double calcMean(vector<int>);
	int displaySmallest(vector<int>);
	int displayLargest(vector<int>);


};

