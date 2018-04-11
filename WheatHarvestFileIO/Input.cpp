/*
 * File Name: Input.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 6
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ios>

#include "Input.h"
#include "Wheat.h"
#include "Milo.h"
#include "Soybeans.h"

enum columnType {
	type = 0,
	date = 1,
	timestamp = 2,
	number = 3,
	grossWeight = 4,
	tareWeight = 5,
	moistureLevel = 6,
	foreignMaterial = 7
};

/*
	Function inputTickets encapsulates the input of tickets

	@param "tickets" of type Tickets
		The tickets class to input the tickets into
*/
void Input::inputTickets(Tickets& tickets) {
	std::ifstream inputFile;
	int column;
	inputFile.open("HarvestTickets.txt", std::ios::in);

	if(inputFile.is_open()) {
		std::string currentLine, currentField;
		while(getline(inputFile, currentLine)) {
			if(currentLine[0] == '\n') continue;

			column = 0;
			std::string inputNumber, inputType, inputDate, inputTimestamp;
			double inputGrossWeight, inputTareWeight, inputMoistureLevel, inputForeignMaterial;
			bool failed, outOfBounds;
			failed = outOfBounds = false;

			std::stringstream delimetedStream(currentLine);
			while(getline(delimetedStream, currentField, '|')) {
				unsigned int i;

				// Remove whitespace before field
				for(i = 0; i < currentField.size(); i++) {
					if(currentField[i] != ' ') break;
				}
				currentField.erase(0, i);

				// Remove whitespace after the field
				std::string whitespaces (" \t\f\v\n\r");

				std::size_t found = currentField.find_last_not_of(whitespaces);
			  if(found != std::string::npos) {
			    currentField.erase(found+1);
				}

				if(currentField[0] == '#') {
					failed = true;
					break;
				}

				switch(column) {
					case type:
						inputType = currentField;
						break;
					case date:
						inputDate = currentField;
						break;
					case timestamp:
						inputTimestamp = currentField;
						break;
					case number:
						inputNumber = currentField;
						break;
					case grossWeight:
						try {
							inputGrossWeight = std::stod(currentField);
						} catch(...) {
							failed = true;
						}
						break;
					case tareWeight:
						try {
							inputTareWeight = std::stod(currentField);
						} catch(...) {
							failed = true;
						}
						break;
					case moistureLevel:
						try {
							inputMoistureLevel = std::stod(currentField);
						} catch(...) {
							failed = true;
						}
						break;
					case foreignMaterial:
						try {
						inputForeignMaterial = std::stod(currentField);
						} catch(...) {
							failed = true;
						}
						break;
					default:
						outOfBounds = true;
						break;
				}

				if(failed || outOfBounds) break;
				column++;
			}

			if(failed) continue;

			//std::cout << inputType << "|" << inputNumber << "|" << inputMoistureLevel << "|" << inputForeignMaterial << "|" << inputGrossWeight << "|" << inputTareWeight << "|" << inputDate << "|" << inputTimestamp << std::endl;

			time_t t;
			try {
				std::string strTimestamp = inputDate + " " + inputTimestamp;
				const char *timestamp = strTimestamp.c_str();

				struct tm tm;
				strptime(timestamp, "%Y-%m-%d %H:%M:%S", &tm);
				t = mktime(&tm);
			} catch(...) {
				break;
			}

			Ticket proposedTicket;
			if(inputType == "Wheat") {
				{
					Grain *w = new Wheat(inputMoistureLevel, inputForeignMaterial);
					proposedTicket = Ticket(inputNumber, inputGrossWeight, inputTareWeight, t, w);
				}
			} else if(inputType == "Soybean") {
				{
					Grain *s = new Soybeans(inputMoistureLevel, inputForeignMaterial);
					proposedTicket = Ticket(inputNumber, inputGrossWeight, inputTareWeight, t, s);
				}
			} else if(inputType == "Grain Sorghum") {
				{
					Grain *m = new Milo(inputMoistureLevel, inputForeignMaterial);
					proposedTicket = Ticket(inputNumber, inputGrossWeight, inputTareWeight, t, m);
				}
			} else {
				failed = true;
			}

			if(failed) continue;

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
		}
	}

	inputFile.close();
}
