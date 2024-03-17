#include "lr1.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>

using namespace std;

tuple<float, float, string> sumAndProd(ifstream &fin, int b, int d) {
    string s;
    int i = 0;
    float sum = 0;
    float product = 1;
    int numProd = 0;
    double doubleValue;
    while (fin >> doubleValue) {
        float floatValue;
        doubleValue = round(doubleValue * 1000000)/1000000;
        if (doubleValue <= std::numeric_limits<float>::max() && doubleValue >= -std::numeric_limits<float>::max()) {
            floatValue = static_cast<float>(doubleValue);
        }
        else {
            return { 0, 0, "InputValueOutOfFloatRange" };
        }
        if (floatValue > 0) {
            double dSum = sum + floatValue;
            if (dSum <= std::numeric_limits<float>::max() && dSum >= -std::numeric_limits<float>::max()) {
                sum += floatValue;
            }
            else {
                return { 0, 0, "SumValueOutOfFloatRange" };
            }
        }
        if (b <= i && i <= d) {
            long double dProd = product * floatValue;
            if (dProd <= std::numeric_limits<float>::max() && dProd >= -std::numeric_limits<float>::max()) {
                product *= floatValue;
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
    if (numProd) {
        return { sum, product, "" };
    }
    else {
        return { sum, 0, "" };
    }
}