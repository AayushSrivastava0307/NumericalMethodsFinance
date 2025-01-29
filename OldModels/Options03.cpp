#include "Options03.hpp"
#include "BinModel01.hpp"
#include <iostream>
#include <cmath>
using namespace std;

// inputting and displaying option data for single strike
int GetInputData(int &N, double &K)
{
    cout << "Enter steps to expiry N: ";
    cin >> N;
    cout << "Enter strike price K: ";
    cin >> K;
    cout << endl;
    return 0;
}

// overloading for multiple strikes
int GetInputData(int &N, double K[])
{
    cout << "Enter steps to expiry N: ";
    cin >> N;
    cout << "Enter first strike price K1: ";
    cin >> K[0];
    cout << "Enter second strike price K2: ";
    cin >> K[1];
    cout << endl;
    return 0;
}

// payoff function pointer 
double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K[],
                  double (*Payoff)(double z, double K[]))
{
    double q = RiskNeutProb(U, D, R);
    double Price[N + 1];
    for (int i = 0; i <= N; i++)
    {
        Price[i] = Payoff(S(S0, U, D, N, i), K);
    }
    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + R);
        }
    }
    return Price[0];
}

double CallPayoff(double z, double K[])
{
    // K[0] is strike price
    if (z > K[0])
        return z - K[0];
    return 0.0;
}


double PutPayoff(double z, double K[])
{
    // K[0] is strike price
    if (z < K[0])
        return K[0] - z;
    return 0.0;
}

double DigitalCallPayoff(double z, double K[])
{
    // K[0] is the strike price
    if (z > K[0])
        return 1.0;
    return 0.0;
}

double DigitalPutPayoff(double z, double K[])
{
    // K[0] is the strike price
    if (z < K[0])
        return 1.0;
    return 0.0;
}

// here use of K[0] will make sense 
double DoubleDigitalPayoff(double z, double K[])
{
    // K[0] = K1, K[1] = K2
    if (z > K[0] && z < K[1])
        return 1.0;
    return 0.0;
}