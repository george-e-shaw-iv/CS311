/*
 * File Name: Ticket.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 4
 */

#include <sstream>
#include <iostream>

#include "Ticket.h"

/*
 * Overloaded insertion operator (<<) is used to output a reciept of the ticket
 * with the help of the private member function toString.
 *
 * @param "os" of type pointer to ostream
 *		The stream attempting to output the Ticket reciept
 * @param "t" of type constant pointer to Ticket
 *		The ticket object attempting to be outputted
 *
 * @return ostream
 *		The returned manipulated stream
 */
std::ostream& operator<<(std::ostream &os, const Ticket &t) {
	os << t.toString();
	return os;
}

/*
	Ticket default constructor sets the timestamp member variable to the current
	time and the rest of the member variables to 0 values.
*/
Ticket::Ticket() : number(""), grossWeight(0), tareWeight(0) {
   time(&this->timestamp);
}

/*
	Function getTimestamp returns the member variable timestamp.

	@return time_t
		The timestamp member variable
*/
std::time_t Ticket::getTimestamp() const {
   return this->timestamp;
}

/*
	Function getForeignMaterial returns the foreign material percentage attached to
	the grain member variable

	@return double
		The foreign material percentage of the grain member variable
*/
double Ticket::getForeignMaterial() const {
   return this->sample.getForeignMaterial();
}

/*
	Function getMoistureLevel returns the moisture level percentage attached to
	the grain member variable

	@return double
		The moisture level percentage of the grain member variable
*/
double Ticket::getMoistureLevel() const {
   return this->sample.getMoistureLevel();
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
 * @param "sample" of type Grain
 *		The grain sample attached to the ticket
 *
 * @return void
 */
Ticket::Ticket(const std::string& number, const int grossWeight, const int tareWeight, const Grain& sample) :
	number(number), grossWeight(grossWeight), tareWeight(tareWeight), sample(sample) {
      time(&this->timestamp);
}

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
bool Ticket::operator ==(const Ticket& ticket) const {
	return (this->number == ticket.number);
}

/*
 * Function toString returns a reciept for the Ticket.
 *
 * @return string
 *		A string representation of a reciept for the referenced ticket.
 */
std::string Ticket::toString() const {
   char buff[20];
   strftime(buff, 20, "%D %T", localtime(&this->timestamp));

	std::stringstream ss;

	ss.precision(2);
	ss << std::fixed;

	ss << "Ticket " << this->number << " - " << buff << ":" << std::endl;
	ss << "\t" << this->grossWeight << " Gross Weight" << std::endl;
	ss << "\t" << this->tareWeight << " Tare Weight" << std::endl;
	ss << "\t" << this->calculateNetWeight() << " Net Weight" << std::endl << std::endl;
	ss << "\t" << this->calculateGrossBushels() << " Gross Bushels" << std::endl;
	ss << "\t" << this->calculateMoistureDockage() << " Moisture Level (" << this->getMoistureLevel() << "%)" <<
		std::endl;
	ss << "\t" << this->calculateForeignMaterialDockage() << " Foriegn Material (" << this->getForeignMaterial() << "%)" <<
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
int Ticket::getGrossWeight() const {
	return this->grossWeight;
}

/*
 * Function getTareWeight returns the member variable "tareWeight"
 *
 * @return double
 *		The value of the member variable "tareWeight"
 */
int Ticket::getTareWeight() const {
	return this->tareWeight;
}

/*
 * Function calculateNetWeight returns the net weight of the bushel intake.
 *
 * @return double
 *		Member variable "grossWeight" minus member variable "tareWeight"
 */
int Ticket::calculateNetWeight() const {
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
	return (this->calculateNetWeight() / this->sample.getAverageTestWeight());
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
	if(this->getMoistureLevel() <= this->sample.getIdealMoistureLevel()) {
		return 0;
	}

	return (this->calculateGrossBushels() * ((this->getMoistureLevel() - this->sample.getIdealMoistureLevel())/100));
}

/*
 * Function calculateForeignMaterialDockage returns the dockage amount due to foriegn material
 * within the intake.
 *
 * @return double
 *		The return value of "calculateGrossBushels" multipled by the member variable
 *		"foriegnMaterial".
 */
double Ticket::calculateForeignMaterialDockage() const {
	return (this->calculateGrossBushels() * (this->getForeignMaterial()/100));
}

/*
 * Function calculateNetBushels returns the amount of net bushels intaked after dockage
 *
 * @return double
 *		The return value of "calculateGrossBushels" subtract the return value of
 *		"calculateMoistureDockage" subtract the return value of "calculateForeignMaterialDockage"
 */
double Ticket::calculateNetBushels() const {
	return (this->calculateGrossBushels() - this->calculateMoistureDockage() - this->calculateForeignMaterialDockage());
}
