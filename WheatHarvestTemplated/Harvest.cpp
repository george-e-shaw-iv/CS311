/*
 * File Name: Harvest.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 7
 */

#include "Array.h"
#include "Ticket.h"
#include "Input.h"
#include "Output.h"

#include <algorithm>

// Sort friend function
bool sort(const Ticket& ticket1, const Ticket& ticket2) {
	bool less = false;

	int t1 = 0, t2 = 0;
	if(ticket1.sample) {
		t1 = ticket1.sample->getTypeValue();
	}
	if(ticket2.sample) {
		t2 = ticket2.sample->getTypeValue();
	}

	if(t1 < t2) {
		less = true;
	} else if(t1 == t2 && ticket1.calculateNetBushels() >= ticket2.calculateNetBushels()) {
		less = true;
	}

	return less;
}

int main() {
	ContainerTemplate::Array<Ticket> t;

	Input::inputTickets(t);
	std::sort(t.begin(), t.end(), sort);
	Output::outputTickets(t);
}
