/*
 * File Name: Harvest.cpp
 * Author: George Shaw
 * Student ID: G829G576
 * Assignment Number: 4
 */

#include "Tickets.h"
#include "Input.h"
#include "Output.h"

int main() {
	Tickets t;

	Input::inputTickets(t);
	Output::outputTickets(t);
	Output::outputSummary(t);
}
