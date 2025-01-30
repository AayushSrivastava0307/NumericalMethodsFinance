#ifndef Options05_hpp
#define Options05_hpp
#include "BinModel02.hpp"
class EurOption
{
private:
    // steps to expiry
    int N;
    // pointer to payoff function
    double (*Payoff)(double z, double K);

public:
    void SetN(int N_) { N = N_; }
    void SetPayoff(double (*Payoff_)(double z, double K))
    {
        Payoff = Payoff_;
    }
    // pricing european option
    double PriceByCRR(BinModel Model, double K);
};
// computing call payoff
double CallPayoff(double z, double K);
class Call : public EurOption //subclass
{
private:
    double K; // strike price
public:
    Call() { SetPayoff(CallPayoff); } //constructor
    double GetK() { return K; }
    int GetInputData();
};
// computing put payoff
double PutPayoff(double z, double K);
class Put : public EurOption
{
private:
    double K; // strike price
public:
    Put() { SetPayoff(PutPayoff); } //constructor
    double GetK() { return K; }
    int GetInputData();
};
#endif