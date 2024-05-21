// process.cpp
#include "processing.h"

#include <iostream>
#include <vector>
#include <string>

// ‘ункци€ дл€ вычислени€ среднего значени€ вектора чисел
double average(const std::vector<double>& v) {
    if (v.empty()) return 0.0; // ƒл€ пустого вектора среднее значение равно 0
    double sum = 0.0;
    for (double num : v) {
        sum += num;
    }
    return sum / v.size();
}

int main() {
    // »нициализаци€ данных о скорости ветра дл€ каждого мес€ца (пустые данные)
    std::vector<std::vector<double>> wind_speeds_by_month(12);

    // ¬вод данных о скорости ветра дл€ каждого мес€ца (пользовательский ввод)
    for (int i = 0; i < 12; ++i) {
        std::cout << "¬ведите данные о скорости ветра дл€ " << i + 1 << "-го мес€ца: ";
        double speed;
        while (std::cin >> speed) {
            wind_speeds_by_month[i].push_back(speed);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int month;
    std::cout << "¬ведите номер мес€ца (1 - €нварь, 2 - февраль и т.д.): ";
    std::cin >> month;

    if (month < 1 || month > 12) {
        std::cout << "ќшибка: введите номер мес€ца от 1 до 12.\n";
        return 1;  // ¬озвращаем ненулевой код, чтобы показать ошибку
    }

    // »ндекс мес€ца в массиве начинаетс€ с 0, поэтому вычитаем 1
    int month_index = month - 1;

    // ѕровер€ем, есть ли данные о скорости ветра дл€ выбранного мес€ца
    if (wind_speeds_by_month[month_index].empty()) {
        std::cout << "Ќет данных о скорости ветра дл€ выбранного мес€ца.\n";
        return 1;
    }

    // ¬ычисл€ем среднюю скорость ветра
    double avg_speed = average(wind_speeds_by_month[month_index]);

    std::cout << "—редн€€ скорость ветра в выбранном мес€це: " << avg_speed << " м/с\n";

    return 0;
}

