/*
 *	File Name: Milo.h
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 7
 */

#ifndef MILO_H_
#define MILO_H_

#include "Grain.h"

class Milo : public Grain {
	public:
	// Default constructor definition
	Milo();

	// Overloaded class constructor to initialize protected variables within the base class
	Milo(double moistureLevel, double foreignMaterial);

	// Return a clone of the object
	Milo* clone() const;

	// Returns the string representation of the derived class name
	std::string getType() const;

	// Returns the constant for ideal moisture level for milo
	const double getIdealMoistureLevel() const;

	// Returns the constant for average test weight per bushel for milo
	const double getAverageTestWeight() const;

	// Converts type to a defined integer
	int getTypeValue() const;
};

#endif
