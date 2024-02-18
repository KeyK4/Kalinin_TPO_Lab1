#include "lr1.h"

std::pair<float, float> prodAndSum(const std::vector<float>& array, int b, int d) {
    float sum = 0;
    float product = 1;
    int i = 0;
    while (i < array.size()) {
        sum += array[i];
        if (b <= i && i <= d) {
            product *= array[i];
        }
    }
    return std::make_pair(sum, product);
}