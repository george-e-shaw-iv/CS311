#include "Ticket.h"

const double AVG_LBS_PER_BUSHEL = 60;
const double AVG_MOISTURE_LEVEL = 12;

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
	return true;
}

bool Ticket::setForiegnMaterial(double input) {
	if(input < 0 || input > 100) {
		return false;
	}

	this->foriegnMaterial = input;
	return true;
}

std::string Ticket::getNumber() {
	return this->number;
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
	double r = (this->grossWeight - this->tareWeight);
	return r;
}

double Ticket::calculateGrossBushels() {
	double r =  (this->calculateNetWeight() / AVG_LBS_PER_BUSHEL);
	return r;
}

double Ticket::calculateMoistureDockage() {
	if(this->moistureLevel <= AVG_MOISTURE_LEVEL) {
		return 0;
	}

	double r = (this->calculateGrossBushels() * ((this->moistureLevel - AVG_MOISTURE_LEVEL)/100));
	return r;
}

double Ticket::calculateForiegnDockage() {
	double r = (this->calculateGrossBushels() * (this->foriegnMaterial/100));
	return r;
}

double Ticket::calculateNetBushels() {
	double r = (this->calculateGrossBushels() - this->calculateMoistureDockage() - this->calculateForiegnDockage());
	return r;
}
