/*
 *	File Name: Output.h
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 7
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Array.h"
#include "Ticket.h"

class Output {
public:
	// Output list of tickets
	static void outputTickets(const ContainerTemplate::Array<Ticket>& tickets);

private:
	// Default constructor (use private to prevent creation)
	Output();
};

#endif
