// process.cpp
#include "processing.h"

#include <iostream>
#include <vector>
#include <string>

// ������� ��� ���������� �������� �������� ������� �����
double average(const std::vector<double>& v) {
    if (v.empty()) return 0.0; // ��� ������� ������� ������� �������� ����� 0
    double sum = 0.0;
    for (double num : v) {
        sum += num;
    }
    return sum / v.size();
}

int main() {
    // ������������� ������ � �������� ����� ��� ������� ������ (������ ������)
    std::vector<std::vector<double>> wind_speeds_by_month(12);

    // ���� ������ � �������� ����� ��� ������� ������ (���������������� ����)
    for (int i = 0; i < 12; ++i) {
        std::cout << "������� ������ � �������� ����� ��� " << i + 1 << "-�� ������: ";
        double speed;
        while (std::cin >> speed) {
            wind_speeds_by_month[i].push_back(speed);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int month;
    std::cout << "������� ����� ������ (1 - ������, 2 - ������� � �.�.): ";
    std::cin >> month;

    if (month < 1 || month > 12) {
        std::cout << "������: ������� ����� ������ �� 1 �� 12.\n";
        return 1;  // ���������� ��������� ���, ����� �������� ������
    }

    // ������ ������ � ������� ���������� � 0, ������� �������� 1
    int month_index = month - 1;

    // ���������, ���� �� ������ � �������� ����� ��� ���������� ������
    if (wind_speeds_by_month[month_index].empty()) {
        std::cout << "��� ������ � �������� ����� ��� ���������� ������.\n";
        return 1;
    }

    // ��������� ������� �������� �����
    double avg_speed = average(wind_speeds_by_month[month_index]);

    std::cout << "������� �������� ����� � ��������� ������: " << avg_speed << " �/�\n";

    return 0;
}

