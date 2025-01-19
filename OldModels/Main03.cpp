#include "BinModel01.hpp"
#include "Options03.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double S0, U, D, R;
    if (GetInputData(S0, U, D, R) == 1)
        return 1;
    double K_single; // strike price for Call, Put, Digital Call, Digital Put
    int N;    // steps to expiry

    // Pricing Call Option
    cout << "Enter call option data:" << endl;
    GetInputData(N, K_single);
    double K_call[1] = { K_single };
    cout << "European call option price = "
         << PriceByCRR(S0, U, D, R, N, K_call, CallPayoff) 
         << endl
         << endl;

    // Pricing Put Option
    cout << "Enter put option data:" << endl;
    GetInputData(N, K_single);
    double K_put[1] = { K_single };
    cout << "European put option price = "
         << PriceByCRR(S0, U, D, R, N, K_put, PutPayoff) 
         << endl
         << endl;

    // Pricing Digital Call Option
    cout << "Enter digital call option data:" << endl;
    GetInputData(N, K_single);
    double K_digitalCall[1] = { K_single };
    cout << "European digital call option price = "
         << PriceByCRR(S0, U, D, R, N, K_digitalCall, DigitalCallPayoff) 
         << endl
         << endl;

    // Pricing Digital Put Option
    cout << "Enter digital put option data:" << endl;
    GetInputData(N, K_single);
    double K_digitalPut[1] = { K_single };
    cout << "European digital put option price = "
         << PriceByCRR(S0, U, D, R, N, K_digitalPut, DigitalPutPayoff) 
         << endl
         << endl;

    // Pricing Double Digital Option
    cout << "Enter double digital option data:" << endl;
    double K_double[2];
    GetInputData(N, K_double); // Uses overloaded function
    cout << "European double digital option price = "
         << PriceByCRR(S0, U, D, R, N, K_double, DoubleDigitalPayoff) 
         << endl
         << endl;

    return 0;
}