#include <iostream>
#include <string>

#include "Input.h"

void Input::inputTickets(Tickets& tickets) {
	if(tickets.size() > 0) {
		std::cin.ignore(256, '\n');
	}

	std::string number;
	double inputGrossWeight, inputTareWeight, inputMoistureLevel, inputForeignMaterial;

	std::cout << "Ticket Number " << tickets.size() + 1 << " (alphanumeric): ";
	std::cin >> number;

	if (number == "") return;

	std::cout << "Gross weight (lbs): ";
	std::cin >> inputGrossWeight;

	std::cout << "Tare weight (lbs): ";
	std::cin >> inputTareWeight;

	std::cout << "Moisture level (\%): ";
	std::cin >> inputMoistureLevel;

	std::cout << "Foreign Material (\%): ";
	std::cin >> inputForeignMaterial;

	Ticket proposedTicket(number, inputGrossWeight, inputTareWeight, Grain(inputMoistureLevel,
				inputForeignMaterial));

	if (tickets.size() > 0) {
		bool duplicate = false;

		for(int i = 0; i < tickets.size(); i++) {
			if(tickets[i] == proposedTicket) {
				duplicate = true;
				break;
			}
		}

		if (duplicate) {
			std::cout << std::endl << "Error: Duplicate ticket encountered, ticket ignored!" << std::endl;
		} else {
			tickets.add(proposedTicket);
		}
	} else {
		tickets.add(proposedTicket);
	}

	std::cout << std::endl;
}
