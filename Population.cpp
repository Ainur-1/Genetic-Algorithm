#include "Population.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// ����� �� ������ ���������� ������ ������ Population

// �����������
Population::Population() {
    // ������������� ���������� ����������
    srand(time(NULL));
}

// ����������
Population::~Population() {
    // ����� ����� ���� ����������� ��� ��� ������������ ��������
}

// ����� ������������� ��������� ���������
void Population::initialize() {
    // ���������� ������������� ��������� ���������
}

// ����� ��� ������� ������������� ���������
void Population::evolve(int maxGenerations) {
    // ���������� ������������� ���������
    // ������� ��������, ������ �����������������, ����� � �������� ����� ���������
}

// ����� ������� ���������
void printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> new_popul) {

    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

    for (int i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";

        for (int j = 0; j < 4; j++) {
            printFormattedNumber(new_popul[i][j]);
        }

        std::cout << std::endl;
    }

}

// ����� ����� � ������� � ���������
void printFormattedNumber(int num) {
    if (num == 100)
        std::cout << num << " ";
    else if (num < 10)
        std::cout << "  " << num << " ";
    else if (num >= 10 && num < 100)
        std::cout << " " << num << " ";
}