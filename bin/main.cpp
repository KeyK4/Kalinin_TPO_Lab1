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
    string inp;

    if (fin >> inp) {
        string delimiter = ";";
        int delimiterPosition = inp.find(delimiter);
        string b_string = inp.substr(0, delimiterPosition);
        b = stoi(b_string);
        string d_string = inp.substr(delimiterPosition + 1, inp.size());
        d = stoi(d_string);
        fin >> inp;
        delimiterPosition = inp.find(delimiter);
        string assumeSumString = inp.substr(0, delimiterPosition);
        assumeSum = stof(assumeSumString);
        string assumeProdString = inp.substr(delimiterPosition + 1, inp.size());
        assumeProd = stof(assumeProdString);
    }
    pair<float, float> result = sumAndProd(fin, b, d);
    fin.close();

    cout << isEqualsActualAndAssumption(result.first, assumeSum) << std::endl;
    cout << isEqualsActualAndAssumption(result.second, assumeProd) << std::endl;
    
    int a;
    cin >> a;
    return 0;
}