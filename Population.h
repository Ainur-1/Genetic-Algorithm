#pragma once

#include <array>

class Population {
public:
    // ������������
    Population(); 
    Population(std::array<std::array<int, 4>, 10> population);

    const std::array<std::array<int, 4>, 10>& getPopulation() const;

    void printPopulation();
    void evolve(int maxGenerations); // ������ ������������� ���������

private:
    int generationNumber;
    std::array<std::array<int, 4>, 10> population_;
    void printFormattedNumber(int num);
};
