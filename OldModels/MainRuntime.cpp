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

    // hardcoded binomial model data:
    // s0 = 100, u = 0.1, d = -0.1, r = 0.06
    {
        // fake input for binmodel::getinputdata()
        istringstream binModelInput("100\n0.1\n-0.1\n0.06\n");

        // temporarily redirect cin
        streambuf* backupCin = cin.rdbuf();
        cin.rdbuf(binModelInput.rdbuf());

        BinModel Model;
        if (Model.GetInputData() == 1)
        {
            cin.rdbuf(backupCin); // restore
            return 1;
        }

        // restore cin
        cin.rdbuf(backupCin);

        // we'll test an american call and a european call for varying n
        // we'll keep strike = 100
        vector<int> testNs = {3, 50, 100, 1000, 5000,20000};

        cout << "hardcoded calls with s0=100, u=0.1, d=-0.1, r=0.06\n"
             << "strike k=100. timing results:\n\n";

        for (int n : testNs)
        {
            // fake data for call::getinputdata() (n, then strike=100)
            ostringstream oss;
            oss << n << "\n100\n";
            istringstream callInput(oss.str());

            // redirect cin again
            backupCin = cin.rdbuf();
            cin.rdbuf(callInput.rdbuf());

            Call OptionCall;
            OptionCall.GetInputData();

            // restore cin
            cin.rdbuf(backupCin);

            // measure runtime for european call
            auto startTimeEu = high_resolution_clock::now();
            double euCallPrice = OptionCall.PriceByCRR(Model);
            auto endTimeEu = high_resolution_clock::now();
            auto durationMsEu = duration_cast<milliseconds>(endTimeEu - startTimeEu).count();

            cout << "n=" << n
                 << ", runtime: " << durationMsEu << " ms\n";

            // measure runtime for american call
            auto startTimeAm = high_resolution_clock::now();
            double amCallPrice = OptionCall.PriceBySnell(Model);
            auto endTimeAm = high_resolution_clock::now();
            auto durationMsAm = duration_cast<milliseconds>(endTimeAm - startTimeAm).count();

            cout << "n=" << n
                 << ", runtime: " << durationMsAm << " ms\n\n";
        }

        cout << "\ndone.\n";
    }

    return 0;
}
