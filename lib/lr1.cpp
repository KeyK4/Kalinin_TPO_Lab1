#include "lr1.h"

std::pair<float, float> prodAndSum(const std::vector<float>& array, int b, int d) {
    int count = 0;
    int total = 0;
    for (int num : array) {
        if (num % 5 == 0 && num % 7 != 0) {
            count++;
            total += num;
        }
    }
    return std::make_pair(count, total);
}