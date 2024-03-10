#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

// Подробнее https://google.github.io/googletest/reference/testing.html

// Тестовый класс
class CountAndSumTest : public ::testing::Test {
protected:
    // Здесь вы можете добавить дополнительные настройки для тестов
    // в функции SetUp()
    void SetUp() override {
        // Например, инициализация данных
        filename = "mainInput.txt";
        b = 2;
        d = 5;
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override {
        // Например, очистка данных
        filename.clear();
    }

    // Объявляем переменные, которые будут использоваться в тестах
    std::string filename;
    std::pair<float, float> result;
    int b;
    int d;

    
};

bool isEqualsActualAndAssumption(float actual, float assumption) {
        return abs(actual - assumption) < 0.000001;
    }

// Пример теста1
TEST_F(CountAndSumTest, CTest1) {
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(filename, b, d);

// Проверяем ожидаемые результаты
    EXPECT_TRUE(isEqualsActualAndAssumption(result.first, 46.111114));
    EXPECT_TRUE(isEqualsActualAndAssumption(result.second, 404.070098));
}

// Пример теста 2
TEST_F(CountAndSumTest, CTest2) {
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(filename, b, d);

// Проверяем ожидаемые результаты
    EXPECT_FALSE(isEqualsActualAndAssumption(result.first, 56));
    EXPECT_FALSE(isEqualsActualAndAssumption(result.second, 100));
}

// Пример теста3
TEST(CountAndSumTest1, CTest3) {
    // Объявляем переменные, которые будут использоваться в тесте
    std::string filename;
    std::pair<float, float> result;
    int b = 2, d = 8;
    // Инициализация данных
    filename = "mainInput.txt";
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(filename, b, d);

// Проверяем ожидаемые результаты
    EXPECT_TRUE(isEqualsActualAndAssumption(result.first, 46.111114));
    EXPECT_TRUE(isEqualsActualAndAssumption(result.second, 213327.984375));
}