#include <iostream>
#include <vector>
#include <iomanip>
#include <lib/lr1.h>
#include <fstream>

using namespace std;

bool isEqualsActualAndAssumption(float actual, float assumption) {
    return abs(actual - assumption) < 0.000001;
}

int main() {
    int b, d;
    float assumeSum, assumeProd;
    ifstream fin("test.txt");
    string inp, assumeErr;

    if (fin >> inp) {
        string delimiter = ";";
        int fitstDelimiterPosition = inp.find(delimiter);
        string b_string = inp.substr(0, fitstDelimiterPosition);
        b = stoi(b_string);
        string d_string = inp.substr(fitstDelimiterPosition + 1, inp.size());
        d = stoi(d_string);
        fin >> inp;
        fitstDelimiterPosition = inp.find(delimiter);
        int secondDelimiterPosition = inp.rfind(delimiter);
        string assumeSumString = inp.substr(0, fitstDelimiterPosition);
        assumeSum = stof(assumeSumString);
        string assumeProdString = inp.substr(fitstDelimiterPosition + 1, secondDelimiterPosition);
        assumeProd = stof(assumeProdString);
        assumeErr = inp.substr(secondDelimiterPosition + 1, inp.size());
    }
    float sum, prod;
    string err;
    tie(sum, prod, err) = sumAndProd(fin, b, d);
    fin.close();

    cout << sum << endl;
    cout << isEqualsActualAndAssumption(sum, assumeSum) << std::endl;
    cout << prod << endl;
    cout << isEqualsActualAndAssumption(prod, assumeProd) << std::endl;
    cout << err << endl;
    bool c = err == assumeErr;
    cout << c << std::endl;
    
    int a;
    cin >> a;
    return 0;
}