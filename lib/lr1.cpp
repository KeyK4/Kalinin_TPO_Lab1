#include "lr1.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>

using namespace std;

bool log(ofstream& fout, int step) {
    fout << "Step: " << step << endl;
    return true;
}

tuple<float, float, string> sumAndProd(ifstream &fin, int b, int d, string protocolName) {
    ofstream fout(protocolName);
    log(fout, 1);
    string s;//1
    int i = 0;//1
    float sum = 0;//1
    float product = 1;//1
    int numProd = 0;//1
    double doubleValue;//1
    while (log(fout, 2) && fin >> doubleValue) {//2
        log(fout, 3);
        float floatValue;//3
        doubleValue = round(doubleValue * 1000000)/1000000;//3
        if ((log(fout, 4) && doubleValue <= std::numeric_limits<float>::max() /*4*/) && (log(fout, 5) && doubleValue >= -std::numeric_limits<float>::max()/*5*/)) {
            log(fout, 6);
            floatValue = static_cast<float>(doubleValue);/*6*/
        }
        else {
            log(fout, 20);
            log(fout, 23);
            log(fout, 27);
            return { 0, 0, "InputValueOutOfFloatRange" };/*20 23*/
        }
        if (log(fout, 7) && floatValue > 0/*7*/) {
            log(fout, 8);
            double dSum = sum + floatValue;/*8*/ 
            if (log(fout, 9) && dSum <= std::numeric_limits<float>::max()/*9*/) {
                sum += floatValue;/*10*/
            }
            else {
                log(fout, 21);
                log(fout, 25);
                return { 0, 0, "SumValueOutOfFloatRange" }; /*21 25*/
            }
        }
        if ((log(fout, 11) && b <= i/*11*/) && (log(fout, 12) && i <= d /*12*/)) {
            log(fout, 13);
            long double dProd = product * floatValue;/*13*/
            if (dProd <= std::numeric_limits<float>::max()/*14*/ && dProd >= -std::numeric_limits<float>::max() /*15*/) {
                log(fout, 16);
                product *= floatValue;/*16*/
                numProd++;/*16*/
            }
            else {
                log(fout, 22);
                log(fout, 25);
                return { 0, 0, "ProductValueOutOfFloatRange" }; /*22*/
            }
        }
        log(fout, 17);
        i++;/*17*/
        if (log(fout, 18) && i > 1024/*18*/) {
            log(fout, 19);
            log(fout, 25);
            return { 0, 0, "MaxNuberOfElementsLimitExeeded" }; /*19*/
        }
    }
    if (log(fout, 24) && !numProd /*24*/) {
        log(fout, 25);
        product = 0;/*25*/
    }
    log(fout, 26);
    log(fout, 27);
    return { sum, product, "" };/*26*/
}/*27*/