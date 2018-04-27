/*
 * File Name: Output.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 6
 */

#include <iostream>
#include <ios>
#include <fstream>

#include "Output.h"

/*
	Function outputTickets outputs the contents of a Tickets class

	@param "tickets" of type Tickets
		The tickets class to output
*/
void Output::outputTickets(const Tickets& tickets) {
	std::ofstream outputFile;
	outputFile.open("HarvestTicketReceipts.txt", std::ios::out | std::ios::trunc);

	if(outputFile.is_open()) {
		for(int i = 0; i < tickets.size(); i++) {
			if(i == 0) outputFile << tickets[i].headerFields() << std::endl;
			outputFile << tickets[i].getRecord() << std::endl;
		}
	}

	outputFile.close();
}
