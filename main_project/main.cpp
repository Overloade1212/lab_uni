#include <iostream>
#include <vector>
#include <algorithm>

// Структура для хранения информации о ветре
struct Wind {
    int day;
    int month;
    std::string direction;
    double speed;
};

// Функция для проверки направления ветра
bool isDirectionAllowed(const std::string& direction) {
    return direction == "West" || direction == "NorthWest" || direction == "North";
}

// Функция для фильтрации ветра по направлению
std::vector<Wind> filterByDirection(const std::vector<Wind>& winds) {
    std::vector<Wind> filtered;
    for (const auto& wind : winds) {
        if (isDirectionAllowed(wind.direction)) {
            filtered.push_back(wind);
        }
    }
    return filtered;
}

// Функция для фильтрации ветра по скорости
std::vector<Wind> filterBySpeed(const std::vector<Wind>& winds, double minSpeed) {
    std::vector<Wind> filtered;
    for (const auto& wind : winds) {
        if (wind.speed > minSpeed) {
            filtered.push_back(wind);
        }
    }
    return filtered;
}

// Функция для шейкерной сортировки по убыванию скорости ветра
void cocktailSortBySpeedDescending(std::vector<Wind>& winds) {
    bool swapped = true;
    int start = 0;
    int end = winds.size() - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (winds[i].speed < winds[i + 1].speed) {
                std::swap(winds[i], winds[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (winds[i].speed < winds[i + 1].speed) {
                std::swap(winds[i], winds[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

// Функция для сортировки слиянием по возрастанию направления ветра
void merge(std::vector<Wind>& winds, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Wind> L(n1);
    std::vector<Wind> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = winds[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = winds[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].direction < R[j].direction ||
            (L[i].direction == R[j].direction && L[i].month < R[j].month) ||
            (L[i].direction == R[j].direction && L[i].month == R[j].month && L[i].day < R[j].day)) {
            winds[k] = L[i];
            ++i;
        }
        else {
            winds[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        winds[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        winds[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSortByDirectionAscending(std::vector<Wind>& winds, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortByDirectionAscending(winds, left, mid);
        mergeSortByDirectionAscending(winds, mid + 1, right);

        merge(winds, left, mid, right);
    }
}

// Функция для вывода ветра
void printWind(const Wind& wind) {
    std::cout << "Day: " << wind.day << ", Month: " << wind.month
        << ", Direction: " << wind.direction << ", Speed: " << wind.speed << std::endl;
}

int main() {
    std::vector<Wind> winds = {
        {1, 1, "North", 3.5},
        {2, 2, "NorthWest", 4.2},
        {3, 3, "West", 6.1},
        {4, 4, "South", 7.3},
        {5, 5, "NorthWest", 5.8}
    };

    // Фильтрация и сортировка
    auto filteredByDirection = filterByDirection(winds);
    auto filteredBySpeed = filterBySpeed(winds, 5.0);

    cocktailSortBySpeedDescending(filteredBySpeed);
    mergeSortByDirectionAscending(filteredByDirection, 0, filteredByDirection.size() - 1);

    // Вывод результатов
    std::cout << "Days with wind blowing in West, NorthWest, or North direction:\n";
    for (const auto& wind : filteredByDirection) {
        printWind(wind);
    }

    std::cout << "\nDays with wind speed greater than 5 m/s:\n";
    for (const auto& wind : filteredBySpeed) {
        printWind(wind);
    }

    return 0;
}
