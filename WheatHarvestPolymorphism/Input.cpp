/*
 * File Name: Input.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 5
 */

#include <iostream>
#include <string>

#include "Input.h"
#include "Wheat.h"
#include "Milo.h"
#include "Soybeans.h"

// Enumerated type for the type of grain
enum Type {
	WHEAT = 'w',
	MILO = 'g',
	SOYBEAN = 's'
};

/*
	Function inputTickets encapsulates the input of tickets

	@param "tickets" of type Tickets
		The tickets class to input the tickets into
*/
void Input::inputTickets(Tickets& tickets) {
	while(true) {
		if(tickets.size() > 0) {
			std::cin.ignore(256, '\n');
		}

		std::string number;
		double inputGrossWeight, inputTareWeight, inputMoistureLevel, inputForeignMaterial;
		char grainType;

		std::cout << "Ticket Number " << tickets.size() + 1 << " (alphanumeric): ";
		std::getline(std::cin, number);

		if (number == "") break;

		std::cout << "Gross weight (lbs): ";
		std::cin >> inputGrossWeight;

		std::cout << "Tare weight (lbs): ";
		std::cin >> inputTareWeight;

		std::cout << "Moisture level (\%): ";
		std::cin >> inputMoistureLevel;

		std::cout << "Foreign Material (\%): ";
		std::cin >> inputForeignMaterial;

		std::cout << "Grain type (w)heat, (s)oybean, (g)rain sorghum: ";
		std::cin >> grainType;

		Ticket proposedTicket;
		switch(grainType) {
			case WHEAT:
				{
					Grain *w = new Wheat(inputMoistureLevel, inputForeignMaterial);
					proposedTicket = Ticket(number, inputGrossWeight, inputTareWeight, w);
				}
				break;
			case MILO:
				{
					Grain *m = new Milo(inputMoistureLevel, inputForeignMaterial);
					proposedTicket = Ticket(number, inputGrossWeight, inputTareWeight, m);
				}
				break;
			case SOYBEAN:
				{
					Grain *s = new Soybeans(inputMoistureLevel, inputForeignMaterial);
					proposedTicket = Ticket(number, inputGrossWeight, inputTareWeight, s);
				}
				break;
			default:
				{
					Grain *w = new Wheat(inputMoistureLevel, inputForeignMaterial);
					proposedTicket = Ticket(number, inputGrossWeight, inputTareWeight, w);
				}
				break;
		}

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

	std::cout << std::endl;
}
