/*
 *	File Name: Soybeans.h
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 5
 */

#ifndef SOYBEANS_H_
#define SOYBEANS_H_

#include "Grain.h"

class Soybeans : public Grain {
	public:
	// Default constructor definition
	Soybeans();
	
	// Overloaded class constructor to initialize protected variables within the base class
	Soybeans(double moistureLevel, double foreignMaterial);
	
	// Return a clone of the object
	Soybeans* clone() const;
	
	// Returns the string representation of the derived class name
	std::string getType() const;
	
	// Returns the constant for ideal moisture level for soybeans
	const double getIdealMoistureLevel() const;
	
	// Returns the constant for average test weight per bushel for soybeans
	const double getAverageTestWeight() const;
};

#endif
