#ifndef BullSpread_hpp
#define BullSpread_hpp

#include "OptionsEuropean.hpp" 

class BullSpread : public EurOption
{
private:
    double K1; // lower strike price
    double K2; // upper strike price

public:
    BullSpread() { } // constructor does not set Payoff via separate function

    // override the Payoff function
    double Payoff(double z) override;

    // accessor methods
    double GetK1() const { return K1; }
    double GetK2() const { return K2; }

    // method to get input data
    int GetInputData();
};

#endif 