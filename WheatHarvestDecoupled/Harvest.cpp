#include "Tickets.h"
#include "Input.h"
#include "Output.h"

int main() {
	Tickets t;
	
	Input::inputTickets(t);
	Output::outputTickets(t);
	Output::outputSummary(t);
}
