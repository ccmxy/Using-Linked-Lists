#include "data.h"
#include <iostream>
#include <iomanip>
using namespace std;

/*
Default constructor.
*/
data::data()
{
	address = NULL;
	bedrooms = 0;
	bathrooms = 0;
	squareFeet = 0;
	specialFeatures = NULL;
}

/*
Copy Constructor. 
*/
data::data(const data& item) 
{
	address = NULL;
	specialFeatures = NULL;
	setAddress(item.address);
	setBedrooms(item.bedrooms);
	setBathrooms(item.bathrooms);
	setSquareFeet(item.squareFeet);
	setSpecialFeatures(item.specialFeatures);
}

/*
Destructor.
*/
data::~data()
{
	if (address != NULL)
		delete[] address;
	if (specialFeatures != NULL)
		delete[] specialFeatures;
}

/*
Precondition: address (the passed in c-string) is a non-empty char array. The data object that this function is being accessed from has an empty char poiter member called address.
Postcondition: The data member called "address" is filled with the passed in char array.
*/
void data::getAddress(char *address)const
{
	strcpy(address, this->address);
}

int data::getBedrooms(void) const
{
	return bedrooms;
}

int data::getBathrooms(void) const
{
	return bathrooms;
}

int data::getSquareFeet(void) const
{
	return squareFeet;
}

void data::getSpecialFeatures(char *specialFeatures)const
{
	strcpy(specialFeatures, this->specialFeatures);
}

/*
Postcondition: The instance variable's address char array, set by the default constructor, is deleted, and the contents of the passed in char array are loaded into it.
*/
void data::setAddress(const char *address)
{
	if (this->address)
		delete[] this->address;

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

void data::setSpecialFeatures(const char *specialFeatures)
{
	if (this->specialFeatures)
		delete[] this->specialFeatures;
	this->specialFeatures = new char[strlen(specialFeatures) + 1];
	strcpy(this->specialFeatures, specialFeatures);
}

void data::setBedrooms(int bedrooms)
{
	this->bedrooms = bedrooms;
}

void data::setBathrooms(int bathrooms)
{
	this->bathrooms = bathrooms;
}

void data::setSquareFeet(int squareFeet)
{
	this->squareFeet = squareFeet;
}

/*
Operator overloader for data objects. When cout is used on a data object, the object's items will be displayed.
*/
ostream& operator<< (ostream& out, const data& item) //cout is a member of the class ostream
{
	out << setw(20) << item.address << setw(5) << item.bedrooms << setw(5) << item.bathrooms << setw(5) << item.squareFeet << setw(25) << item.specialFeatures;
	return out;
}

/*
Operator overloader for assignment operator. Makes it so that one data item can be assigned to another.
*/
const data& data::operator= (const data& item)
{
	if (this == &item)
		return *this;
	else
	{
		setAddress(item.address);
		setBedrooms(item.bedrooms);
		setBathrooms(item.bathrooms);
		setSquareFeet(item.squareFeet);
		setSpecialFeatures(item.specialFeatures);
		return *this;
	}
}