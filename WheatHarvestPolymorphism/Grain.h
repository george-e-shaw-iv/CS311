/*
 * Grain.h
 *
 *  Created on: Feb 9, 2018
 *      Author: Joe
 */

#include <string>

#ifndef GRAIN_H_
#define GRAIN_H_

/**
 * The Grain class identifies properties of a sample of grain
 */
class Grain {
public:
	// Constructor default
	Grain();

	// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
	Grain(double moistureLevel, double foreignMaterial);

	// Destructor
	virtual ~Grain();

	// Pure virtual accessor to return grain's average test weight (lbs/bushel)
	virtual const double getAverageTestWeight() const = 0;

	// Pure virtual accessor to return grain's ideal moisture level (percent)
	virtual const double getIdealMoistureLevel() const = 0;

	// Accessor to return sample's moisture level (percent)
	double getMoistureLevel() const;

	// Accessor to return sample's foreign material (percent)
	double getForeignMaterial() const;

	// Pure virtual function to return a copy of the calling object
	virtual &Grain clone() const = 0;

	// Pure virtual function to get string representation of the calling object's grain type
	virtual std::string getType() const = 0;

	// Defined member function to make use of the pure virtual function getType
	std::string toString() const;

private:
	// Member variables
	double moistureLevel;
	double foreignMaterial;
};

#endif /* GRAIN_H_ */
