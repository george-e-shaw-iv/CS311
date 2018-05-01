/*
 *	File Name: Soybean.cpp
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 7
 */

#include "Soybean.h"

namespace {
	const double AVG_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.0;
}

/*
	Default constructor for class Soybean which uses constructor delegation
	use the constructor of its parent class, grain.
*/
Soybean::Soybean() : Grain(0, 0)
{}

/*
	Overloaded constructor for class Soybean which uses constructor delegation
	to make use of its parent class, grain.

	@param "moistureLevel" of type double
		The value to initailize member variable moistureLevel
	@param "foreignMaterial" of type double
		The value to initailize member variable foreignMaterial
*/
Soybean::Soybean(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{}

/*
	Function clone returns a copy of pointer to the calling object

	@return Soybean
		A copy of the pointer of the calling object.
*/
Soybean* Soybean::clone() const {
	return new Soybean(*this);
}

/*
	Function getType gets the string representation of the calling object's
	class name

	@return sting
		"Soybean", the name of the class
*/
std::string Soybean::getType() const {
	return "Soybean";
}

/*
	Function getIdealMoistureLevel returns the constant ideal moisture level
	of Soybean

	@return const double
		The ideal moisture level of Soybean
*/
const double Soybean::getIdealMoistureLevel() const {
	return IDEAL_MOISTURE_LEVEL;
}

/*
	Function getAverageTestWeight returns the constant average test weight
	of Soybean

	@return const double
		The average test weight of Soybean
*/
const double Soybean::getAverageTestWeight() const {
	return AVG_TEST_WEIGHT;
}

// Converts type to a defined integer
int Soybean::getTypeValue() const {
	return 2;
}
