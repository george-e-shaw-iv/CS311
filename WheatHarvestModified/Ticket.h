/*
 * File Name: Ticket.h
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 1
 */

#include <string>

class Ticket {
public:
	Ticket(std::string reference, double grossWeight, double tareWeight, double moistureLevel, double foriegnMaterial);

	/* GETTERS */
	std::string getNumber();
	double getGrossWeight();
	double getTareWeight();
	double getMoistureLevel();
	double getForiegnMaterial();

	/* CALCULATIONS */
	double calculateNetWeight();
	double calculateGrossBushels();
	double calculateMoistureDockage();
	double calculateForiegnDockage();
	double calculateNetBushels();
	
private:
	std::string number;
	double grossWeight, tareWeight, moistureLevel, foriegnMaterial;
};
