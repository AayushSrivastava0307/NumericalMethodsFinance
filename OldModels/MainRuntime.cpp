#include "BinModel02.hpp"
#include "Options08.hpp"
#include <iostream>
#include <chrono>
#include <sstream>
#include <vector>

int main()
{
    using namespace std;
    using namespace std::chrono;

    // Hardcoded binomial model data:
    // S0 = 100, U = 0.1, D = -0.1, R = 0.05
    // This code sets up the model with the same data each time.
    {
        // Fake input for BinModel::GetInputData()
        istringstream binModelInput("100\n0.1\n-0.1\n0.06\n");

        // temporarily redirect cin
        streambuf* backupCin = cin.rdbuf();
        cin.rdbuf(binModelInput.rdbuf());

        // Create binomial model
        BinModel Model;
        if (Model.GetInputData() == 1)
        {
            cin.rdbuf(backupCin); // restore
            return 1;
        }

        // Restore cin
        cin.rdbuf(backupCin);

        // We'll test an American Call for varying N
        // We'll keep strike = 100
        vector<int> testNs = {3, 50, 100, 1000, 5000};

        cout << "Hardcoded American Call with S0=100, U=0.1, D=-0.1, R=0.05\n"
             << "Strike K=100. Timing results:\n\n";

        for (int n : testNs)
        {
            // Fake input for Call::GetInputData() for each N
            //  (N, then strike K=100)
            ostringstream oss;
            oss << n << "\n100\n";
            istringstream callInput(oss.str());

            // Redirect cin again
            backupCin = cin.rdbuf();
            cin.rdbuf(callInput.rdbuf());

            Call OptionCall;
            OptionCall.GetInputData();

            // Restore cin
            cin.rdbuf(backupCin);

            // Measure runtime of PriceBySnell (American)
            auto startTime = high_resolution_clock::now();
            double amCallPrice = OptionCall.PriceBySnell(Model);
            auto endTime = high_resolution_clock::now();

            auto durationMs = duration_cast<milliseconds>(endTime - startTime).count();

            // Print result for this N
            cout << "N=" << n << " -> American Call Price: " << amCallPrice
                 << ", Runtime: " << durationMs << " ms\n";
        }

        cout << "\nDone.\n";
    }

    return 0;
}