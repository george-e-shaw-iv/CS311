/*
 *	File Name: Ticket.h
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 5
 */

#ifndef TICKET_H_
#define TICKET_H_

#include <ctime>
#include <ostream>
#include <string>

#include "Grain.h"

class Ticket {
public:
	// Constructor default
	Ticket();

	// Constructor allowing caller to specify a ticket's number,
	//  gross weight (lbs), tare weight (lbs), and grain sample
	Ticket(const std::string& number, const int grossWeight, const int tareWeight, const Grain& sample);

	// Accessor to return timestamp
	std::time_t getTimestamp() const;

	// Accessor to return number
	std::string getNumber() const;

	// Accessor to return gross weight (lbs)
	int getGrossWeight() const;

	// Accessor to return tare weight (lbs)
	int getTareWeight() const;

	// Function to return net weight (lbs)
	int calculateNetWeight() const;

	// Function to return gross bushels (lbs)
	double calculateGrossBushels() const;

	// Function to return moisture level dockage (lbs bushels)
	double calculateMoistureDockage() const;

	// Function to return foreign material dockage (lbs bushels)
	double calculateForeignMaterialDockage() const;

	// Function to return net bushels (lbs)
	double calculateNetBushels() const;

	// Grain foreign material accessor (percent)
	double getForeignMaterial() const;

	// Grain moisture level accessor (percent)
	double getMoistureLevel() const;

	// Returns a string representing ticket's attributes (in form of a receipt)
	std::string toString() const;

	// Overloaded equality operator ==
	bool operator ==(const Ticket& ticket) const;

	// Overloaded insertion operator <<
	friend std::ostream& operator <<(std::ostream& os, const Ticket& tickets);

private:
	// Member variables
	std::time_t timestamp;
	std::string number;
	int grossWeight;
	int tareWeight;
	Grain sample;
};

#endif
