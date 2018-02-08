/*
 * File Name: Ticket.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 3
 */

#include <sstream>
#include <iostream>
#include "Ticket.h"

namespace {
	const double AVG_LBS_PER_BUSHEL = 60;
	const double AVG_MOISTURE_LEVEL = 12;
}

Ticket::Ticket(std::string reference, double grossWeight, double tareWeight, double moistureLevel, double
		foriegnMaterial) : number(reference), grossWeight(grossWeight), tareWeight(tareWeight),
	moistureLevel(moistureLevel), foriegnMaterial(foriegnMaterial) {}

bool Ticket::operator==(const Ticket compareTicket) {
	return (this->number == compareTicket.number);
}

std::string Ticket::toString() const {
	std::stringstream ss;

	ss.precision(2);
	ss << std::fixed;

	ss << "Ticket " << this->number << ":" << std::endl;
	ss << "\t" << this->grossWeight << " Gross Weight" << std::endl;
	ss << "\t" << this->tareWeight << " Tare Weight" << std::endl;
	ss << "\t" << this->calculateNetWeight() << " Net Weight" << std::endl << std::endl;
	ss << "\t" << this->calculateGrossBushels() << " Gross Bushels" << std::endl;
	ss << "\t" << this->calculateMoistureDockage() << " Moisture Level (" << this->moistureLevel << "%)" << 
		std::endl;
	ss << "\t" << this->calculateForiegnDockage() << " Foriegn Material (" << this->foriegnMaterial << "%)" <<
		std::endl;
	ss << "\t" << this->calculateNetBushels() << " Net Bushels" << std::endl;

	return ss.str();
}

std::string Ticket::getNumber() const {
	return this->number;
}

double Ticket::getGrossWeight() const {
	return this->grossWeight;
}

double Ticket::getTareWeight() const {
	return this->tareWeight;
}

double Ticket::getMoistureLevel() const {
	return this->moistureLevel;
}

double Ticket::getForiegnMaterial() const {
	return this->foriegnMaterial;
}

double Ticket::calculateNetWeight() const {
	double r = (this->grossWeight - this->tareWeight);
	return r;
}

double Ticket::calculateGrossBushels() const {
	double r = (this->calculateNetWeight() / AVG_LBS_PER_BUSHEL);
	return r;
}

double Ticket::calculateMoistureDockage() const {
	if(this->moistureLevel <= AVG_MOISTURE_LEVEL) {
		return 0;
	}

	double r = (this->calculateGrossBushels() * ((this->moistureLevel - AVG_MOISTURE_LEVEL)/100));
	return r;
}

double Ticket::calculateForiegnDockage() const {
	double r = (this->calculateGrossBushels() * (this->foriegnMaterial/100));
	return r;
}

double Ticket::calculateNetBushels() const {
	double r = (this->calculateGrossBushels() - this->calculateMoistureDockage() - this->calculateForiegnDockage());
	return r;
}
