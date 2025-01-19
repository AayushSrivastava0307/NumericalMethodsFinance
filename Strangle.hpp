
#ifndef Strangle_hpp
#define Strangle_hpp
#include "OptionsEuropean.hpp" 

class Strangle : public EurOption
{
private:
    double K1; // lower strike price
    double K2; // upper strike price

public:
    Strangle() { } // constructor does not set Payoff via separate function

    // override the payoff function
    double Payoff(double z) override;

    // accessor methods
    double GetK1() const { return K1; }
    double GetK2() const { return K2; }

    int GetInputData();
};

#endif 