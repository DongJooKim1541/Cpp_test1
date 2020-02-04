#ifndef COUNTRY_H
#define COUNTRY_H
class Country {
public:
	char* CountryName;
	int Points;
	Country();
	Country(char* name, int point);
	Country(const Country& c);
	~Country();
	void setPoints(int point);
	void setCountryName(char* name);
	void Print();
};
#endif
