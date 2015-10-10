#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;
class data
{
public:

	data();
	data(const data& item);	//copy constructor: make current object a copy of "item"
	~data(); //destructor

	void getAddress(char *address) const;
	int getBathrooms(void) const;
	int getBedrooms(void) const;
	int getSquareFeet(void) const;
	void getSpecialFeatures(char *specialFeatures) const;

	//mutators
	void setAddress(const char *address);
	void setBedrooms(int bedrooms);
	void setBathrooms(int bathrooms);
	void setSquareFeet(int squareFeet);
	void setSpecialFeatures(const char * specialFeatures);

	//operator overloaders
	friend ostream& operator<< (ostream& out, const data& item);  //friend to access the private members (displays them)
	const data& operator= (const data& item); //overload assignment operator

private:
	char *address;
	char *specialFeatures;
	int bedrooms;
	int bathrooms;
	int squareFeet;
};

#endif