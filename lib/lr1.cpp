#include "lr1.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

pair<float, float> sumAndProd(ifstream &fin, int b, int d) {
    string s;
    int i = 0;
    float sum = 0;
    float product = 1;
    while (fin >> s) {
        if (s == "EOTEST") {
            return make_pair(sum, product);
        }
        float floatValue;
        double doubleValue = stof(s);
        if (doubleValue <= std::numeric_limits<float>::max() && doubleValue >= -std::numeric_limits<float>::max()) {
            floatValue = static_cast<float>(doubleValue);
        }
        else {
            // �������������� ����������� �������� ������
        }
        double dSum = sum + floatValue;
        if (dSum <= std::numeric_limits<float>::max() && dSum >= -std::numeric_limits<float>::max()) {
            sum = static_cast<float>(dSum);
        }
        else {
            // �������������� ����������� �������� ������
        }
        if (b <= i && i <= d) {
            long double dProd = product * floatValue;
            if (dProd <= std::numeric_limits<float>::max() && dProd >= -std::numeric_limits<float>::max()) {
                product = static_cast<float>(dProd);
            }
            else {
                // �������������� ����������� �������� ������
            }
        }
        i++;
        if (i > 1024) {
            //�������� ������, ��� ������ ������� �������
        }
    }
    return make_pair(sum, product);
}