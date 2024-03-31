#include "BSM.h";
#include <math.h>

using namespace std;

BSM::BSM(float ass,
	float strk,
	float grwth,
	float volty,
	float yrs,
	long steps,
	long sims) {

	BsmAsset = ass;	
	BsmStrike = strk;	
	BsmGrowth = grwth;	
	BsmVol = volty;	
	BsmYears = yrs;	
	BsmSteps = steps;	
	BsmMonteCarloSims = sims;	

}

BSM::~BSM(){}

// simulating movement of underlying asset
void BSM::logNormalRandomWalk() {
	srand((unsigned)time(0));

	double callPayoffPot = 0.0;
	double putPayoffPot = 0.0;

	double timeStep = getBsmYears() / getBsmSteps();
	double sqrtTs = sqrt(timeStep);

	for (long i = 1; i <= getBsmMonteCarloSims(); i++)
	{
		double ass = getBsmAsset();
		// initial value of asset
		for (int j = 1; j <= getBsmSteps(); j++)
		{
			// del S / S = mu*t + sigma*sqrt(T)*epsilon
			ass = ass * (1 + getBsmGrowth() * timeStep +
				getBsmVol() * sqrtTs * (
					rn() + rn() + rn() + rn() +
					rn() + rn() + rn() + rn() +
					rn() + rn() + rn() + rn()  - 6
					));

			// sum of n r.v.s follows a normal distribution
			//cout << "Asset value after " << j << "th step :" << ass << endl;
		}

		if (ass > getBsmStrike()) {

			callPayoffPot += ( ass - getBsmStrike() );
			// adding call payoff potential across all simulations
		}
		else if (ass < getBsmStrike()) {
			putPayoffPot += (getBsmStrike() - ass);
			// adding put payoff potential across all simulations
		}

		// observing if average payoffs converge
		/*cout << "Asset Price at the end of iteration " << i << " is " << (ass) << endl;
		cout << "Average Payoff Call after iteration " << i << " is " << (callPayoffPot / i) << endl;
		cout << "Average Payoff Put after iteration " << i << " is " << (putPayoffPot / i) << "\n" << endl;*/

		if ((i % 10000) == 0) {
			cout << "." << flush;

			if ((i % 100000) == 0) {
				long iMess = i / 1000;
				cout << iMess << "k" << flush;
			}
		}

	}

	bsmCallPrice = callPayoffPot / getBsmMonteCarloSims();
	bsmPutPrice = putPayoffPot / getBsmMonteCarloSims();

	return;
}

// defining included methods

double BSM::rn() {
	return (double)rand() / (double)(RAND_MAX + 1.0);
	// Never want the method rn() to return exact 1
}

float BSM::getBsmAsset() {
	return BsmAsset;
}

float BSM::getBsmStrike() {
	return BsmStrike;
}

float BSM::getBsmGrowth() {
	return BsmGrowth;
}

float BSM::getBsmVol() {
	return BsmVol;
}

float BSM::getBsmYears() {
	return BsmYears;
}

long BSM::getBsmSteps() {
	return BsmSteps;
}

long BSM::getBsmMonteCarloSims() {
	return BsmMonteCarloSims;
}

double BSM::getCallPrice() {
	return bsmCallPrice;
}

double BSM::getPutPrice() {
	return bsmPutPrice;
}


