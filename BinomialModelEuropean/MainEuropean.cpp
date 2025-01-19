
#include "BinModelEuropean.hpp"
#include "OptionsEuropean.hpp"
#include "DoubleDigitOpt.hpp"
#include "Strangle.hpp"
#include "Butterfly.hpp"
#include "BullSpread.hpp"
#include "BearSpread.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
     BinModel Model;
     if (Model.GetInputData() == 1)
          return 1;
     Call Option1;
     Option1.GetInputData();
     cout << "European Call Option Price = "
          << Option1.PriceByCRR(Model)
          << endl
          << endl;
     Put Option2;
     Option2.GetInputData();
     cout << "European Put Option Price = "
          << Option2.PriceByCRR(Model)
          << endl
          << endl;
     DoubDigitOpt Option3;
     Option3.GetInputData();
     cout << "European Double-Digital Option Price = "
          << Option3.PriceByCRR(Model)
          << endl
          << endl;
     Strangle Option4;
     Option4.GetInputData();
     cout << "European Strangle Option Price = "
          << Option4.PriceByCRR(Model)
          << endl
          << endl;

     Butterfly Option5;
     Option5.GetInputData();
     cout << "European Butterfly Spread Option Price = "
          << Option5.PriceByCRR(Model)
          << endl
          << endl;
     BullSpread Option6;
     Option6.GetInputData();
     cout << "European Bull Spread Option Price = "
          << Option6.PriceByCRR(Model)
          << endl
          << endl;

     BearSpread Option7;
     Option7.GetInputData();
     cout << "European Bear Spread Option Price = "
          << Option7.PriceByCRR(Model)
          << endl
          << endl;

     return 0;
}