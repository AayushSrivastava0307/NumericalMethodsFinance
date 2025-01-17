#ifndef Options01_hpp
#define Options01_hpp
// inputting and displaying option data
int GetInputData(int &N, double &K);
// pricing European option
double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K);
// computing call payoff
double CallPayoff(double z, double K);
#endif