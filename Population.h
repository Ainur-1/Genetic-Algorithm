#pragma once

#include <array>

class Population {
public:
    Population(); // �����������
    ~Population(); // ����������

    void initialize(); // ������������� ��������� ���������
    void evolve(int maxGenerations); // ������ ������������� ���������

    void printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> new_popul);


private:
    int Generation_Number;
    void printFormattedNumber(int num);
};
