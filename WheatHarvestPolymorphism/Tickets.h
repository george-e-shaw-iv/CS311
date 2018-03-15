/*
 *	File Name: Tickets.h
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 5
 */

#ifndef TICKETS_H_
#define TICKETS_H_

#include "Ticket.h"

class Tickets {
public:
	// Constructor default
	Tickets();

	// Copy constructor
	Tickets(const Tickets& tickets);

	// Destructor
	~Tickets();

	// Add a ticket to the array of tickets
	void add(const Ticket& ticket);

	// Return size of array of tickets (number of tickets in array)
	int size() const;

	// Overloaded assignment operator =
	const Tickets& operator =(const Tickets& tickets);

	// Overloaded array operator []
	Ticket operator [](unsigned int index) const;

private:
	// Member variables
	Ticket *ticketArray;				// Pointer to array of tickets
	unsigned int ticketArrayCapacity;	// Number of tickets the array currently has space for
	unsigned int ticketArraySize;		// Number of tickets added to the array
};

#endif
