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
    double K; // strike price
    int N;    // steps to expiry

    // Pricing Call Option
    cout << "Enter call option data:" << endl;
    GetInputData(N, K);
    cout << "European call option price = "
         << PriceByCRR(S0, U, D, R, N, K, CallPayoff) 
         << endl
         << endl;

    // Pricing Put Option
    cout << "Enter put option data:" << endl;
    GetInputData(N, K);
    cout << "European put option price = "
         << PriceByCRR(S0, U, D, R, N, K, PutPayoff) 
         << endl
         << endl;

    // Pricing Digital Call Option
    cout << "Enter digital call option data:" << endl;
    GetInputData(N, K);
    cout << "European digital call option price = "
         << PriceByCRR(S0, U, D, R, N, K, DigitalCallPayoff) 
         << endl
         << endl;

    // Pricing Digital Put Option
    cout << "Enter digital put option data:" << endl;
    GetInputData(N, K);
    cout << "European digital put option price = "
         << PriceByCRR(S0, U, D, R, N, K, DigitalPutPayoff) 
         << endl
         << endl;

    return 0;
}