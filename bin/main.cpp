#include <iostream>
#include <vector>

#include <lib/lr1.h>

using namespace std;

int main() {
    int b = 2, d = 5;
    vector<float> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    pair<float, float> result = prodAndSum(arr, b, d);
    cout << "Number of elements that are divisible by 5 and not divisible by 7: " << result.first << std::endl;
    cout << "Sum: " << result.second << std::endl;
    int a;
    cin >> a;
    return 0;
}