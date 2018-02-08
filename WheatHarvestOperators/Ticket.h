/*
 * File Name: Ticket.h
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 3
 */

#include <string>

class Ticket {
public:
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
	Ticket(std::string reference, double grossWeight, double tareWeight, double moistureLevel, double foriegnMaterial);
	
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
	bool operator==(const Ticket compareTicket);

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
	friend std::ostream& operator<<(std::ostream &os, const Ticket &t);

	/*
	 * Function getNumber returns the member variable "number"
	 *
	 * @return string
	 *		The value of the member variable "number"
	 */
	std::string getNumber() const;

	/*
	 * Function getGrossWeight returns the member variable "grossWeight"
	 *
	 * @return double
	 *		The value of the member variable "grossWeight"
	 */
	double getGrossWeight() const;

	/*
	 * Function getTareWeight returns the member variable "tareWeight"
	 *
	 * @return double
	 *		The value of the member variable "tareWeight"
	 */
	double getTareWeight() const;

	/*
	 * Function getMoistureLevel returns the member variable "moistureLevel"
	 *
	 * @return double
	 *		The value of the member variable "moistureLevel"
	 */
	double getMoistureLevel() const;

	/*
	 * Function getForiegnMaterial returns the member variable "foriegnMaterial"
	 *
	 * @return double
	 *		The value of the member variable "foriegnMaterial"
	 */
	double getForiegnMaterial() const;

	/*
	 * Function calculateNetWeight returns the net weight of the bushel intake.
	 *
	 * @return double
	 *		Member variable "grossWeight" minus member variable "tareWeight"
	 */
	double calculateNetWeight() const;

	/*
	 * Function calculateGrossBushels returns the amount of bushels before subtracting dockage
	 *
	 * @return double
	 *		Return value of member function "calculateNetWeight" divided by the average
	 *		pounds per bushel, which is 60.
	 */
	double calculateGrossBushels() const;

	/*
	 * Function calculateMoistureDockage returns the dockage amount due to moisture levels
	 * in the intake, if the moisture level percentage given was above 12%, exclusive.
	 *
	 * @return double
	 *		Returns 0 if moisture level is less than or equal to 12 percent. If greater than 12
	 *		percent the function returns the return value of "calculateGrossBushels" multipled by
	 *		the member variable "moistureLevel" subtract 12.
	 */
	double calculateMoistureDockage() const;

	/*
	 * Function calculateForiegnDockage returns the dockage amount due to foriegn material
	 * within the intake.
	 *
	 * @return double
	 *		The return value of "calculateGrossBushels" multipled by the member variable
	 *		"foriegnMaterial".
	 */
	double calculateForiegnDockage() const;

	/*
	 * Function calculateNetBushels returns the amount of net bushels intaked after dockage
	 *
	 * @return double
	 *		The return value of "calculateGrossBushels" subtract the return value of
	 *		"calculateMoistureDockage" subtract the return value of "calculateForiegnDockage"
	 */
	double calculateNetBushels() const;
	
private:
	std::string number;
	double grossWeight, tareWeight, moistureLevel, foriegnMaterial;

	/*
	 * Function toString returns a reciept for the Ticket.
	 *
	 * @return string
	 *		A string representation of a reciept for the referenced ticket.
	 */
	std::string toString() const;
};
