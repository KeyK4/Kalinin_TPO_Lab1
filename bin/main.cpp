#include <iostream>
#include <vector>

#include <lib/lr1.h>

using namespace std;

int main() {
    int b = 1, d = 2;
    vector<float> arr = {10, 14, 15, 20, 21, 25, 30};
    pair<float, float> result = prodAndSum(arr, b, d);
    cout << "Number of elements that are divisible by 5 and not divisible by 7: " << result.first << std::endl;
    cout << "Sum: " << result.second << std::endl;
    int a;
    cin >> a;
    return 0;
}