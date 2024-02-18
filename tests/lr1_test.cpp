#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

// Подробнее https://google.github.io/googletest/reference/testing.html

// Тестовый класс
class CountAndSumTest : public ::testing::Test {
protected:
    // Здесь вы можете добавить дополнительные настройки для тестов
    // в функции SetUp()
    void SetUp() override {
        // Например, инициализация данных
        arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        b = 2;
        d = 5;
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override {
        // Например, очистка данных
        arr.clear();
    }

    // Объявляем переменные, которые будут использоваться в тестах
    std::vector<float> arr;
    std::pair<float, float> result;
    int b;
    int d;
};

// Пример теста1
TEST_F(CountAndSumTest, CTest1) {
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(arr, b, d);

// Проверяем ожидаемые результаты
    EXPECT_EQ(result.first, 55);
    EXPECT_EQ(result.second, 360);
}

// Пример теста 2
TEST_F(CountAndSumTest, CTest2) {
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(arr, b, d);

// Проверяем ожидаемые результаты
    EXPECT_NE(result.first, 56);
    EXPECT_NE   (result.second, 100);
}

// Пример теста3
TEST(CountAndSumTest1, CTest3) {
    // Объявляем переменные, которые будут использоваться в тесте
    std::vector<float> arr;
    std::pair<float, float> result;
    int b = 2, d = 8;
    // Инициализация данных
    arr = { 1, 23, 34, 5, 34, 53, 34, 24, 5, 23, 34 };
// Вызываем функцию countAndSum с тестовыми данными
    result = prodAndSum(arr, b, d);

// Проверяем ожидаемые результаты
    EXPECT_EQ(result.first, 270);
    EXPECT_EQ(result.second, 1249867200);
}