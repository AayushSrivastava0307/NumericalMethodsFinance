#pragma once
#ifndef Options03_hpp
#define Options03_hpp


int GetInputData(int &N, double &K);
int GetInputData(int &N, double K[]); // overloading for multiple strikes

// euro options 
double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K[],
                  double (*Payoff)(double z, double K[]));


double CallPayoff(double z, double K[]);


double PutPayoff(double z, double K[]);


double DigitalCallPayoff(double z, double K[]);


double DigitalPutPayoff(double z, double K[]);


double DoubleDigitalPayoff(double z, double K[]);

#endif