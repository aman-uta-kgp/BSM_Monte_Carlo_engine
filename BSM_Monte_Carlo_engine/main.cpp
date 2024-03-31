#include <iostream>
#include "BSM.h"

using namespace std;

enum BSMExecution
{
    ASSET = 1,
    STRIKE = 2,
    GROWTH = 3,
    VOLATILITY = 4,
    YEARS = 5,
    STEPS = 6,
    SIMULATIONS = 7
};

int main(int argc, const char* argv[])
{
    BSM bsm(atof(argv[ASSET]),
        atof(argv[STRIKE]),
        atof(argv[GROWTH]),
        atof(argv[VOLATILITY]),
        atof(argv[YEARS]),
        atof(argv[STEPS]),
        atof(argv[SIMULATIONS]));

    cout << "Asset:  " << bsm.getBsmAsset() << endl <<
        "Strike: " << bsm.getBsmStrike() << endl <<
        "Growth: " << bsm.getBsmGrowth() << endl <<
        "Vol:    " << bsm.getBsmVol() << endl <<
        "Years:  " << bsm.getBsmYears() << endl <<
        "Steps:  " << bsm.getBsmSteps() << endl <<
        "Sims:   " << bsm.getBsmMonteCarloSims() << endl;

    bsm.logNormalRandomWalk();

    cout << "\n Call option price: "
        << bsm.getCallPrice() << endl;

    cout << "Put option price: "
        << bsm.getPutPrice() << endl;

    return 0;
}
