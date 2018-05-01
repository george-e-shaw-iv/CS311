/*
 * File Name: Grain.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 7
 */

#include "Grain.h"

/*
	Default constructor for grain class initializes member variables to 0.
*/
Grain::Grain() : moistureLevel(0), foreignMaterial(0)
{}

/*
	Parameterized constructor for grain class initializes member variables to
	the given parameters.

	@param "moistureLevel" of type double
		The value to initailize member variable moistureLevel
	@param "foreignMaterial" of type double
		The value to initailize member variable foreignMaterial
*/
Grain::Grain(double moistureLevel, double foreignMaterial) : moistureLevel(moistureLevel),
	foreignMaterial(foreignMaterial)
{}

/*
	Default deconstructor for grain class
*/
Grain::~Grain()
{}

/*
	Function getMoistureLevel returns the member variable for the moisture
	level in percentage.

	@return double
		The moisture level member variable value as a percentage.
*/
double Grain::getMoistureLevel() const {
	return this->moistureLevel;
}

/*
	Function getForeignMaterial returns the member variable for the foreign
	material level as a percentage.

	@return double
		The foreign material member variable value as a percentage
*/
double Grain::getForeignMaterial() const {
	return this->foreignMaterial;
}

/*
	Defined member function to call upon the virtual getType function that returns
	the string representation of the grain type.

	@return string
		The string representation of the calling object's most derived class
*/
std::string Grain::toString() const {
	return this->getType();
}
