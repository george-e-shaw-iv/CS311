/*
 * File Name: Grain.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 4
 */

#include "Grain.h"

namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 12.0;
}

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
	Function getAverageTestWeight returns the constant for the average
	weight per bushel.

	@return const double
		The average weight per bushel
*/
const double Grain::getAverageTestWeight() const {
	return AVERAGE_TEST_WEIGHT;
}

/*
	Function getIdealMoistureLevel returns the constant for the ideal
	moisture level.

	@return const double
		The ideal moisture level
*/
const double Grain::getIdealMoistureLevel() const {
	return IDEAL_MOISTURE_LEVEL;
}

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
