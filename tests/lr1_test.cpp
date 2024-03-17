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

struct MyTest {
    int b;
    int d;
    float assumeSum;
    float assumeProd;
    string assumeErr;
};

MyTest parseTest(ifstream& fin) {
    MyTest result;
    string inp;
    fin >> inp;
    string delimiter = ";";

    int fitstDelimiterPosition = inp.find(delimiter);
    string b_string = inp.substr(0, fitstDelimiterPosition);
    result.b = stoi(b_string);

    string d_string = inp.substr(fitstDelimiterPosition + 1, inp.size());
    result.d = stoi(d_string);

    fin >> inp;
    fitstDelimiterPosition = inp.find(delimiter);
    int secondDelimiterPosition = inp.rfind(delimiter);

    string assumeSumString = inp.substr(0, fitstDelimiterPosition);
    result.assumeSum = stof(assumeSumString);;


    string assumeProdString = inp.substr(fitstDelimiterPosition + 1, secondDelimiterPosition);
    result.assumeProd = stof(assumeProdString);

    result.assumeErr = inp.substr(secondDelimiterPosition + 1, inp.size());

    return result;
}

class CountAndSumTestOF : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    float sum;
    float prod;
    string err;

 };

bool isEqualsActualAndAssumption(double actual, float assumption) {
        return abs(actual - assumption) < 0.000001;
    }

// Пример теста1
TEST_F(CountAndSumTestOF, CTest1) {
    ifstream fin("test1.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log1.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest2) {
    ifstream fin("test2.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log2.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest3) {
    ifstream fin("test3.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log3.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest4) {
    ifstream fin("test4.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log4.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest5) {
    ifstream fin("test5.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log5.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest6) {
    ifstream fin("test6.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log6.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest7) {
    ifstream fin("test7.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log7.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest8) {
    ifstream fin("test8.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log8.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}


TEST_F(CountAndSumTestOF, CTest9) {
    ifstream fin("test9.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log9.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}


TEST_F(CountAndSumTestOF, CTest10) {
    ifstream fin("test10.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log10.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest11) {
    ifstream fin("test11.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log11.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest12) {
    ifstream fin("test12.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log12.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest13) {
    ifstream fin("test13.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log13.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest14) {
    ifstream fin("test14.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log14.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest15) {
    ifstream fin("test15.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log15.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest16) {
    ifstream fin("test16.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log16.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest17) {
    ifstream fin("test17.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log17.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest18) {
    ifstream fin("test18.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log18.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest19) {
    ifstream fin("test19.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log19.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest20) {
    ifstream fin("test20.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log20.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest21) {
    ifstream fin("test21.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log21.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest22) {
    ifstream fin("test22.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log22.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}

TEST_F(CountAndSumTestOF, CTest23) {
    ifstream fin("test23.txt");
    MyTest test = parseTest(fin);
    tie(sum, prod, err) = sumAndProd(fin, test.b, test.d, "log23.txt");
    fin.close();

    EXPECT_TRUE(isEqualsActualAndAssumption(sum, test.assumeSum));
    EXPECT_TRUE(isEqualsActualAndAssumption(prod, test.assumeProd));
    EXPECT_EQ(err, test.assumeErr);
}