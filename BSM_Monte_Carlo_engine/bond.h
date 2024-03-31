class Bond
{
public:
    const char BOND_ANNUAL_TYPE = 'A';
    const char BOND_SEMIANNUAL_TYPE = 'S';
    const char BOND_QUARTERLY_TYPE = 'Q';

    Bond(double, double, double, double, char);
    ~Bond();

    //different methods

    double getBondPrice();

    void setPrincipal(double);
    double getPrincipal();

    void setCouponrate(double);
    double getCouponrate();

    void setMarketrate(double);
    double getMarketrate();

    void setyearsToMaturity(double);
    double getyearsToMaturity();

    void setpaymentType(char);
    char getpaymentType();

private:
    double principal;
    double Couponrate;
    double Marketrate;
    double yearsToMaturity;
    char paymentType; // 'A'nnual, 'S'emi-Annual, 'Q'uarterly
};
