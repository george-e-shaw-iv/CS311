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

/*
 * Function Ticket is the constructor for the class Ticket.
 *
 * @param "reference" of type string
 *		Initial value of member variable "number". Indicates the ticket
 *		reference number.
 * @param "grossWeight" of type double
 *		Intial value of member variable "grossWeight". Indicates the
 *		weight of the truck before the load has been dumped.
 * @param "tareWeight" of type double
 *		Intial value of member variable "tareWeight". Indicates the
 *		weight of the truck after its load has been dumped.
 * @param "moistureLevel" of type double
 *		Initial value of member variable "moistureLevel". Indicates
 *		moisture level of the wheat intake in the form of a percentage.
 * @param "foriegnMaterial" of type double
 *		Initial value of member variable "foriegnMaterial". Indicates
 *		the amount of foriegn material in the wheat intake in the form
 *		of a percetnage.
 *
 * @return void
 */
Ticket::Ticket(std::string reference, double grossWeight, double tareWeight, double moistureLevel, double
		foriegnMaterial) : number(reference), grossWeight(grossWeight), tareWeight(tareWeight),
	moistureLevel(moistureLevel), foriegnMaterial(foriegnMaterial) {}

/*
 * Overloaded == operator to compare two Ticket class types. The comparison
 * takes place between the ticketNumber member variables between the two objects.
 *
 * @param "comapreTicket" of type Ticket
 *		The ticket to compare the calling Ticket object to
 *
 * @return bool
 *		True if calling Ticket and parameter Ticket have the same ticketNumber
 *		member variable.
 */
bool Ticket::operator==(const Ticket compareTicket) {
	return (this->number == compareTicket.number);
}

/*
 * Function toString returns a reciept for the Ticket.
 *
 * @return string
 *		A string representation of a reciept for the referenced ticket.
 */
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

/*
 * Function getNumber returns the member variable "number"
 *
 * @return string
 *		The value of the member variable "number"
 */
std::string Ticket::getNumber() const {
	return this->number;
}

/*
 * Function getGrossWeight returns the member variable "grossWeight"
 *
 * @return double
 *		The value of the member variable "grossWeight"
 */
double Ticket::getGrossWeight() const {
	return this->grossWeight;
}

/*
 * Function getTareWeight returns the member variable "tareWeight"
 *
 * @return double
 *		The value of the member variable "tareWeight"
 */
double Ticket::getTareWeight() const {
	return this->tareWeight;
}

/*
 * Function getMoistureLevel returns the member variable "moistureLevel"
 *
 * @return double
 *		The value of the member variable "moistureLevel"
 */
double Ticket::getMoistureLevel() const {
	return this->moistureLevel;
}

/*
 * Function getForiegnMaterial returns the member variable "foriegnMaterial"
 *
 * @return double
 *		The value of the member variable "foriegnMaterial"
 */
double Ticket::getForiegnMaterial() const {
	return this->foriegnMaterial;
}

/*
 * Function calculateNetWeight returns the net weight of the bushel intake.
 *
 * @return double
 *		Member variable "grossWeight" minus member variable "tareWeight"
 */
double Ticket::calculateNetWeight() const {
	return (this->grossWeight - this->tareWeight);
}

/*
 * Function calculateGrossBushels returns the amount of bushels before subtracting dockage
 *
 * @return double
 *		Return value of member function "calculateNetWeight" divided by the average
 *		pounds per bushel, which is 60.
 */
double Ticket::calculateGrossBushels() const {
	return (this->calculateNetWeight() / AVG_LBS_PER_BUSHEL);
}

/*
 * Function calculateMoistureDockage returns the dockage amount due to moisture levels
 * in the intake, if the moisture level percentage given was above 12%, exclusive.
 *
 * @return double
 *		Returns 0 if moisture level is less than or equal to 12 percent. If greater than 12
 *		percent the function returns the return value of "calculateGrossBushels" multipled by
 *		the member variable "moistureLevel" subtract 12.
 */
double Ticket::calculateMoistureDockage() const {
	if(this->moistureLevel <= AVG_MOISTURE_LEVEL) {
		return 0;
	}

	return (this->calculateGrossBushels() * ((this->moistureLevel - AVG_MOISTURE_LEVEL)/100));
}

/*
 * Function calculateForiegnDockage returns the dockage amount due to foriegn material
 * within the intake.
 *
 * @return double
 *		The return value of "calculateGrossBushels" multipled by the member variable
 *		"foriegnMaterial".
 */
double Ticket::calculateForiegnDockage() const {
	return (this->calculateGrossBushels() * (this->foriegnMaterial/100));
}

/*
 * Function calculateNetBushels returns the amount of net bushels intaked after dockage
 *
 * @return double
 *		The return value of "calculateGrossBushels" subtract the return value of
 *		"calculateMoistureDockage" subtract the return value of "calculateForiegnDockage"
 */
double Ticket::calculateNetBushels() const {
	return (this->calculateGrossBushels() - this->calculateMoistureDockage() - this->calculateForiegnDockage());
}