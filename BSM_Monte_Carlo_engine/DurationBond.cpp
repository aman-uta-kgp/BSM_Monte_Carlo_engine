#include <iostream>

#include "DurationBond.h"

using namespace std;

DurationBond::DurationBond(double prin,
	double coup,
	double mkt,
	double yTM,
	char typ) : Bond(prin,
		coup,
		mkt,
		yTM,
		typ)
{
	cout << "In the DurationBond constructor" << endl;
	setDuration(calculateDuration());
}

DurationBond :: ~DurationBond() {
	cout << "In the ~DurationBond destructor" << endl;
}

double DurationBond::calculateDuration() {
	double origMarketRate = getMarketrate();

	cout << "origMarketRate: " << origMarketRate << endl;

	/*shock interest rate by deltaY*/

	double deltaY = DURATION_BOND_RATE_CHANGE;

	if (origMarketRate <= DURATION_BOND_RATE_CHANGE) {
		deltaY = origMarketRate - 0.0001;
	}
	 
	cout << "deltaY: " << deltaY << endl;

	//v1 is the current bond price
	double v1 = getBondPrice();
	cout << "Current Bond Price (v1) : " << v1 << endl;

	//Shock interest rate down by DeltaY

	double bipsLower = origMarketRate - deltaY;

	setMarketrate(bipsLower);

	double v2 = getBondPrice();
	cout << "New Bond Price {After interest lowered} (v2) : " << v2 << endl;

	double bipsHigher = origMarketRate + deltaY;

	setMarketrate(bipsHigher);

	double v3 = getBondPrice();
	cout << "New Bond Price {After interest increased} (v3) : " << v3 << endl;

	//Rest YTM to actual current rate

	setMarketrate(origMarketRate);

	// Calculate Bon Duration
	// Duration = v2 - v3 / (2*v1*DeltaY)

	double calcDuration = (v2 - v3) / (2 * v1 * deltaY);

	cout << "Internal, calcDuration: " << calcDuration << endl;

	return calcDuration;
}

double DurationBond::getDuration() {
	return duration;
}

void DurationBond::setDuration(double inpDurn) {
	duration = inpDurn;
}