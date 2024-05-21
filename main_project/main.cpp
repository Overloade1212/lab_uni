#include <iostream>
#include <vector>
#include <algorithm>

// ��������� ��� �������� ���������� � �����
struct Wind {
    int day;
    int month;
    std::string direction;
    double speed;
};

// ������� ��� �������� ����������� �����
bool isDirectionAllowed(const std::string& direction) {
    return direction == "West" || direction == "NorthWest" || direction == "North";
}

// ������� ��� ���������� ����� �� �����������
std::vector<Wind> filterByDirection(const std::vector<Wind>& winds) {
    std::vector<Wind> filtered;
    for (const auto& wind : winds) {
        if (isDirectionAllowed(wind.direction)) {
            filtered.push_back(wind);
        }
    }
    return filtered;
}

// ������� ��� ���������� ����� �� ��������
std::vector<Wind> filterBySpeed(const std::vector<Wind>& winds, double minSpeed) {
    std::vector<Wind> filtered;
    for (const auto& wind : winds) {
        if (wind.speed > minSpeed) {
            filtered.push_back(wind);
        }
    }
    return filtered;
}

// ������� ��� ���������� �� �������� �������� �����
bool sortBySpeedDescending(const Wind& a, const Wind& b) {
    return a.speed > b.speed;
}

// ������� ��� ���������� �� ����������� ����������� �����
bool sortByDirectionAscending(const Wind& a, const Wind& b) {
    if (a.direction != b.direction) {
        return a.direction < b.direction;
    }
    else if (a.month != b.month) {
        return a.month < b.month;
    }
    else {
        return a.day < b.day;
    }
}

// ������� ��� ������ �����
void printWind(const Wind& wind) {
    std::cout << "Day: " << wind.day << ", Month: " << wind.month
        << ", Direction: " << wind.direction << ", Speed: " << wind.speed << std::endl;
}

int main() {
    // ������ ������ � �����
    std::vector<Wind> winds = {
        {1, 1, "North", 3.5},
        {2, 2, "NorthWest", 4.2},
        {3, 3, "West", 6.1},
        {4, 4, "South", 7.3},
        {5, 5, "NorthWest", 5.8}
    };

    // ���������� � ����������
    auto filteredByDirection = filterByDirection(winds);
    auto filteredBySpeed = filterBySpeed(winds, 5.0);
    std::sort(filteredBySpeed.begin(), filteredBySpeed.end(), sortBySpeedDescending);
    std::sort(filteredByDirection.begin(), filteredByDirection.end(), sortByDirectionAscending);

    // ����� �����������
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
