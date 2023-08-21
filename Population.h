#pragma once

#include <array>

class Population {
public:
    // ������������
    Population(); 
    Population(std::array<std::array<int, 4>, 10> population);

    void evolve(int maxGenerations); // ������ ������������� ���������
    void printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> population);


private:
    int generationNumber;
    std::array<std::array<int, 4>, 10> population_;
    void printFormattedNumber(int num);
};
