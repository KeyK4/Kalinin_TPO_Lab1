#include <iostream>
#include <vector>

#include <lib/lr1.h>

using namespace std;

int main() {
    int b = 2, d = 5;
    vector<float> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    pair<float, float> result = prodAndSum(arr, b, d);
    cout << "Sum of all elements: " << result.first << std::endl;
    cout << "Production of elements on[" << b <<", " << d << "]: " << result.second << std::endl;
    int a;
    cin >> a;
    return 0;
}