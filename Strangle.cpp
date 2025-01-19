#include "Strangle.hpp"
#include <iostream>
using namespace std;

// override the Payoff function
double Strangle::Payoff(double z)
{
    if (z <= K1)
        return K1 - z;
    else if (z > K1 && z <= K2)
        return 0.0;
    else 
        return z - K2;
}

int Strangle::GetInputData()
{
    cout << "Enter Strangle option data:" << endl;
    cout << "Enter number of steps to expiry N: ";
    int N_input;
    cin >> N_input;
    SetN(N_input);

    do
    {
        cout << "Enter lower strike price K1: ";
        cin >> K1;
        cout << "Enter upper strike price K2: ";
        cin >> K2;

        if (K1 >= K2)
            cout << "Error: K1 must be less than K2. Please re-enter.\n";

    } while (K1 >= K2);

    cout << endl;
    return 0;
}