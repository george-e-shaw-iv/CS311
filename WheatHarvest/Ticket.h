#include <string>

class Ticket {
public:
	/* SETTERS */
	bool setNumber(std::string input);
	bool setGrossWeight(double input);
	bool setTareWeight(double input);
	bool setMoistureLevel(double input);
	bool setForiegnMaterial(double input);

	/* GETTERS */
	std::string getNumber();
	double getGrossWeight();
	double getTareWeight();
	double getMoistureLevel();
	double getForiegnMaterial();

	/* CALCULATIONS */
	double calculateNetWeight();
	double calculateGrossBushels();
	double calculateMoistureDockage();
	double calculateForiegnDockage();
	double calculateNetBushels();
	
private:
	std::string number;
	double grossWeight, tareWeight, moistureLevel, foriegnMaterial;
};
