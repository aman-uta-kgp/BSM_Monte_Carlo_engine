#include "Bond.h"
#include <iostream>
#include <cmath>

using namespace std;


//constructor

Bond::Bond(double prin, double coup, double mkt, double yTM, char type)
{
    //cout << "I have created a tailored Bond" << endl;

    setPrincipal(prin);
    setCouponrate(coup);
    setMarketrate(mkt);
    setyearsToMaturity(yTM);
    setpaymentType(type);

}

Bond::~Bond() {
    cout << "In the ~Bond destructor" << endl;
}

// following are different methods
double Bond::getBondPrice()
{
    double bondPrice = 0;

    int scalingfactor = 0;

    if (getpaymentType() == BOND_ANNUAL_TYPE)
    {
        scalingfactor = 1;
    }
    else if (getpaymentType() == BOND_SEMIANNUAL_TYPE)
    {
        scalingfactor = 2;
    }
    else if (getpaymentType() == BOND_QUARTERLY_TYPE)
    {
        scalingfactor = 4;
    }

    double coupon =
        getPrincipal() * (getCouponrate() / scalingfactor);

    /*cout << "Coupon: " << coupon << endl;*/

    double periods =
        getyearsToMaturity() * scalingfactor;

    double yield = getMarketrate() / scalingfactor;

    /*//cout << "Yield: " << yield << endl;*/

    double pvCoupons =
        (coupon * (1 - pow(1 + yield, - periods))) / yield;

    //cout << "PV Coupons: " << pvCoupons << endl;

    double pvRedemption =
        getPrincipal() * pow((1 + yield), - periods);

    //cout << "PV Redemption: " << pvRedemption << endl;

    bondPrice = pvCoupons + pvRedemption;
    /*cout << "Bond Price" << bondPrice << endl;*/

    return bondPrice;

}

void Bond::setPrincipal(double prin){
    principal = prin;
}
double Bond::getPrincipal()
{
    return principal;
}

void Bond::setCouponrate(double coup)
{
    Couponrate = coup;
}
double Bond::getCouponrate() {
    return Couponrate;
}

void Bond::setMarketrate(double coup)
{
    Marketrate = coup;
}
double Bond::getMarketrate() {
    return Marketrate;
}

void Bond::setyearsToMaturity(double yTM) {
    yearsToMaturity = yTM;
}
double Bond::getyearsToMaturity() {
    return yearsToMaturity;
}

void Bond::setpaymentType(char type) {
    paymentType = type;
}
char Bond::getpaymentType() {
    return paymentType;
}

