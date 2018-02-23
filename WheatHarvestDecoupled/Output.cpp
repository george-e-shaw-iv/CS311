#include <iostream>
#include <ios>

#include "Output.h"

void Output::outputTickets(const Tickets& tickets) {
	for(unsigned int i = 0; i < tickets.size(); i++) {
		std::cout << tickets[i] << std::endl;
	}
}

void Output::outputSummary(const Tickets& tickets) {
	std::ios_base::fmtflags f(std::cout.flags());

	double grossBushels = 0, netBushels = 0;
	for(unsigned int i = 0; i < tickets.size(); i++) {
		// add those up in here
	}

	std::cout.precision(2);
	std::cout << std::fixed << "Wheat Harvest Summary Totals" << std::endl;
	std::cout << "\t" << grossBushels << " Gross Bushels" << std::endl;
	std::cout << "\t" << netBushels << " Net Bushels" << std::endl;

	std::cout.flags(f);
}
