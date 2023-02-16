#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <sstream>
#include "OperacjeNaStringach.h"
using namespace std;

string NaMaleLitery(string dana)
{
		std::transform(dana.begin(), dana.end(), dana.begin(),
		[](unsigned char c) { return std::tolower(c); });
		return dana;
}

void UsunSpacje(string& temp)
{
	temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
	temp.erase(remove(temp.begin(), temp.end(), '	'), temp.end());
	return;
}

bool CzyCyfry(const string& str)
{
	return all_of(str.begin(), str.end(), isdigit); 
}

bool CzyZawiera(const string &temp, string slowo)
	{
	if (temp.find(slowo) != string::npos)
		return true;
	else
		return false;
	}
