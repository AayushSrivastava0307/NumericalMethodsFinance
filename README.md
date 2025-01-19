# Numerical Methods in Finance  

## **Binomial European Model Implementation**

To successfully compile and run the Binomial European Model:  

### **1. Ensure Compatibility**  
- Use the **latest versions** of `BinModel`, `Options`, and `Main`.  
- These files are available in the `BinomialModelEuropean` directory for the most up-to-date implementation.  

### **2. Avoid Old Models**  
- If you're referencing legacy files from the `OldModels` directory, ensure you update them to match the latest standards before compiling.  
- The old versions may lack recent features, optimizations, or bug fixes.  

## **How to Run the Model**  
1. Clone the repository:  
   ```bash
   git clone https://github.com/YourRepo/NumericalMethodsFinance.git
   cd NumericalMethodsFinance
2. Compile the Files
   ```bash
    g++ MainEuropean.cpp BinModelEuropean.cpp OptionsEuropean.cpp Call.cpp Put.cpp Strangle.cpp Butterfly.cpp BullSpread.cpp BearSpread.cpp DoubleDigitOpt.cpp -o MainEuropean.exe
3. Run the executable
   ```bash
   ./MainEuropean.exe
