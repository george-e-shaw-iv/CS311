/*
 * File Name: Output.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 5
 */

#include <iostream>
#include <ios>

#include "Output.h"

/*
	Function outputTickets outputs the contents of a Tickets class

	@param "tickets" of type Tickets
		The tickets class to output
*/
void Output::outputTickets(const Tickets& tickets) {
	for(int i = 0; i < tickets.size(); i++) {
		std::cout << tickets[i] << std::endl;
	}
}

/*
	Function outputSummary outputs the net and gross amounts of bushels
	within a Tickets class

	@param "tickets" of type Tickets
		The tickets class to output
*/
void Output::outputSummary(const Tickets& tickets) {
	std::ios_base::fmtflags f(std::cout.flags());

	double grossBushels = 0, netBushels = 0;
	for(int i = 0; i < tickets.size(); i++) {
		grossBushels += tickets[i].calculateGrossBushels();
		netBushels += tickets[i].calculateNetBushels();
	}

	std::cout.precision(2);
	std::cout << std::fixed << "Harvest Summary Totals" << std::endl;
	std::cout << "\t" << grossBushels << " Gross Bushels" << std::endl;
	std::cout << "\t" << netBushels << " Net Bushels" << std::endl;

	std::cout.flags(f);
}
