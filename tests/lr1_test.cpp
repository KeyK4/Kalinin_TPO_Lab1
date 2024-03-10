#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <string>

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

float roundToPresicion(float num) {
        return round(num * 1000000) / 1000000;
    }

// Пример теста1
TEST_F(CountAndSumTest, CTest1) {
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(filename, b, d);

// Проверяем ожидаемые результаты
    EXPECT_EQ(roundToPresicion(result.first), 46.1111145);
    EXPECT_EQ(roundToPresicion(result.second), 404.0700989);
}

// Пример теста 2
TEST_F(CountAndSumTest, CTest2) {
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(filename, b, d);

// Проверяем ожидаемые результаты
    EXPECT_NE(roundToPresicion(result.first), 56);
    EXPECT_NE(roundToPresicion(result.second), 100);
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
    EXPECT_EQ(roundToPresicion(result.first), 46.1111145);
    EXPECT_EQ(roundToPresicion(result.second), 213327.9843750);
}