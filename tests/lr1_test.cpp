#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>

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
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override {
    }

    // Объявляем переменные, которые будут использоваться в тестах
    std::pair<float, float> result;
    int b;
    int d;

    float assumeSum;
    float assumeProd;

    
};

class CountAndSumTestCF : public ::testing::Test {
protected:
    void SetUp() override {
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
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override {
        fin.close();
    }

    // Объявляем переменные, которые будут использоваться в тестах
    std::pair<float, float> result;
    int b;
    int d;

    float assumeSum;
    float assumeProd;


};

bool isEqualsActualAndAssumption(float actual, float assumption) {
        return abs(actual - assumption) < 0.000001;
    }

// Пример теста1
TEST_F(CountAndSumTestOF, CTest1) {
// Вызываем функцию countAndSum с тестовыми данными
    result = sumAndProd(fin, b, d);

// Проверяем ожидаемые результаты
    EXPECT_TRUE(isEqualsActualAndAssumption(result.first, assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(result.second, assumeProd));
}

TEST_F(CountAndSumTestCF, CTest2) {
    // Вызываем функцию countAndSum с тестовыми данными
    result = sumAndProd(fin, b, d);

    // Проверяем ожидаемые результаты
    EXPECT_TRUE(isEqualsActualAndAssumption(result.first, assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(result.second, assumeProd));
}


