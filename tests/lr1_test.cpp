#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <tuple>

using namespace std;

// Подробнее https://google.github.io/googletest/reference/testing.html

string FILE_NAME = "test.txt";
ifstream fin(FILE_NAME);

// Тестовый класс
class CountAndSumTestOF : public ::testing::Test {
protected:
    void SetUp() override {
        string inp;
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
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override {
    }

    // Объявляем переменные, которые будут использоваться в тестах
    int b;
    int d;

    float assumeSum, sum;
    float assumeProd, prod;
    string assumeErr, err;

    
};

class CountAndSumTestCF : public::CountAndSumTestOF {
protected:
    void TearDown() override {
        fin.close();
    }
};

bool isEqualsActualAndAssumption(float actual, float assumption) {
        return abs(actual - assumption) < 0.000001;
    }

// Пример теста1
TEST_F(CountAndSumTestOF, CTest1) {
    tie(sum, prod, err) = sumAndProd(fin, b, d);

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, assumeProd));
    EXPECT_EQ(err, assumeErr);
}

TEST_F(CountAndSumTestCF, CTest2) {

    tie(sum, prod, err) = sumAndProd(fin, b, d);

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, assumeProd));
    EXPECT_EQ(err, assumeErr);
}


