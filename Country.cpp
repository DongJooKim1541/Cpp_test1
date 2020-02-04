#include <iostream>
#include "Country.h"
using namespace std;
const int MAX = 30;

Country::Country() {
	CountryName = new char[MAX];
	CountryName = NULL;
	Points = 0;
}
Country::Country(char* name, int point) {
	CountryName = new char[strlen(name) + 1];
	strcpy_s(CountryName, strlen(name) + 1, name);
	Points = point;
}
Country::Country(const Country& c) {
	CountryName = new char[strlen(c.CountryName) + 1];
	strcpy_s(CountryName, strlen(c.CountryName) + 1, c.CountryName);
	Points = c.Points;
}
Country::~Country() {
	if (CountryName) {
		delete[] CountryName;
		CountryName = NULL;
	}
}
void Country::setPoints(int point) {
	Points = Points + point;
}
void Country::setCountryName(char* name) {
	CountryName = new char[strlen(name) + 1];
	strcpy_s(CountryName, strlen(name) + 1, name);
}
void Country::Print() {
	cout << "     " << CountryName << "        " << Points << endl;
}