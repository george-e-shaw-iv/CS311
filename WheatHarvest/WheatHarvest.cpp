#include <iostream>
#include "Ticket.h"

int main() {
	Ticket myTicket;

	std::string stringInput;
	double doubleInput;
	bool inputError;

	while(true) {
		std::cout << "Ticket Number: ";
		std::cin >> stringInput;

		inputError = myTicket.setNumber(stringInput);
		if(inputError) {
			break;
		}

		std::cout << "Please enter a valid alpha-numeric ticket number." << std::endl;
	}

	while(true) {
		std::cout << "Gross weight (lbs): ";
		std::cin >> doubleInput;

		inputError = myTicket.setGrossWeight(doubleInput);
		if(inputError) {
			break;
		}

		std::cout << "Please enter a valid non-zero and non-negative gross weight." << std::endl;
	}

	while(true) {
		std::cout << "Tare weight (lbs): ";
		std::cin >> doubleInput;

		inputError = myTicket.setTareWeight(doubleInput);
		if(inputError) {
			break;
		}

		std::cout << "Please enter a valid non-zero and non-negative tare weight." << std::endl;
	}

	while(true) {
		std::cout << "Moisture level (%): ";
		std::cin >> doubleInput;

		inputError = myTicket.setMoistureLevel(doubleInput);
		if(inputError) {
			break;
		}

		std::cout << "Please enter a valid moisture percentage between 0-100." << std::endl;
	}

	while(true) {
		std::cout << "Foriegn material (%): ";
		std::cin >> doubleInput;

		inputError = myTicket.setForiegnMaterial(doubleInput);
		if(inputError) {
			break;
		}

		std::cout << "Please enter a valid foriegn matieral percentage between 0-100." << std::endl;
	}

	std::cout << "Ticket " << myTicket.getNumber() << ":" << std::endl;
	std::cout << "\t" << myTicket.getGrossWeight() << " Gross Weight" << std::endl;
	std::cout << "\t" << myTicket.getTareWeight() << " Tare Weight" << std::endl;
	std::cout << "\t" << myTicket.calculateNetWeight() << " Net Weight" << std::endl << std::endl;
	std::cout << "\t" << myTicket.calculateGrossBushels() << " Gross Bushels" << std::endl;
	std::cout << "\t" << myTicket.calculateMoistureDockage() << " Moisture Level (" << myTicket.getMoistureLevel() <<
		")" << std::endl;
	std::cout << "\t" << myTicket.calculateForiegnDockage() << " Foriegn Material (" << myTicket.getForiegnMaterial() <<
		")" << std::endl;
	std::cout << "\t" << myTicket.calculateNetBushels() << " Net Bushels" << std::endl;
}
