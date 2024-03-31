#include <iostream>

class BSM {
public:
    BSM(float, float, float, 
        float, float, long, long);
    ~BSM();

    float getBsmAsset();
    float getBsmStrike();
    float getBsmGrowth();
    float getBsmVol();
    float getBsmYears();
    long getBsmSteps();
    long getBsmMonteCarloSims();

    void logNormalRandomWalk();

    double getCallPrice();
    double getPutPrice();

    double rn();
        
private:
    float BsmAsset;
    float BsmStrike;
    float BsmGrowth;
    float BsmVol;
    float BsmYears;
    long BsmSteps;
    long BsmMonteCarloSims;

    double bsmCallPrice;
    double bsmPutPrice;

};
