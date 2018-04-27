/*
 *	File Name: Soybean.h
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 6
 */

#ifndef SOYBEAN_H_
#define SOYBEAN_H_

#include "Grain.h"

class Soybean : public Grain {
	public:
	// Default constructor definition
	Soybean();

	// Overloaded class constructor to initialize protected variables within the base class
	Soybean(double moistureLevel, double foreignMaterial);

	// Return a clone of the object
	Soybean* clone() const;

	// Returns the string representation of the derived class name
	std::string getType() const;

	// Returns the constant for ideal moisture level for Soybean
	const double getIdealMoistureLevel() const;

	// Returns the constant for average test weight per bushel for Soybean
	const double getAverageTestWeight() const;
};

#endif
