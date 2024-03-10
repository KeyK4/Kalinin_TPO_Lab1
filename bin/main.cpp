#include <iostream>
#include <vector>
#include <iomanip>
#include <lib/lr1.h>

using namespace std;

int main() {
    int b = 2, d = 8;
    string filename = "mainInput.txt";
    pair<float, float> result = prodAndSum(filename, b, d);
    cout << "Sum of all elements: " << fixed << setprecision(7) << result.first << std::endl;
    cout << "Production of elements on[" << b <<", " << d << "]: " << fixed << setprecision(7) << result.second << std::endl;
    int a;
    cin >> a;
    return 0;
}