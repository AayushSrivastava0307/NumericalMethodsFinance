
#include "Butterfly.hpp"
#include <iostream>

using namespace std;

// override the Payoff function
double Butterfly::Payoff(double z)
{
    double midpoint = (K1 + K2) / 2.0;
    
    if (z > K1 && z <= midpoint)
        return (z - K1) / 2.0;
    else if (z > midpoint && z <= K2)
        return K2 - z;
    else
        return 0.0;
}


int Butterfly::GetInputData()
{
    cout << "Enter Butterfly Spread option data:" << endl;
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