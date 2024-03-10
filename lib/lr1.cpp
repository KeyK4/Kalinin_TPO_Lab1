#include "lr1.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

pair<float, float> prodAndSum(string filename, int b, int d) {
    ifstream fin(filename);
    vector<float> array;
    double doubleValue;
    int i = 0;
    while (fin >> doubleValue) {
        float floatValue;
        if (doubleValue <= std::numeric_limits<float>::max() && doubleValue >= -std::numeric_limits<float>::max()) {
            floatValue = static_cast<float>(doubleValue);
        }
        else {
            // �������������� ����������� �������� ������
        }
        array.push_back(floatValue);
        i++;
        if (i > 1024) {
            //�������� ������, ��� ������ ������� �������
        }
    }
    fin.close();

    //if (array.size() < d) {
    //    //�������� ������, ��� �������� ������� �� ������� �������
    //}
    //if (b < 0) {
    //    //�������� ������, ��� �������� ������� �� ������� �������
    //}

    float sum = 0;
    float product = 1;
    i = 0;
    while (i < array.size()) {
        double dSum = sum + array[i];
        if (dSum <= std::numeric_limits<float>::max() && dSum >= -std::numeric_limits<float>::max()) {
            sum = static_cast<float>(dSum);
        }
        else {
            // �������������� ����������� �������� ������
        }
        if (b <= i && i <= d) {
            long double dProd = product * array[i];
            if (dProd <= std::numeric_limits<float>::max() && dProd >= -std::numeric_limits<float>::max()) {
                product = static_cast<float>(dProd);
            }
            else {
                // �������������� ����������� �������� ������
            }
        }
        i++;
    }
    return std::make_pair(sum, product);
}