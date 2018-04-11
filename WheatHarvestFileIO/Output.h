/*
 *	File Name: Output.h
 *	Author: George Shaw
 *	Student ID: G829G576
 *	Assignment Number: 6
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Tickets.h"

class Output {
public:
	// Output list of tickets
	static void outputTickets(const Tickets& tickets);

private:
	// Default constructor (use private to prevent creation)
	Output();
};

#endif
