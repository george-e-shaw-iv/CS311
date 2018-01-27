/*
 * File Name: Ticket.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 1
 */

#include "Ticket.h"

const double AVG_LBS_PER_BUSHEL = 60;
const double AVG_MOISTURE_LEVEL = 12;

Ticket::Ticket(std::string reference, double grossWeight, double tareWeight, double moistureLevel, double
		foriegnMaterial) : number(reference), grossWeight(grossWeight), tareWeight(tareWeight),
	moistureLevel(moistureLevel), foriegnMaterial(foriegnMaterial) {}

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
