#include "lr1.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <tuple>

using namespace std;

tuple<float, float, string> sumAndProd(ifstream &fin, int b, int d) {
    string s;
    int i = 0;
    float sum = 0;
    float product = 1;
    int numProd = 0;
    while (fin >> s) {
        if (s == "EOTEST") {
            if (numProd) {
                return { sum, product, ""};
            }
            else {
                return { sum, 0, "" };
            }
                
        }
        float floatValue;
        double doubleValue = stof(s);
        if (doubleValue <= std::numeric_limits<float>::max() && doubleValue >= -std::numeric_limits<float>::max()) {
            floatValue = static_cast<float>(doubleValue);
        }
        else {
            return { 0, 0, "InputValueOutOfFloatRange" };
        }
        double dSum = sum + floatValue;
        if (dSum <= std::numeric_limits<float>::max() && dSum >= -std::numeric_limits<float>::max()) {
            sum = static_cast<float>(dSum);
        }
        else {
            return { 0, 0, "SumValueOutOfFloatRange" };
        }
        if (b <= i && i <= d) {
            long double dProd = product * floatValue;
            if (dProd <= std::numeric_limits<float>::max() && dProd >= -std::numeric_limits<float>::max()) {
                product = static_cast<float>(dProd);
                numProd++;
            }
            else {
                return { 0, 0, "ProductValueOutOfFloatRange" };
            }
        }
        i++;
        if (i > 1024) {
            return { 0, 0, "MaxNuberOfElementsLimitExeeded" };
        }
    }
    return { sum, product, "TestNotEndsWithEOTEST" };
}