/*
 *	File Name: Soybeans.cpp
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 5
 */

#include "Soybeans.h"

namespace {
	const double AVG_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.0;
}

/*
	Default constructor for class soybeans which uses constructor delegation
	use the constructor of its parent class, grain.
*/
Soybeans::Soybeans() : Grain(0, 0)
{}

/*
	Overloaded constructor for class soybeans which uses constructor delegation
	to make use of its parent class, grain.

	@param "moistureLevel" of type double
		The value to initailize member variable moistureLevel
	@param "foreignMaterial" of type double
		The value to initailize member variable foreignMaterial
*/
Soybeans::Soybeans(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{}

/*
	Function clone returns a copy of pointer to the calling object

	@return Soybeans
		A copy of the pointer of the calling object.
*/
Soybeans* Soybeans::clone() const {
	return new Soybeans(*this);
}

/*
	Function getType gets the string representation of the calling object's
	class name

	@return sting
		"Soybeans", the name of the class
*/
std::string Soybeans::getType() const {
	return "Soybeans";
}

/*
	Function getIdealMoistureLevel returns the constant ideal moisture level
	of soybeans

	@return const double
		The ideal moisture level of soybeans
*/
const double Soybeans::getIdealMoistureLevel() const {
	return IDEAL_MOISTURE_LEVEL;
}

/*
	Function getAverageTestWeight returns the constant average test weight
	of soybeans

	@return const double
		The average test weight of soybeans
*/
const double Soybeans::getAverageTestWeight() const {
	return AVG_TEST_WEIGHT;
}
