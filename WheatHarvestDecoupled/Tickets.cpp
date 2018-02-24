#include "Tickets.h"

Tickets::Tickets() : ticketArrayCapacity(0), ticketArraySize(0) {
	this->ticketArray = new Ticket[this->ticketArrayCapacity];
}

Tickets::Tickets(const Tickets& tickets) {
	this->ticketArray = new Ticket[tickets.ticketArrayCapacity];

	for(unsigned int i = 0; i < tickets.ticketArraySize; i++) {
		this->ticketArray[i] = tickets.ticketArray[i];
	}

	this->ticketArrayCapacity = tickets.ticketArrayCapacity;
	this->ticketArraySize = tickets.ticketArraySize;
}

Tickets::~Tickets() {
	delete[] this->ticketArray;
}

const Tickets& Tickets::operator =(const Tickets& tickets) {
	if(&tickets == this) {
		return *this;
	}

	this->ticketArray = new Ticket[tickets.ticketArrayCapacity];

	for(unsigned int i = 0; i < tickets.ticketArraySize; i++) {
		this->ticketArray[i] = tickets.ticketArray[i];
	}

	this->ticketArrayCapacity = tickets.ticketArrayCapacity;
	this->ticketArraySize = tickets.ticketArraySize;

	return *this;
}

Ticket Tickets::operator [](unsigned int index) const {
	if(index <= ticketArraySize) {
		return ticketArray[index];
	}
	return Ticket();
}

int Tickets::size() const {
	return this->ticketArraySize;
}

void Tickets::add(const Ticket& ticket) {
	this->ticketArraySize++;

	if(this->ticketArraySize > this->ticketArrayCapacity) {
		this->ticketArrayCapacity = this->ticketArraySize + 3;
		Ticket *newTicketArray = new Ticket[this->ticketArrayCapacity];

		for(unsigned int i = 0; i < this->ticketArraySize - 1; i++) {
			newTicketArray[i] = this->ticketArray[i];
		}
		newTicketArray[this->ticketArraySize - 1] = ticket;

		delete[] this->ticketArray;
		this->ticketArray = newTicketArray;

		return;
	}

	this->ticketArray[this->ticketArraySize - 1] = ticket;
}
