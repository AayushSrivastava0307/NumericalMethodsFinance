#include "BearSpread.hpp"
#include <iostream>

using namespace std;

// override the Payoff function
double BearSpread::Payoff(double z)
{
    if (z <= K1)
        return K2 - K1;
    else if (z > K1 && z < K2)
        return K2 - z;
    else // z >= K2
        return 0.0;
}


int BearSpread::GetInputData()
{
    cout << "Enter Bear Spread option data:" << endl;
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