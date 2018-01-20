#include "Ticket.h"

const double AVG_LBS_PER_BUSHEL = 60;
const double AVG_MOISTURE_LEVEL = 60;

bool Ticket::setNumber(std::string input) {
	if(input == "") {
		return false;
	}

	this->number = input;
	return true;
}

bool Ticket::setGrossWeight(double input) {
	if(input <= 0) {
		return false;
	}

	this->grossWeight = input;
	return true;
}

bool Ticket::setTareWeight(double input) {
	if(input <= 0) {
		return false;
	}

	this->tareWeight = input;
	return true;
}

bool Ticket::setMoistureLevel(double input) {
	if(input < 0 || input > 100) {
		return false;
	}

	this->moistureLevel = input;
}

bool Ticket::setForiegnMaterial(double input) {
	if(input < 0 || input > 100) {
		return false;
	}

	this->foriegnMaterial = input;
}

double Ticket::getGrossWeight() {
	return this->grossWeight;
}

double Ticket::getTareWeight() {
	return this->tareWeight;
}

double Ticket::getMoistureLevel() {
	return this->moistureLevel;
}

double Ticket::getForiegnMaterial() {
	return this->foriegnMaterial;
}

double Ticket::calculateNetWeight() {
	return (this->grossWeight - this->tareWeight);
}

double Ticket::calculateGrossBushels() {
	return (this->calculateNetWeight / AVG_LBS_PER_BUSHEL);
}

double Ticket::calculateMoistureDockage() {
	if(this->moistureLevel <= 12) {
		return 0;
	}

	return (this->calculateGrossBushels() * (this->moistureLevel/100));
}

double Ticket::calculateForiegnDockage() {
	return (this->calculateGrossBushels() * (this->foriegnMaterial/100));
}

double Ticket::calculateNetBushels() {
	return (this->calculateGrossBushels() - this->calculateMoistureDockage() - this->calculateForiegnDockage());
}
