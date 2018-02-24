#include "Grain.h"

namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 12.0;
}

Grain::Grain() : moistureLevel(0), foreignMaterial(0)
{}

Grain::Grain(double moistureLevel, double foreignMaterial) : moistureLevel(moistureLevel),
	foreignMaterial(foreignMaterial)
{}

Grain::~Grain()
{}

const double Grain::getAverageTestWeight() const {
	return AVERAGE_TEST_WEIGHT;
}

const double Grain::getIdealMoistureLevel() const {
	return IDEAL_MOISTURE_LEVEL;
}

double Grain::getMoistureLevel() const {
	return this->moistureLevel;
}

double Grain::getForeignMaterial() const {
	return this->foreignMaterial;
}
