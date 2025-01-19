#ifndef BearSpread_hpp
#define BearSpread_hpp

#include "OptionsEuropean.hpp" 

class BearSpread : public EurOption
{
private:
    double K1; // lower strike price
    double K2; // upper strike price

public:
    BearSpread() { } // constructor does not set Payoff via separate function

    // override the Payoff function
    double Payoff(double z) override;

    // accessor methods
    double GetK1() const { return K1; }
    double GetK2() const { return K2; }

    int GetInputData();
};

#endif 