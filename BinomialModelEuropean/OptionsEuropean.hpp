#ifndef OptionsEuropean_hpp
#define OptionsEuropean_hpp
#include "BinModelEuropean.hpp"
class EurOption
{
private:
    int N; // steps to expiry
public:
    void SetN(int N_) { N = N_; }
    // Payoff defined to return 0.0
    // for pedagogical purposes.
    // To use a pure virtual function replace by
    // virtual double Payoff(double z)=0; 
    virtual double Payoff(double z) { return 0.0; }
    // pricing European option
    double PriceByCRR(BinModel Model);
};
class Call : public EurOption
{
private:
    double K; // strike price
public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    double Payoff(double z);
};
class Put : public EurOption
{
private:
    double K; // strike price
public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    double Payoff(double z);
};
#endif